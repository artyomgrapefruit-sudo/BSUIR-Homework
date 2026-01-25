/*
  Написать программу по обработке динамических массивов.
  Размеры массивов вводить с клавиатуры.

  При создании оконного приложения скалярный (простой) результат выводить в виде компоненты Label,
  а массивы вводить и выводить с помощью компонент StringGrid,\
  в которых 0-й столбец и 0-ю строку использовать для отображения индексов массивов.

  2. Из матрицы размером NxM получить вектор B, присвоив его k-му элементу значение 1,
  если элементы k-й строки матрицы упорядочены по убыванию, иначе 0.
*/

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
  size_t m, n, k;
  int64_t l, input, max;
  bool flag = true;

  std::cout << "Wrute size of matrix:\n";
  n = true_input();
  m = true_input();

  int64_t** input_array = new int64_t*[n]{new int64_t[m]};
  int32_t* B = new int32_t[n];

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