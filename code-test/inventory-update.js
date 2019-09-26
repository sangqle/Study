function updateInventory(arr1, arr2) {
  // All inventory must be accounted for or you're fired!
  const inventory = Array.prototype.concat.apply([], arr1);
  for (let i = 0; i < arr2.length; i++) {
    const item = arr2[i][1];
    const quantity = arr2[i][0];
    const position = inventory.indexOf(item);
    if (position !== -1) {
      const row = Math.floor(position / 2);
      arr1[row][0] += quantity;
      continue;
    }
    arr1.push([quantity, item]);
  }
  arr1.sort((previous, next) => (previous[1] > [next[1]] ? 1 : -1));

  return arr1;
}

// Example inventory lists
updateInventory(
  [[21, "Bowling Ball"], [2, "Dirty Sock"], [1, "Hair Pin"], [5, "Microphone"]],
  [
    [2, "Hair Pin"],
    [3, "Half-Eaten Apple"],
    [67, "Bowling Ball"],
    [7, "Toothpaste"]
  ]
);
