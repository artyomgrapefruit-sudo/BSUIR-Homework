#include <cmath>
#include <iostream>
#include <string>

int main() {
  std::string input;
  bool is_number;

  do {
    is_number = true;
    std::cout << "Enter number" << std::endl;
    std::cin >> input;
    for (int curr = 0; curr < input.length(); ++curr) {
      char curr_s = input[curr];
      if ( curr_s > '9' || curr_s < '0' && curr_s != '.') {
        std::cout << "Your answer incorrect, please try again" << std::endl;
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  double alpha = stod(input);

  double numerator = sin(2*alpha) + sin(5*alpha) - sin(3*alpha);
  double denominator = cos(alpha) + 1 - 2*pow( sin(2*alpha), 2);

  while (denominator == 0) {
    std::cout << "Incorrect data, please try again" << std::endl;
    std::cin >> alpha;

    numerator = sin(2*alpha) + sin(5*alpha) - sin(3*alpha);
    denominator = cos(alpha) + 1 - 2 * pow(sin(2*alpha), 2);
  }

  double z1 = numerator/denominator;
  double z2 = 2 * sin(alpha);

  std::cout << z1 << " " << z2 << std::endl;
  return 0;
}
