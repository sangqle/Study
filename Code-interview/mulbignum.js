const a = 9998;
const b = 19999;

const mulbignum = (a, b) => {
  const strA = a.toString().split("");
  const strB = b.toString().split("");

  const arrRq = [];
  const arrRowSum = new Array(strB.length + strA.length).fill(0);
  const arrRowResult = new Array(strB.length + strA.length).fill(0);

  for (let i = strB.length - 1; i >= 0; i--) {
    const arrRow = new Array(strB.length + strA.length).fill(0);
    for (let j = strA.length - 1; j >= 0; j--) {
      const result = parseInt(strB[i], 10) * parseInt(strA[j], 10);
      arrRow[i + j + 1] = result;
      arrRowSum[i + j + 1] += result;
    }
    arrRq.push(arrRow);
  }
  arrRq.push(arrRowSum);

  // divide the remainder by ten
  for (let i = arrRowSum.length - 1; i >= 0; i--) {
    if (arrRowSum[i] > 9) {
      arrRowSum[i - 1] += Math.floor(arrRowSum[i] / 10);
      arrRowResult[i] = arrRowSum[i] % 10;
    } else {
      arrRowResult[i] = arrRowSum[i];
    }
  }
  console.log(a * b);
  return arrRowResult.join("");
};

console.log(mulbignum(a, b));

