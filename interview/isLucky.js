function isLucky(n) {
  n = n.toString().split("");
  s1 = 0;
  s2 = 0;
  for (let i = 0; i < n.length / 2; i++) {
    s1 += parseInt(n[i]);
    s2 += parseInt(n[i + n.length / 2]);
  }
  if (s1 === s2) return true;
  return false;
}
console.log(isLucky(239017));
