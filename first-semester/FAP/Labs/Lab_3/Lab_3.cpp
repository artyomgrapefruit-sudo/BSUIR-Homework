// pow by myself?

#include <cmath>
#include <iostream>
#include <iomanip>

double fact (double num) {
  if (num < 3) {
    return num;
  }
  return num * fact(num - 1);
}

int true_input () {
  char* input = new char[255];
  bool is_number;
  do {
    std::cin >> input;
    is_number = true;
    size_t curr = 0;
    for (;input[curr] != '\0'; ++curr) {
      if ((input[curr] > '9' || input[curr] < '0' || (curr == 0 && input[curr] == '0')) && input[curr] != '.') {
        std::cout << "Incorrect data!\nTry again:\n";
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  return std::stoi(input);
}

int main () {
  double difference, a, b, h, n, x, y, s, power;
  int after_point = 5;

  std::cout << "Input a" << std::endl;
  a = true_input();
  std::cout << "Input b" << std::endl;
  b = true_input();
  std::cout << "Input h" << std::endl;
  h = true_input();
  std::cout << "Input n" << std::endl;
  n = true_input();

  std::string tab = std::string(after_point + 5, ' ');
  std::cout << "\tx" << tab << "y" << tab << "s" << tab << "difference" << std::endl;
  std::cout << std::setprecision(after_point);

  tab = std::string(4, ' ');
  power = pow(10, after_point);
  x = a;

  while (x < b) {
    y = round(sin(x)*power)/power;
    s = 0;
    for (int k = 0; k < n; ++k) {
      s += pow(-1, k) * pow(x, 2 * k + 1) / fact(2 * k + 1);
      s = round(s*power)/power;
    }
    difference = (s > y) ? (s - y) : (y - s);
    std::cout << std::fixed << "\t" << x << tab << y << tab << s << tab << difference << std::endl;
    x += h;
  }
}