const n = 7;
for (let i = 0; i < n; i++) {
  let pr = "";
  for (let j = 1; j <= n + n - 1; j++) {
    if (j >= n - i && j <= n + i) pr += "*";
    else pr += "_";
  }
  console.log(pr);
}

/*+
 * * *
 * * * *
 * * * * *
 */
