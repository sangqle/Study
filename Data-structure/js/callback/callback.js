let square = (a, b, h) => {
    return (a + b)* h / 2;
}

console.log(square(2, 3, 2));

let add = (a, b, cb) => {
    setTimeout(() => {
        let err, result;
        if(typeof a != 'number' || typeof b != 'number') {
            err = new Error('Tham so phai la number');
            return cb(err, result);
        }
        result = a + b;
        cb(err, result);
    }, 500)
}

let multiply = (a, b, cb) => {
    setTimeout(() => {
        let err, result;
        if(typeof a != 'number' || typeof b != 'number') {
            err = new Error('Tham so phai la number');
            return cb(err, result);
        }
        result = a * b;
        cb(err, result);
    }, 500)
}


let divide = (a, b, cb) => {
    setTimeout(() => {
        let err, result;
        if(typeof a != 'number' || typeof b != 'number') {
            err = new Error('Tham so phai la number');
            return cb(err, result);
        }
        if(b == 0) {
            return cb(new Error('Chia Cho 0'));
        }
        result = a / b;
        cb(err, result);
    }, 500)
}

// add(4, '5', (err, result) => {
//     if(err) {
//         console.log(err.toString());
//     } else {
//         console.log(result);
//     }
// })

let tinhDienTichHinhThang = (a, b, h, cb) => {
    add(a, b, (err, result) => {
        if(err) return cb(err);
        multiply(result, h, (err, result) => {
            if(err) return cb(err);
            divide(result, 2, (err, square) => {
                if(err) return cb(err);
                return cb(undefined, square);
            })
        })
    })
}

tinhDienTichHinhThang(2, '3', 4, (err, data) => {
    if(err) return console.log(err.toString());
    console.log(data);
});