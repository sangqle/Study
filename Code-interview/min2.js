const arr = [1, 4, 52, 6, 0, 19];
const x = 51;

function minSubArr(arr, x) {
  let min = arr.length + 1;
  let left = 0;
  let right = 0;
  let sum = arr[0];
  while (left <= right) {
    if (sum <= x) {
      right++;
      if (right >= arr.length) {
        break;
      }
      sum += arr[right];
      console.log(sum);
    } else {
      length = right - left + 1;
      if (length < min) min = length;
      sum -= arr[left];
      left++;
    }
  }
  if (min === arr.length + 1) {
    console.log("not possible");
    return;
  }

  console.log(min);
}
minSubArr(arr, x);
