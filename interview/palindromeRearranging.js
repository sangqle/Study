function palindromeRearranging(inputString) {
  let odd = 0;
  let even = 0;
  const setC = new Set(inputString);
  setC.forEach(char => {
    let count = (inputString.match(new RegExp(char, "g")) || []).length;
    if (count % 2 === 0) even++;
    else {
      odd++;
    }
  });
  if (even >= 0) {
    return odd <= 1 ? true : false;
  } else {
    return odd == 1;
  }
}

a = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaabbbccccaaaaaaaaaaaaa";
console.log(palindromeRearranging(a));
