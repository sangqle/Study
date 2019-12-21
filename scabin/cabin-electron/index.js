const { ipcRenderer } = require("electron");
const editor = document.getElementById("editor");
ipcRenderer.on("new-file", (event, args) => {
  if (args) {
    const div = document.createElement("div");
    div.id = "text-editor";
    div.innerHTML = `
    <textarea name="editor" id="" cols="65" rows="35"></textarea>
  `;
    document.getElementById("editor").appendChild(div);
    addEventListenerOnTextEditor();
  }
});

function addEventListenerOnTextEditor() {
  let strText = "";
  const textEditor = document.getElementById("text-editor");
  textEditor.value = "";
  textEditor.addEventListener("keypress", event => {
    if (event) {
      strText = textEditor.value;
      console.log("output: ", strText);
    }
  });
}

ipcRenderer.on("save-file", (event, args) => {
  if (args) {
    const textInEditor = document.getElementById("text-editor");
    console.log(textInEditor.value);
    ipcRenderer.send("file-saved", { text: strText });
  }
});
