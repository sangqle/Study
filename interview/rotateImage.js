image = [
  [1, 2, 3],
  [4, 5, 6],
  [7, 8, 9]
];

function rotateImage(image) {
  const N = image.length;
  // Conver rows => columns
  for (let i = 0; i < N; i++) {
    for (let j = i; j < N; j++) {
      const temp = image[i][j];
      image[i][j] = image[j][i];
      image[j][i] = temp;
    }
  }
  // Swap row start to row end
  for (let i = 0; i < N; i++) {
    for (let j = 0; j < N / 2; j++) {
      const temp = image[i][j];
      image[i][j] = image[i][N - 1 - j];
      image[i][N - 1 - j] = temp;
    }
  }
  return image;
}

rotateImage2 = a => {
  return a.map((row, rowIndex) => {
    return a.map(val => val[rowIndex]).reverse();
  });
};

console.log(image);
console.log(rotateImage(image));
