var fs = require("fs");

let Graph = {
  n: 0,
  m: 0,
  A: []
};

const init_graph = (G, n) => {
  G.n = n;
  for (let i = 0; i < G.n; i++) {
    let ar = [];
    for (let j = 0; j < G.n; j++) {
      ar.push(0);
    }
    G.A.push(ar);
  }
};

const add_adge = (G, x, y) => {
  G.A[x - 1][y - 1] = 1;
  G.A[y - 1][x - 1] = 1;
};

const main = () => {
  let content = fs.readFileSync("file.txt", "utf-8");

  content = content.split("");
  let arr = [];
  let el = [];
  for (let i = 0; i < content.length; i++) {
    if (content[i] != " ") {
      el.push(content[i]);
    }
  }
};
//main();
var readln = require("readline");

var cl = readln.createInterface(process.stdin, process.stdout);
var question = function(q) {
  return new Promise((res, rej) => {
    cl.question(q, answer => {
      res(answer);
    });
  });
};

(async function main() {
  var answer;
  while (answer != "yes") {
    answer = await question("Are you sure? ");
  }
  console.log("finally you are sure!");
})();
