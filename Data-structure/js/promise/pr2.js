let add = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a != "number" || typeof b != "number") {
        return reject(new Error("Tham so phai la number"));
      }
      resolve(a + b);
    }, 2000);
  });
};

add('3', 5)
.then(data => console.log(data), err => console.log(err.toString()));