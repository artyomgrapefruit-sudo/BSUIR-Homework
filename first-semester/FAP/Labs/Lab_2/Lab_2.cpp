#include <iostream>
#include <cmath>

int main() {
  double z, x, fi = 0, answer, a = 1;
  // char* input = new char[255];
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

  z = std::stod(input);

  if(z < 1) {
    x = powf(z, 2);
    std::cout << "Calculation was made whith x = z^2\n";
  }
  else {
    x = z + 1;
    std::cout << "Calculation was made whith x = z + 1\n";
  }

  std::cout << "x = " << x << std::endl;
  std::cout << "Choose fi(write 1-3)\n1 - 2x\n2 - x^2\n3 - x/3\n";
  int choose;

  while (fi == 0) { // x ALWAYS more then 0, so fi is too always will be more then 0, if fi == 0 -> we didn`t made calculating
    std::cin >> choose;

    switch (choose)
    {
    case 1:
      fi = 2 * x;
      std::cout << "Calculation was made whith fi = 2x\n fi = " << fi << std::endl;
      continue;
      break;
    
    case 2:
      fi = pow(x, 2);
      std::cout << "Calculation was made whith fi = x^2\n fi = " << fi << std::endl;
      continue;
      break;

    case 3:
      fi = x / 3;
      std::cout << "Calculation was made whith fi = x/3\n fi = " << fi << std::endl;
      continue;
      break;

    default:
      std::cout << "...\nWhy... Try again\n";
      break;
    }
  }

  answer = 2 * a * log(1 + pow(x, 0.2)) + pow(cos(floor(fi + 1)), 2); // log(1 + pow(x, 0.2)) > 0
  std::cout << "So answer is: " << answer << std::endl;
}