"use strict";

console.log("app.js is running");

var template = React.createElement(
  "div",
  null,
  React.createElement(
    "h1",
    null,
    "Indecision App"
  ),
  React.createElement(
    "p",
    null,
    "Hello this is p tag"
  ),
  React.createElement(
    "ol",
    null,
    React.createElement(
      "li",
      null,
      "The first"
    ),
    React.createElement(
      "li",
      null,
      "The second"
    )
  )
);
var appRoot = document.getElementById("app");

ReactDOM.render(template, appRoot);
