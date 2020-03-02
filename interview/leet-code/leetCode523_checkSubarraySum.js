var checkSubarraySum = function(nums, k) {
  let map = {};
  let sum = 0;
  map[0] = -1;
  for (let i = 0; i < nums.length; i++) {
    sum += nums[i];
    if (k !== 0) {
      sum = sum % k;
    }
    console.log(map);

    if (map[sum] !== undefined) {
      if (i - map[sum] > 1) {
        return true;
      }
    } else {
      map[sum] = i;
    }
  }
  return false;
};

const nums = [23, 3, 6, 2, 4],
  k = 6;
console.log(checkSubarraySum(nums, k));
// sum = 2;
// sum = 2;
map = { "0": -1, "5": 0, "2": 1, "2": 2, "4": 3, "2": 4 };
