var Stack = function() {
  this.count = 0;
  this.storage = {};

  // Add a value onto the end of the stack
  this.push = function(value) {
    this.storage[this.count] = value;
    this.count++;
  };

  // Removes and returns the value at the end of the stack
  this.pop = function() {
    if (this.count === 0) {
      return undefined;
    }
    this.count--;
    var result = this.storage[this.count];
    delete this.storage[this.count];
    return result;
  };

  // Returns the value at the end of the stack
  this.peek = function() {
    return this.storage[this.count - 1];
  };
};

// Return the size of the stack
Stack.prototype.size = function() {
  return this.count;
};

var myStack = new Stack();

for (let i = 0; i < 5; i++) {
  myStack.push(Math.floor(Math.random() * 100 + 1));
}

myStack.push("sang");
myStack.push({ name: "le quang sang" });
myStack.push(["an", 21]);
myStack.pop();
console.log(myStack);

var myArray = [];
for (let i = 0; i < 5; i++) {
  myArray.push(Math.floor(Math.random() * 100 + 1));
}

Array.prototype.insert = function(index, item) {
    this.splice(index, 0, item);
}
myArray.push('sang')
myArray.insert(0, 'TranAn')
myArray.pop()
myArray.push('sang')
myArray.shift(); // delete first
console.log(myArray.includes('sang', 0));
console.log(myArray.unshift('minh'));
console.log(myArray.slice(2, 4));

console.log(myArray);
