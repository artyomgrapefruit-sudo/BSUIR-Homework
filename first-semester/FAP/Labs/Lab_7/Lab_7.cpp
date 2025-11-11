/*
	В оконном приложении исходные данные вводить из компоненты Edit в ListBox (заканчивать нажатием Enter).
  Скалярный результат выводить в компоненту Label. Для выхода из программы использовать кнопку «Close».

	2. В строке, состоящей из групп нулей и единиц, найти и вывести на экран самую короткую группу.
*/

#include <iostream>
#include <vector>

int main () {
	size_t distance[255] = {0};
	int64_t key[255] = {-1};
	key[0] = 0;
	size_t last = 0;
	char str[255] = {'\0'};
	bool is_number = true;

	do {
		last = 0;
		size_t curr = 0;
		std::cout << "Please write line with 0 and 1\n";
		is_number = true;
		std::cin >> str;

		while (str[curr] != '\0') {
			if(str[curr] != '0' && str[curr] != '1' && str[curr] != '\0') {
				std::cout << "Incorrect data!\nTry again:\n";
				is_number = false;
				break;
			}

			if (curr != 0 && str[curr] != str[curr - 1]) {
				distance[last] = curr - key[last];
				key[++last] = curr;
			}
			++curr;
		}
		
		distance[last] = curr - key[last];
		key[++last] = curr;
	} while (!is_number);

	size_t min_distance = distance[0];
	int64_t min_key = key[0];
	
	for (size_t i = 1; i < last; ++i) {
		if (min_distance > distance[i]) {
			min_distance = distance[i];
			min_key = key[i];
		}
	}

	for (size_t curr_point = min_key; curr_point < min_distance + min_key; ++curr_point) {
	 	std::cout << str[curr_point];
	}

	std::cout << std::endl;
	
	return 0;
}
//     4   8901234
// 000011110101010
//     ^   ^^^^^^^e
