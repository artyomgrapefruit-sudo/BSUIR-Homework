let input = prompt("Input");

function compare(str, c_str) {
  for (let i = 0; i < 7; i++) {
    if (str[i] != c_str[i]) {
      return false;
    }
  }
  return true;
}

return compare(input, "http://");