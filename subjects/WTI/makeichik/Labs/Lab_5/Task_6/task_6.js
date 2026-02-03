function square(n) {
  return Number(n) * Number(n);
}

function sum(n1, n2) {
  return Number(n1) + Number(n2);
}

function dif_and_div(n1, n2, n3) {
  return (Number(n1) - Number(n2)) / Number(n3);
}

function week(d) {
  switch (Number(d)) {
    case 1: alert("Понедельник"); break;
    case 2: alert("Вторник"); break;
    case 3: alert("Среда"); break;
    case 4: alert("Четверг"); break;
    case 5: alert("Пятница"); break;
    case 6: alert("Суббота"); break;  
    case 7: alert("Восскресенье"); break;  
    default:
    alert("Ты дурень");
      break;
  }  
}

while (1) {
  input = Number(prompt("Введите подпункт задачи"));

  switch (input) {
    case 1:
      var num = prompt("Введите число");
      alert(square(num));
      break;

    case 2:
      var num1 = prompt("Введите первое число");
      var num2 = prompt("Введите второе число");
      alert(sum(num1, num2));
      break;

    case 3:
      var num1 = prompt("Введите первое число");
      var num2 = prompt("Введите второе число");
      var num3 = prompt("Введите второе число");
      alert(dif_and_div(num1, num2, num3));
      break;

    case 4:
      var day = prompt("Введите номер дня недели");
      week(day);
      break;

    default:
      alert("Чет не так");
      break;
  }
}