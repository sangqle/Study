let aPromise = new Promise((resolve, reject) => {
  //resolve("Thanh Cong");
  setTimeout(() => {
    reject("khong The ket noi");
  }, 2000);
}).then(
  result => {
    console.log(result);
  },
  err => {
    console.log(err.toString());
  }
);
