function sym() {
  arrs = [];
  for (arg of arguments) arrs.push(arg);
  function symDiff(arr1, arr2) {
    const result = [];
    arr1.forEach(function(item) {
      if (arr2.indexOf(item) < 0 && result.indexOf(item) < 0) result.push(item);
    });
    arr2.forEach(function(item) {
      if (arr1.indexOf(item) < 0 && result.indexOf(item) < 0) result.push(item);
    });
    return result;
  }
  return arrs.reduce(symDiff).sort();
}

console.log(
  sym([3, 3, 3, 2, 5], [2, 1, 5, 7], [3, 4, 6, 6], [1, 2, 3], [5, 3, 9, 8], [1])
);
