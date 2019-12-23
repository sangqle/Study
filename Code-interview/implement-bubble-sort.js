function swap(i1, i2, array) {
  const temp = array[i1];
  array[i1] = array[i2];
  array[i2] = temp;
}
function bubbleSort(arr) {
  // change code below this line
  let array = [...arr];
  for (let i = array.length - 1; i > 0; i--) {
    let check = true;
    for (let j = 0; j < i; j++) {
      if (array[i] < array[j]) {
        swap(i, j, array);
        check = false;
      }
    }
    if (check) {
      break;
    }
  }
  return array;
}

// test array:
console.log(
  bubbleSort([
    1,
    4,
    2,
    8,
    345,
    123,
    43,
    32,
    5643,
    63,
    123,
    43,
    2,
    55,
    1,
    234,
    92
  ])
);
