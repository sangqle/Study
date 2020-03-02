const array = [-6, -4, 1, 2, 3, 5];
function sortedSquaredArray(array) {
  let output = [];
  let left = 0;
  let right = array.length - 1;
  while (left <= right) {
    if (Math.abs(array[left]) > Math.abs(array[right])) {
      output.push(Math.pow(array[left], 2));
      left++;
    } else {
      output.push(Math.pow(array[right], 2));
      right--;
    }
  }
  return output.reverse();
}

const rs = sortedSquaredArray(array);
console.log(rs);
