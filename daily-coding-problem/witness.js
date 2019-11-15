/*
 * Input: [3, 6, 3, 4, 1]
 * Output: 3
 #
 #
 # #
####
####
#####
36341   x
 */

const witnesses = heights => {
  let count = 1;
  let max = heights[heights.length - 1];
  for (let i = heights.length - 1; i >= 0; i--) {
    if (heights[i] > max) {
      max = heights[i];
      count++;
    }
  }
  return count;
};

console.log(witnesses([3, 6, 2, 4, 5, 3, 4, 1]));
