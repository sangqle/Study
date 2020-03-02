function pairwise(arr, arg) {
  const arrMark = [];
  let result = 0;
  for (let i = 0; i < arr.length; i++) {
    if (arrMark.includes(i)) continue;
    for (let j = i + 1; j < arr.length; j++) {
      if (!arrMark.includes(j) && arr[i] + arr[j] === arg) {
        result += i + j;
        arrMark.push(i);
        arrMark.push(j);
        break;
      }
    }
  }
  return result;
}

pairwise([1, 4, 2, 3, 0, 5], 7);
console.log(pairwise([1, 4, 2, 3, 0, 5], 7));
console.log(pairwise([1, 3, 2, 4], 4));
console.log(pairwise([1, 1, 1], 2));
console.log(pairwise([0, 0, 0, 0, 1, 1], 1));
console.log(pairwise([], 100));
