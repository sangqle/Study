const { BrowserWindow, Menu, app, shell, dialog } = require("electron");
const mainMenuTemplate = [
  {
    label: "File",
    submenu: [
      {
        label: "New Window"
      },
      {
        label: "Open File",
        accelerator: process.platform == "darwin" ? "Command+O" : "Ctrl+O"
      },
      {
        label: "Save",
        accelerator: process.platform == "darwin" ? "Command+S" : "Ctrl+S",
        click() {}
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
