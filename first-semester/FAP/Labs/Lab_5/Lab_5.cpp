/* 
Размеры массивов вводить с клавиатуры.
В консольном приложении предусмотреть возможность ввода данных как с клавиатуры,
так и с использованием функции random().

В одномерном массиве, состоящем из n вводимых с клавиатуры целых элементов, вычислить:
    Произведение элементов массива, расположенных между максимальным и минимальным элементами.
*/

#include <iostream>
#include <algorithm>
#include <ctime>


int main() {
  size_t n, k_max, k_min;
  int64_t max, min, answer = 1;
  bool rand_input, sorter_input;
  std::cout << "Input size of array\n";
  std::cin >> n;
  int64_t array[n]; // можем по идее и создать массив из 2^64 элементов
  
  std::cout << "Random or not random?\n 0 - hand\n 1 - random\n";
  std::cin >> rand_input;
  std::cout << "Input numbers:\n";

  srand(time(0));


  for (int64_t curr = 0; curr < n; ++curr) {
    if(rand_input) {
      array[curr] = rand() % 10;
      std::cout << array[curr] << " ";
    } else {
      std::cin >> array[curr];
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

  std::cout << "Resut:" << answer << std::endl;
}