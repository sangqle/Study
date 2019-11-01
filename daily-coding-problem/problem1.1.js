/* 
Given a list of numbers and a number k,
return whether any two numbers from the list add up to k.

For example, given [10, 15, 3, 7] and k of 17, return true since 10 + 7 is 17.
 */
const arr = [10, 15, 3, 7, 2, 4, 14];
const k = 17;

const results = [];

function check(arr, k) {
  let arrClone = [...arr];
  for (let i = 0; i < arrClone.length; i++) {
    const ans = arrClone.indexOf(k - arrClone[i]);
    if (ans != -1) {
      results.push([arrClone[i], arrClone[ans]]);
      delete arrClone[i];
      delete arrClone[ans];
    }
  }
}
check(arr, k);

console.log(results);
