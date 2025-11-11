/*
  В оконном приложении исходные данные вводить из компоненты Edit в ListBox (заканчивать нажатием Enter).
  Скалярный результат выводить в компоненту Label. Для выхода из программы использовать кнопку «Close».

  2. В строке, состоящей из групп нулей и единиц, найти и вывести на экран самую короткую группу.
*/

// Solution was made by vector

#include <iostream>
#include <vector>

int main () {
  std::vector<std::pair<int64_t, int64_t>> distance;
  char str[255];
  std::cin >> str;

  size_t curr = 1;
  distance.push_back(std::pair(0, -1));

  while (str[curr] != '\0') {
    if(str[curr] != str[curr - 1]) {
      distance.back().second = curr - distance.back().first;
      distance.push_back(std::pair(curr, -1));
    }
    ++curr;
  }
  distance.back().second = curr - distance.back().first;

  std::pair<int64_t, int64_t> min = distance.front();
  for (std::pair<int64_t, int64_t> current : distance) {
    if(min.second > current.second) {
      min = current;
    }
  }

  for (size_t curr_point = min.first; curr_point < min.first + min.second; ++curr_point) {
    std::cout << str[curr_point];
  }
  return 0;
}