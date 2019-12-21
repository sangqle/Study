const { ipcRenderer } = require("electron");
const editor = document.getElementById("editor");
ipcRenderer.on("new-file", (event, args) => {
  if (args) {
    const div = document.createElement("div");
    div.id = "text-editor";
    div.innerHTML = `
    <textarea name="editor" id="textArea" cols="65" rows="35"></textarea>
  `;
    document.getElementById("editor").appendChild(div);
    // addEventListenerOnTextEditor();
  }
});

// function addEventListenerOnTextEditor() {
//   const textArea = document.getElementById("textArea");
//   textArea.addEventListener("keypress", event => {});
// }

ipcRenderer.on("save-file", (event, args) => {
  if (args) {
    const textInEditor = document.getElementById("text-editor");
    const textArea = document.getElementById("textArea");

    console.log(textInEditor.value);
    ipcRenderer.send("file-saved", { text: textArea.value });
  }
});
