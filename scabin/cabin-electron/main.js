const { app, BrowserWindow, Menu, globalShortcut, shell } = require("electron");
const fs = require("fs");

const url = require("url");
const path = require("path");
const ipc = require("electron").ipcMain;
const glob = require("glob");

let mainWindow;

function initialize() {
  loadDemos();
  function createWindow() {
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
  }

  app.on("ready", createWindow);

  app.on("window-all-closed", () => {
    if (process.platform !== "darwin") {
      app.quit();
    }
  });

  app.on("activate", () => {
    if (mainWindow === null) {
      createWindow();
    }
  });
}

// Require each JS file in the main-process dir
function loadDemos() {
  const files = glob.sync(path.join(__dirname, "main-process/**/*.js"));
  files.forEach(file => {
    require(file);
  });
}

initialize();
