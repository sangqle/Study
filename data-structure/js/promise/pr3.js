let add = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a != "number" || typeof b != "number") {
        return reject(new Error("Tham so phai la number"));
      }
      resolve(a + b);
    }, 500);
  });
};

let mutiply = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a != "number" || typeof b != "number") {
        return reject(new Error("Tham so phai la number"));
      }
      resolve(a * b);
    }, 500);
  });
};

let devide = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a != "number" || typeof b != "number") {
        return reject(new Error("Tham so phai la number"));
      }
      if (b === 0) return reject(new Error("Chi cho 0"));
      resolve(a / b);
    }, 500);
  });
};

let tinhDienTich = (a, b, h) => {
  return add(a, b)
    .then(res => mutiply(res, h))
    .then(result => devide(result, 2));
};

tinhDienTich(6, 4, 5)
  .then(square => console.log("DienTich: " + square))
  .catch(err => {
    console.log(err.toString());
  }); // catch all err throw out from then(err) and break then if throw out the erro anywhere imminately
