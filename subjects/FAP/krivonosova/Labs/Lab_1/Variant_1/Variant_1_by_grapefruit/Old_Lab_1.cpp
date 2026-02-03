#include <cmath>
#include <iostream>

using namespace std;

int main() {
  double numerator, denominator, parentheses, x, y, z, answer;
  bool flag = true;

  while (flag) {
    cout << "Enter numbers" << std::endl;
    cin >> x >> y >> z;

    numerator = 2 * cos(x - M_PI / 6);
    denominator = 0.5 + pow(sin(y), 2);

    if (denominator != 0 && (3 - pow(z, 2) / 5) != 0) {
      parentheses = 1 + pow(z, 2)/(3 - pow(z, 2) / 5); // from "expression in parentheses"
      flag = false;
    }
  }

  answer = numerator / denominator * parentheses;
  cout << answer << endl;
  return 0;
}