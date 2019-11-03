/* You are given a positive integer N which represents the number of steps in a staircase.
You can either climb 1 or 2 steps at a time.
Write a function that returns the number of unique ways to climb the stairs. */

/* 
print staircase(4)
# 5
print staircase(5)
# 8 
*/

const staircase = n => {
  const rs =
    (Math.pow(1.618034, n + 1) - Math.pow(-0.618034, n + 1)) / Math.sqrt(5);
  return Math.round(rs);
};

console.log(staircase(3));
console.log(staircase(4));
console.log(staircase(5));
