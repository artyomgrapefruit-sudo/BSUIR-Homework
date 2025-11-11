#include <cmath>
#include <iostream>
#include <iomanip>

double fact (double num) {
  if (num < 3) {
    return num;
  }
  return num * fact(num - 1);
}

int main () {
  double difference, a, b, h, n, x, y, s, power;
  int after_point = 5;

  std::cout << "Input a, b, h, n" << std::endl;
  std::cin >> a >> b >> h >> n;

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