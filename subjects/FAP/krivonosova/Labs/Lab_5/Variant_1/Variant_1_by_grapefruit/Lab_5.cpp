#include <iostream>
#include <ctime>

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

int main() {
  size_t n, k_max, k_min;
  int64_t max, min, answer = 1;
  bool rand_input, sorter_input;
  std::cout << "Input size of array\n";
  n = true_input();
  int64_t array[n]; // можем и создать массив из 2^64 элементов
  
  while (rand_input != 0 || rand_input != 1) {
    std::cout << "Random or not random?\n 0 - hand\n 1 - random\n";
    rand_input = true_input();
  }
  std::cout << "Input numbers:\n";

  srand(time(0));


  for (int64_t curr = 0; curr < n; ++curr) {
    if(rand_input) {
      array[curr] = rand() % 10;
      std::cout << array[curr] << " ";
    } else {
      array[curr] = true_input();
    }
  std::cout << std::endl;

    if (array[curr] > max || curr == 0) {
      max = array[curr];
      k_max = curr;
    }

    if (array[curr] < min || curr == 0) {
      min = array[curr];
      k_min = curr;
    }    
  }
  
  if (abs(k_max - k_min) < 2) {
    std::cout << "No numbers";
    return 0;
  }

  for (int64_t curr = std::min(k_min, k_max) + 1; curr < std::max(k_min, k_max); ++curr) {
    answer *= array[curr];
  }

  std::cout << "Resut: " << answer << std::endl;
}