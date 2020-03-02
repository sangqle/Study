const arr = [1, 4, 52, 6, 0, 19];
const sum = arr.reduce((a, b) => a + b);
console.log(sum);
const x = sum - 1;
function minSubArr(arr, x) {
  let minLength = arr.length;
  let iMin = 0;
  for (let i = 0; i < arr.length; i++) {
    let sum = 0;
    let j = i;
    for (j; j < arr.length; j++) {
      sum += arr[j];
      if (sum > x) {
        length = arr.slice(i, j + 1).length;
        if (length < minLength) {
          minLength = length;
          iMin = i;
        }
        break;
      }
    }
    if (i === 0 && j === arr.length && sum <= x) {
      console.log("Not possible");
      return;
    }
  }
  console.log(minLength);
  console.log(arr.slice(iMin, iMin + minLength));
}
minSubArr(arr, x);
// console.log(arr.slice(1, 2));
