function Animal() {}
Animal.prototype = {
    constructor: Animal,
    describle: function() {
        console.log('My name is: '+ this.name);
    },
    eat: function() {
        console.log('mon mon mon');
    }
}

function Dog() {}
function Bird() {}

// inheritance
Dog.prototype = Object.create(Animal.prototype);
Bird.prototype = Object.create(Animal.prototype);
// constructor of Dog
Dog.prototype.constructor = Dog;
Bird.prototype.constructor = Bird;

// Add method for bird
Bird.prototype.fly = function() {
    console.log(`I'm flying!.`);
}
Dog.prototype.bark = function() {
    console.log('Woof!');
}

let animal = Object.create(Animal.prototype);
let dog = new Dog();

let duck = new Bird();

duck.eat();
duck.fly();
