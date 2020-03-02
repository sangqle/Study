const arr = [1, 4, 45, 6, 0, 19];
const k = 51;
function maxSum(arr, k) {
  let left = 0;
  let right = 0;
  let maxCount = arr.length + 1;
  let sum = arr[0];
  while (left <= right && right < arr.length - 1) {
    if (sum < k) {
      right++;
      sum += arr[right];
    } else if (sum >= k) {
      if (right - left + 1 < maxCount) maxCount = right - left + 1;
      sum -= arr[left];
      left++;
    }
  }
  return maxCount === arr.length + 1 ? "imposible" : maxCount;
}
console.log(maxSum(arr, k));
