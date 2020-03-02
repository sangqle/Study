let s1 = "aabcc";
let s2 = "adcaa";

function commonCharacterCount(s1, s2) {
  let characters = s1.split("");
  sum = 0;
  while (characters.length) {
    char = characters.pop();
    if (s2.includes(char)) {
      sum++;
      s2 = s2.replace(char, "");
    }
  }
}

commonCharacterCount(s1, s2);
