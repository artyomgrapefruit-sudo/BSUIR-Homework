let input = prompt("Введи сумму своей зарплаты пж");

let result = input;
result *= 1.15;
alert("Премия 15% " + result);
result -= 0.1 * result;
alert("НДС " + result);
result -= 90;
alert("Похож в магазин " + result);
result /= 2;
alert("Поделим с супругой/супрогом " + result);

alert(result);