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
#include <vector>

int main()
{
  size_t m, n, k;
  int64_t l, input, max;
  bool flag = true;

  std::cout << "Wrute size of matrix:\n";
  std::cin >> n >> m;

  int64_t input_array[n][m];
  int32_t B[n];

  std::cout << "Input matrix:\n";

  for (size_t i = 0; i < n; ++i)
  {
    B[i] = 1;
    max = input_array[i][0];
    for (size_t j = 0; j < m; ++j)
    {
      std::cin >> input_array[i][j];
      if(input_array[i][j] >= max) {
        B[i] = 0;
      }
      max = input_array[i][j];
    }
  }

  for (size_t i = 0; i < n; ++i)
  {
    std::cout << B[i] << "    ";
    // for (size_t j = 0; j < m; ++j)
    // {
    //   std::cout << input_array[i][j] << " ";
    // }
    // std::cout << std::endl;  
  }

  
  
  return 0;
}