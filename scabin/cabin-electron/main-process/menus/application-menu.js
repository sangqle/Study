const { BrowserWindow, Menu, app, shell, dialog } = require("electron");
const electron = require("electron");
const { ipcMain } = require("electron");
const path = require("path");
const url = require("url");
const loadWorkSpace = require("../work-space/workspace");
const fs = require("fs");
const mainMenuTemplate = [
  {
    label: "File",
    submenu: [
      {
        label: "New File",
        accelerator: process.platform == "darwin" ? "Command+N" : "Ctrl+N",
        click: (item, focusedWindow) => {
          focusedWindow.webContents.send("new-file", "create");
        }
      },
      {
        label: "Open File",
        accelerator: process.platform == "darwin" ? "Command+O" : "Ctrl+O"
      },
      {
        label: "Save",
        accelerator: process.platform == "darwin" ? "Command+S" : "Ctrl+S",
        click(item, focusedWindow) {
          let i = 0;
          focusedWindow.webContents.send("save-file", "save");
        }
      },
      {
        label: "Save As..."
      },
      {
        label: "Quit",
        accelerator: process.platform == "darwin" ? "Command+Q" : "Ctrl+Q",
        click() {
          app.quit();
        }
      }
    ]
  },
  {
    label: "Edit"
  },
  {
    label: "Selection"
  },
  {
    label: "View"
  },
  {
    label: "Go"
  },
  {
    label: "Debug"
  },
  {
    label: "Termial"
  },
  {
    label: "Help"
  }
];

ipcMain.on("file-saved", (event, args) => {
  console.log(args);
  try {
    fs.writeFileSync("myfile.js", args.text, "utf-8");
    console.log("Saved");
  } catch (e) {
    console.log("Failed to save the file !");
  }
  event.returnValue = "pong";
});

if (process.env.NODE_ENV != "production") {
  mainMenuTemplate.push({
    label: "Developer Tool",
    submenu: [
      {
        label: "Toggle DevTools",
        accelerator: process.platform == "darwin" ? "Command+I" : "Ctrl+I",
        click(item, focusedWindow) {
          focusedWindow.toggleDevTools();
        }
      },
      {
        role: "reload"
      }
    ]
  });
}
function findReopenMenuItem() {
  const menu = Menu.getApplicationMenu();
  if (!menu) return;

  let reopenMenuItem;
  menu.items.forEach(item => {
    if (item.submenu) {
      item.submenu.items.forEach(item => {
        if (item.key === "reopenMenuItem") {
          reopenMenuItem = item;
        }
      });
    }
  });
  return reopenMenuItem;
}

app.on("ready", () => {
  const menu = Menu.buildFromTemplate(mainMenuTemplate);
  Menu.setApplicationMenu(menu);
});

app.on("browser-window-created", () => {
  let reopenMenuItem = findReopenMenuItem();
  if (reopenMenuItem) reopenMenuItem.enabled = false;
});

app.on("window-all-closed", () => {
  let reopenMenuItem = findReopenMenuItem();
  if (reopenMenuItem) reopenMenuItem.enabled = true;
});
