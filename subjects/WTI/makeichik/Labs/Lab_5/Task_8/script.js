let input1 = Number(prompt("N1"));
let input2 = Number(prompt("N2"));

let result = (n1, n2) => n1 > n2 ? 1 : n1 == n2 ? 0 : -1;

alert(result(input1, input2));