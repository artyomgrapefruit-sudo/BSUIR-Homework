#include <cmath>
#include <iostream>
#include <string>

double true_input () {
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

  return std::stod(input);
}

int main() {
  double alpha = true_input();

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
