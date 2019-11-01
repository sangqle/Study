/* 
Given an array of integers, 
return a new array such that each element at index i
of the new array is the product of all the numbers in the original array except the one at i.

For example, if our input was [1, 2, 3, 4, 5],
the expected output would be [120, 60, 40, 30, 24].
If our input was [3, 2, 1], the expected output would be [2, 3, 6].
 */

const arr1 = [1, 2, 3, 4, 5];
const arr2 = [3, 2, 1];
const product = arr => {
  const newArr = [];
  for (let i = 0; i < arr.length; i++) {
    let pro = 1;
    for (let j = 0; j < arr.length; j++) {
      if (i !== j) {
        pro *= arr[j];
      }
    }
    newArr.push(pro);
  }
  return newArr;
};

console.log(product(arr1));

console.log(product(arr2));
