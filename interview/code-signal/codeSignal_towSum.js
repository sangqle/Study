function sumOfTwo(a, b, v) {
  let map = [];
  for (let i = 0; i < b.length; i++) {
    map[b[i]] = b[i];
  }
  for (let i = 0; i < a.length; i++) {
    console.log(map[v - a[i]]);
    if (a[i] && map[v - a[i]] === v - a[i]) return true;
  }
  return false;
}

const a = [3, 2, 3, 7, 5, 0, 3, 0, 4, 2];
b = [6, 8, 2, 9, 7, 10, 3, 8, 6, 0];
v = 2;
console.log(sumOfTwo(a, b, v));
