/* 
Given a list of numbers and a number k,
return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 */
const arrTest = [10, 15, 3, 4, 6, 12];
let k = 17;
let restK = k;
const results = [];

function check(arr, k) {
  for (let i = 0; i < arr.length; i++) {
    const ans = arr.indexOf(k - arr[i]);
    if (ans != -1) {
      return [arr[i], arr[ans]];
    }
  }
  return [];
}

function main(arr, k) {
  for (let i = 0; i < arr.length; i++) {
    let rs = check(arr, k - arr[i]);
    if (rs.length == 2) {
      rs.unshift(arr[i]);
      return rs;
    }
  }
}

console.log(main(arrTest, k));
