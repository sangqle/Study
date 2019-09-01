let add = (a, b) => {
  return new Promise((resolve, reject) => {
    setTimeout(() => {
      if (typeof a != "number" || typeof b != "number") {
        return reject(new Error("Tham so phai la number PHEN CONG"));
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
// async awati a Promise
// return callback funtion
let tinhDienTichCallBack = async (a, b, h, cb) => {
  try {
    let ab = await add(a, b);
    let abh = await mutiply(ab, h);
    let square = await devide(abh, 2);
    cb(undefined, square);
  } catch (error) {
    cb(error);
  }
};

// async return a promise
let tinhDienTichPr = async (a, b, h) => {
  try {
    let ab = await add(a, b);
    let abh = await mutiply(ab, h);
    let square = await devide(abh, 2);
    return Promise.resolve(square);
  } catch (error) {
    return Promise.reject(error);
  }
};

// user callback to get reuse result.
tinhDienTichCallBack(2, 3, 5, (err, result) => {
  if (err) return console.log(err.toString());
  console.log(result);
});

tinhDienTichPr(2, 3, 5)
  .then(res => console.log(res))
  .catch(err => console.log(err));
