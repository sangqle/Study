const { Node } = require("./node");

let count = 1;
function Tree() {
  this.root = null;
}

Tree.prototype.traverse = function() {
  this.root.visit();
};

Tree.prototype.search = function(val) {
  return this.root.search(val);
};

Tree.prototype.addValue = function(val, data) {
  var n = new Node(val, data);
  if (this.root == null) {
    this.root = n;
  } else {
    this.root.addNode(n);
  }
};

module.exports = { Tree };
