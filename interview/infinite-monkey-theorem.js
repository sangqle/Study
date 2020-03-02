/*
 * @pi = 3141592653589793238462643383279
 * @favArr = ["314", "49", "901", "15926535897", "14", "9323", "8462643383279", "4", "793"]
 * Sample output: 3(314 15926535897 9323 8462643383279)

 */

const pi = "3141592653589793238462643383279";
const N = pi.length;
const favArr = [
  "314",
  "49",
  "901",
  "15926535897",
  "14",
  "9323",
  "8462643383279",
  "4",
  "793"
];
let rsArr = [];
const initMax = 9999;
let check = pos => {
  if (pos === N) return 0;
  let cur = "";
  let ans = initMax;
  for (let j = pos; j < pi.length; j++) {
    cur += pi[j];
    if (favArr.includes(cur)) {
      rsArr.push(cur);
      let other = check(j + 1);
      if (other !== -1) ans = Math.min(ans, 1 + other);
    }
  }
  return ans === initMax ? -1 : ans;
};

console.log(check(0));
console.log(rsArr);
