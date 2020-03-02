const l = [3, 1, 2, 3, 4, 5];
const k = 3;
function removeKFromList(l, k) {
  console.log(k);
  return l.filter(e => e !== k);
}
console.log(removeKFromList(l, k));
