const arr1 = [
  [88, "Bowling Ball"],
  [2, "Dirty Sock"],
  [3, "Hair Pin"],
  [5, "Microphone"],
  [3, "Half-Eaten Apple"],
  [7, "Toothpaste"]
];
arr1.sort((previous, next) => {
  if (previous > next) return 1;
  return -1;
});

const arr2 = [2, 3, 1, 0, 9, 8, 5, 6];
console.log(arr2.sort((a, b) => b - a));
