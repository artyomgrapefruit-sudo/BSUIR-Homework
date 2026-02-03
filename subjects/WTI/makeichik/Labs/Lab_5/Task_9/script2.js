let input = prompt("Input");

function compare(str, c_str) {
  for (let i = 0; i < 5; i++) {
    if (str[str.length - 5 + i] != c_str[i]) {
      return false;
    }
  }
  return true;
}

return compare(input, ".html");