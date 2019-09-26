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
        return reject(new Error("Tham so phai la number PHEP NHAN"));
      }
      resolve(a * b);
    }, 100);
  });
};

// Promise.all([mutiply(4, '5'), add(4, '6')]) // all the promise is resolve then handle is excute
//   .then(result => {
//     console.log(result);
//   })
//   .catch(err => {
//     console.log(err.toString());
//   }); // call when the promise throw error the first

Promise.race([mutiply(4, 5), add(4, '6')])
  .then(result => {
    console.log(result);
  })
  .catch(err => {
    console.log(err.toString());
  }); // return result of promise throw result the first notwithstanding whether or not err
