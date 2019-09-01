let fs = require('fs');

// this is Async operator
// fs.readFile('./test.txt', 'utf8', (err, data) => {
//     if(err) {
//         console.log(err);
//     } else {
//         console.log(data);
//     }
// });

// This is Sync operator
let data = fs.readFileSync('./test.txt', 'utf8');
console.log(data);

console.log('The end');