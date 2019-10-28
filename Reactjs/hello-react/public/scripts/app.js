"use strict";

console.log("app.js is running");
var app = {
  title: "Some title",
  subtitle: "this is subtitle"
};
var template = React.createElement(
  "div",
  null,
  React.createElement(
    "h1",
    null,
    app.title
  ),
  React.createElement(
    "p",
    null,
    app.subtitle
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
var user = {
  userName: "Sang",
  userAge: 22,
  userLocation: "CanTho"
};
var userName = "Sang";
var userAge = 22;
var userLocation = "CanTho";

var templateTwo = React.createElement(
  "div",
  null,
  React.createElement(
    "h1",
    null,
    user.userName
  ),
  React.createElement(
    "p",
    null,
    "Age: ",
    user.userAge
  ),
  React.createElement(
    "p",
    null,
    "Location: ",
    user.userLocation
  )
);
var appRoot = document.getElementById("app");

ReactDOM.render(template, appRoot);
