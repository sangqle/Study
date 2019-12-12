const { Menu, app } = require("electron");
const mainMenuTemplate = [
  {
    label: "File",
    submenu: [
      {
        label: "New Window"
      },
      {
        label: "Save"
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

module.exports = {
  mainMenu,
  mainMenuTemplate
};
