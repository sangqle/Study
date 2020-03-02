function addBorder(picture) {
  const width = Math.max(...picture.map(el => el.length));
  return [
    "*".repeat(width),
    ...picture.map(line => `*${line}*`),
    "*".repeat(width)
  ];
}

console.log(addBorder(["abc", "ded"]));
