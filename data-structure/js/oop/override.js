function Animal() {}
Animal.prototype.eat = function() {
  return "nom nom nom";
};
function Bird() {}

// Inherit all methods from Animal
Bird.prototype = Object.create(Animal.prototype);

// Bird.eat() overrides Animal.eat()
Bird.prototype.eat = function() {
  console.log("peck peck peck");
};

let duck = new Bird();

duck.eat();
