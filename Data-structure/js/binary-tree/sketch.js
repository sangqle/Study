var tree;

function setup() {
  tree = new Tree();
  for (let i = 0; i < 20; i++) {
    tree.addValue(i + 1, {
      value: Math.floor(Math.random() * 100 + 1),
      age: Math.floor(Math.random() * 100 + 1),
      name: "sang"
    });
  }
  tree.traverse();
  var result = tree.search(10);
  if (result) {
    console.log("Found ");
    console.log(result);
  } else {
    console.log("Not Found");
  }
  console.log(tree);
}

const { Node } = require("./node");
const { Tree } = require("./tree");
setup();
