const fs = require("fs");

let readFilePr = fileName =>
  new Promise((resolve, reject) => {
    fs.readFile(fileName, "utf8", (err, data) => {
      if (err) return reject(err);
      return resolve(data);
    });
  });

readFilePr("../test.txt").then(
  data => {
    console.log(data);
    console.log("The End");
  },
  err => {
    console.log(err.toString());
  }
);
