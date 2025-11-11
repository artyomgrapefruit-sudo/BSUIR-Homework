#include <cmath>
#include <iostream>
#include <string.h>

int main() {
  double numerator, denominator, parentheses, x, y, z, answer;
  bool flag = true;

  while (flag) {
    std::cout << "Enter numbers" << std::endl;
    std::cin >> x >> y >> z;

    numerator = 2 * cos(x - M_PI / 6);
    denominator = 0.5 + pow(sin(y), 2);

    if (denominator != 0 && (3 - pow(z, 2) / 5) != 0) {
      parentheses = 1 + pow(z, 2)/(3 - pow(z, 2) / 5); // from "expression in parentheses"
      flag = false;
    }
  }

  answer = numerator / denominator * parentheses;
  std::cout << answer << std::endl;
  return 0;
}

// 14.26 -1.22 0.035