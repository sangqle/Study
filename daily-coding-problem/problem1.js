/* 
Given a list of numbers and a number k,
return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 */
const arr = [10, 15, 3, 7];
const k = 17;

function check(arr, k) {
  for (let i = 0; i < arr.length; i++) {
    const ans = arr.indexOf(k - arr[i]);
    if (ans != -1) {
      return [arr[i], arr[ans]];
    }
  }
}

console.log(check(arr, k));
