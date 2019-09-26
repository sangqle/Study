var array = [1, 3, 0, 9, 5, 6, 2];

var aObj = [
  {
    name: "sang",
    age: 21
  },
  {
    name: "an",
    age: 20
  },
  {
    name: "tam",
    age: 19
  },
  {
    name: "thanh",
    age: 20
  },
  {
    name: "tai",
    age: 18
  }
];

//aObj = aObj.sort((a, b) => a.age > b.age ? -1 : a.age < b.age ? 1 : 0)

Array.prototype.sortOpt = function(opt) {
  var array = this.slice(); // make a new array with out reference old array
  try {
    for (let i = 0; i < array.length; i++) {
      for (let j = i + 1; j < array.length; j++) {
          if(array[i][opt] > array[j][opt]) {
              var temp = array[i];
              array[i] = array[j];
              array[j] = temp; 
          }
      }
    }
  } catch (error) {
      throw error;
  }
  return array;
};

//var arry = aObj.sortOpt("name");
console.log(aObj.sortOpt("age"));
console.log(aObj);
//console.log(aObj);
