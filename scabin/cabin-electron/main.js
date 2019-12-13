const { app, BrowserWindow, Menu, globalShortcut, shell } = require("electron");
const fs = require("fs");

const url = require("url");
const path = require("path");
const ipc = require("electron").ipcMain;

let mainWindow;

function createWindow() {
  // Create the browser window.
  mainWindow = new BrowserWindow({
    title: "Scode",
    icon: "./assets/icons/png/icon.png",
    webPreferences: {
      nodeIntegration: true
    }
  });
  mainWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, "index.html"),
      protocol: "file:",
      slashes: true
    })
  );
  mainWindow.webContents.openDevTools();

  mainWindow.on("closed", () => {
    mainWindow = null;
  });

  /*   globalShortcut.register("f5", function() {
    console.log("f5 is pressed");
    mainWindow.reload();
  });
  globalShortcut.register("CommandOrControl+R", function() {
    console.log("CommandOrControl+R is pressed");
    mainWindow.reload();
  }); */
}

app.on("ready", createWindow);

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
        click() {
          const fullPath = app.getAppPath();
          shell.showItemInFolder(fullPath);
          mainWindow.webContents.send("save", {
            SAVED: "save file"
          });
          ipc.on("key-press", function(event, data) {
            console.log(data);
            try {
              fs.writeFileSync("myfile.js", data.txtCode, "utf-8");
            } catch (e) {
              alert("Failed to save the file !");
            }
          });
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

const mainMenu = Menu.buildFromTemplate(mainMenuTemplate);
Menu.setApplicationMenu(mainMenu);

// Quit when all windows are closed.
app.on("window-all-closed", () => {
  // to stay active until the user quits explicitly with Cmd + Q
  if (process.platform !== "darwin") {
    app.quit();
  }
});

app.on("activate", () => {
  // On macOS it's common to re-create a window in the app when the
  // dock icon is clicked and there are no other windows open.
  if (mainWindow === null) {
    createWindow();
  }
});

// In this file you can include the rest of your app's specific main process
// code. You can also put them in separate files and require them here.
