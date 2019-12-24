const a = 9998;
const b = 19999;

const mulbignum = (a, b) => {
  const strA = a.toString().split("");
  const strB = b.toString().split("");

  const arrRq = [];
  const rowSum = new Array(strB.length + strA.length).fill(0);
  const rowResult = new Array(strB.length + strA.length).fill(0);

  for (let i = strB.length - 1; i >= 0; i--) {
    const row = new Array(strB.length + strA.length).fill(0);
    for (let j = strA.length - 1; j >= 0; j--) {
      const result = parseInt(strB[i], 10) * parseInt(strA[j], 10);
      row[i + j + 1] = result;
      rowSum[i + j + 1] += result;
    }
    arrRq.push(row);
  }
  arrRq.push(rowSum);

  // divide the remainder by ten
  for (let i = rowSum.length - 1; i >= 0; i--) {
    if (rowSum[i] > 9) {
      rowSum[i - 1] += Math.floor(rowSum[i] / 10);
      rowResult[i] = rowSum[i] % 10;
    } else {
      rowResult[i] = rowSum[i];
    }
  }
  console.log(a * b);
  return rowResult.join("");
};

console.log(mulbignum(a, b));
