// const arr = [1, 2, 1, 2, 1];
// const k = 3;
// const arr = [-1, -1, 1];
// const k = 0;
// const arr = [-1, -1, 1];
// const k = 1;
// const arr = [100, 1, 2, 3, 4];
// const k = 6;
// const arr = [100, 1, 2, 3, 4];
// const k = 6;

function subarraySum(arr, k) {
  let left = 0;
  let right = 0;
  let maxCount = 0;
  let sum = arr[0];
  while (left <= right) {
    console.log(left, right);
    if (sum < k) {
      if (right < arr.length - 1) {
        right++;
        sum += arr[right];
      } else {
        sum -= arr[left];
        left++;
      }
    } else if (sum === k) {
      maxCount++;
      if (right < arr.length - 1) {
        sum -= arr[left];
        left++;
        right++;
        sum += arr[right];
      } else {
        sum -= arr[left];
        left++;
      }
    } else {
      if (right < arr.length - 1) {
        if (right == left) {
          sum -= arr[left];
          left++;
          right++;
          sum += arr[right];
        } else {
          sum -= arr[left];
          left++;
        }
      } else {
        sum -= arr[left];
        left++;
      }
    }
    // }
  }
  return maxCount;
}
console.log(subarraySum(arr, k));
