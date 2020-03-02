a = [832, 998, 148, 570, 533, 561, 894, 147, 455, 279];
b = [832, 998, 148, 570, 533, 561, 455, 147, 894, 279];
function areSimilar(a, b) {
  sum = 0;
  for (i = 0; i < a.length; i++) {
    if (a[i] != b[i]) {
      sum++;
    }
  }
  a.sort();
  b.sort();
  console.log(a.toString());
  return a.toString() == b.toString() && sum < 3;
}
console.log(areSimilar(a, b));
