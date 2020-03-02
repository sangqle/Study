image = [
  [false, true, true, false],
  [true, true, false, true],
  [false, false, true, false]
];

function plusAround(image, x, y) {
  for (let i = x; i < x + 3; i++) {
    for (let j = y; j < y + 3; j++) {
      if (i === x && j === y) {
      } else {
        image[i][j] += 1;
      }
    }
  }
}

function minesweeper(image) {
  let matrix = Array(image.length + 2)
    .fill()
    .map(() => Array(image[0].length + 2).fill(0));
  for (let i = 0; i < image.length; i++) {
    for (let j = 0; j < image[i].length; j++) {
      if (image[i][j] === true) {
        plusAround(matrix, i, j);
      }
    }
  }
  let rs = [];
  for (let i = 1; i < matrix.length - 1; i++) {
    let line = [];
    for (let j = 1; j < matrix[i].length - 1; j++) {
      line.push(matrix[i][j]);
    }
    rs.push(line);
  }
  return rs;
}

const array = minesweeper(image);

console.log(array);
