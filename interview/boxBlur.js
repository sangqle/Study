let image = [
  [36, 0, 18, 9, 9, 45, 27],
  [27, 0, 54, 9, 0, 63, 90],
  [81, 63, 72, 45, 18, 27, 0],
  [0, 0, 9, 81, 27, 18, 45],
  [45, 45, 27, 27, 90, 81, 72],
  [45, 18, 9, 0, 9, 18, 45],
  [27, 81, 36, 63, 63, 72, 81]
];

function blur(image, x, y) {
  sum = 0;
  for (let i = x; i < x + 3; i++) {
    for (let j = y; j < y + 3; j++) {
      sum += image[i][j];
    }
  }
  return Math.floor(sum / 9);
}

function boxBlur(image) {
  let boxBlured = [];
  for (let i = 0; i <= image.length - 3; i++) {
    let row = [];
    for (let j = 0; j <= image[i].length - 3; j++) {
      const avg = blur(image, i, j);
      row.push(avg);
    }
    boxBlured.push(row);
  }
  return boxBlured;
}

const blurImage = boxBlur(image);
console.log(blurImage);
