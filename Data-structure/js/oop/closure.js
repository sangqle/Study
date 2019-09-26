function Bird() {
  let hatchedEgg = 10; // private property

  this.getHatchedEggCount = function() {
    // publicly available method that a bird object can use
    return hatchedEgg;
  };
}
let ducky = new Bird();
ducky.getHatchedEggCount(); // returns 10
