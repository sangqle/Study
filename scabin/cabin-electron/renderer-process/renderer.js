const ipc = require("electron").ipcRenderer;

let textCodeInput = "";
let textArea = document.getElementById("txtCode");

textArea.addEventListener("keypress", function(event) {
  textCodeInput = textArea.value;
  console.log("output: ", textCodeInput);
});
ipc.on("save", function(event, data) {
  if (data) {
    ipc.send("key-press", {
      txtCode: textCodeInput
    });
  }
});
