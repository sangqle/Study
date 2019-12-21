const path = require("path");
const url = require("url");

const loadWorkSpace = (item, focusedWindow) => {
  focusedWindow.loadURL(
    url.format({
      pathname: path.join(__dirname, "workspace.html"),
      protocol: "file:",
      slashes: true
    })
  );
};

module.exports = loadWorkSpace;
