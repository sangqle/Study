reverseInParentheses = str => {
  if (str.indexOf("(") === -1) return str;
  const reverse = str
    .split("(")
    .pop()
    .split(")")[0];

  //   console.log(reverse);
  str = str.replace(
    "(" + reverse + ")",
    reverse
      .split("")
      .reverse()
      .join("")
  );
  return reverseInParentheses(str);
};

str = "foo(bar(baz))blim";
console.log(reverseInParentheses(str));
