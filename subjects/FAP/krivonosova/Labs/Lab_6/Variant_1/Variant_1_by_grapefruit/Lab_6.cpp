#include <iostream>

int true_input () {
  char* input = new char[255];
  bool is_number;

  do {
    std::cin >> input;
    is_number = true;
    size_t curr = 0;
    for (;input[curr] != '\0'; ++curr) {
      if (input[curr] > '9' || input[curr] < '0' || (curr == 0 && input[curr] == '0')) {
        std::cout << "Incorrect data!\nTry again:\n";
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  return std::stoi(input);
}

int main()
{
  long long m, n, k, l, input, max;
  bool flag = true;

  std::cout << "Wrute size of matrix:\n";
  n = true_input();
  m = true_input();

  long long** input_array = new long long*[n]{new long long[m]};
  int* B = new int[n];

  std::cout << "Input matrix:\n";

  for (size_t i = 0; i < n; ++i)
  {
    B[i] = 1;
    max = input_array[i][0];
    for (size_t j = 0; j < m; ++j)
    {
      input_array[i][j] = true_input();
      if(input_array[i][j] >= max) {
        B[i] = 0;
      }
      max = input_array[i][j];
    }
  }

  for (size_t i = 0; i < n; ++i)
  {
    std::cout << B[i] << "    ";
  }
  
  return 0;
}