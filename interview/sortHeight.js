/* function sortByHeight(a) {
  for (let i = 0; i < a.length; i++) {
    for (let j = i; j < a.length; j++) {
      if (a[j] === -1) continue;
      if (a[i] > a[j]) {
        temp = a[i];
        a[i] = a[j];
        a[j] = temp;
      }
    }
  }
  return a;
} */

function sortByHeight(a) {
  var s = a.filter(h => h > 0).sort((a, b) => a - b);
  console.log(s);
  return a.map(p => {
    if (p !== -1) {
      return s.shift();
    }

    return -1;
  });
}

a = [-1, 150, 190, 170, -1, -1, 160, 180];
console.log(sortByHeight(a));
