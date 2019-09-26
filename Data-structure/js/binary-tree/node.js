function Node(val, data) {
  this.value = val;
  this.data = data;
  this.left = null;
  this.right = null;
}

Node.prototype.visit = function() {
  if (this.left != null) {
    this.left.visit();
  }
  let obj = {
    value: this.value,
    data: this.data
  };
  console.log(obj);
  if (this.right != null) {
    this.right.visit();
  }
};

Node.prototype.search = function(val) {
  if (this.value == val) {
    return this;
  } else if (val < this.value && this.left != null) {
    return this.left.search(val);
  } else if (val > this.value && this.right != null) {
    return this.right.search(val);
  }
  return null;
};

Node.prototype.addNode = function(n) {
  if (n.value < this.value) {
    if (this.left == null) {
      this.left = n;
    } else {
      this.left.addNode(n);
    }
  } else if (n.value > this.value) {
    if (this.right == null) {
      this.right = n;
    } else {
      this.right.addNode(n);
    }
  }
};

module.exports = {Node};