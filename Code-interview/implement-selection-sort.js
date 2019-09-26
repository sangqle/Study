function swap(i1, i2, array) {
  const temp = array[i1];
  array[i1] = array[i2];
  array[i2] = temp;
}

function selectionSort(array) {
  for (let i = 0; i < array.length; i++) {
    let iMin = i;
    let vMin = array[i];
    for (let j = i + 1; j < array.length; j++) {
      if (array[j] < vMin) {
        vMin = array[j];
        iMin = j;
      }
    }
    swap(iMin, i, array);
  }
  return array;
}

// test array:
const arrayTest = [
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
  92,
  324
];
console.log(selectionSort(arrayTest));
