const a = [1, 2, 3];
const b = a.reduce((acc, curv, i) => {
  console.log(`Acc ${i} ${acc}`);
  console.log(`Curv ${i} ${curv}`);

  return acc + curv;
}, 10);
console.log(b);
