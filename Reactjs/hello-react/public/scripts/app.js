"use strict";

console.log("app.js is running");
var app = {
  title: "Some title",
  subtitle: "this is subtitle",
  option: ["one", "two"]
};
var template = React.createElement(
  "div",
  null,
  React.createElement(
    "h1",
    null,
    app.title
  ),
  app.subtitle && React.createElement(
    "p",
    null,
    app.subtitle
  ),
  React.createElement(
    "p",
    null,
    app.option.length > 0 ? "Here is your option" : "No option"
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
  name: "Sang",
  age: 25,
  location: "CanTho"
};

function getLocation(location) {
  if (location) {
    return React.createElement(
      "p",
      null,
      "Location: ",
      location
    );
  }
}
var templateTwo = React.createElement(
  "div",
  null,
  React.createElement(
    "h1",
    null,
    user.name ? user.name : "Anonymous"
  ),
  user.age && user.age >= 25 && React.createElement(
    "p",
    null,
    "Age: ",
    user.age
  ),
  getLocation(user.location)
);
var appRoot = document.getElementById("app");

ReactDOM.render(template, appRoot);
