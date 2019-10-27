console.log("hello react");

var template = React.createElement(
  "p",
  {
    id: "someid"
  },
  "Hello React.js"
);
var appRoot = document.getElementById("app");

ReactDom.render(template, appRoot);
