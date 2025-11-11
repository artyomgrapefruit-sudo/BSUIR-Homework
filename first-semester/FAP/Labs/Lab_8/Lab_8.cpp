/*
Написать программу обработки файла типа запись, содержащую следующие пункты меню:
«Создание», «Просмотр», «Коррекция» (добавление новых данных или редактирование старых), «Решение индивидуального задания».
Каждая запись должна содержать следующую информацию о студентах:
– фамилия и инициалы;
– год рождения;
– номер группы;
– оценки за семестр: по физике, математике, информатике, химии;
– средний балл.
Организовать ввод исходных данных, средний балл рассчитать по введенным оценкам.
Содержимое всего файла и результаты решения индивидувльного задания записать в текстовый файл.

2. Распечатать анкетные данные студентов-отличников, фамилии которых начинаются с интересующей вас буквы.
*/
#include <iostream>

struct Student {
  char surname[255] = {'\0'};
  char initial_1[255] = {'\0'};
  char initial_2[255] = {'\0'};
  char date_of_birth[255] = {'\0'};
  char group[255] = {'\0'};
  int32_t grades[4][20] = {-1};
  size_t last[4] = {0};
 private:
  double average_grade;

 public:
  const double& student_average_grade () {
    average_grade = 0;
    for (size_t i = 0; i < 4; ++i) {
      for (size_t curr = 0; curr <  last[i]; ++curr) {
        average_grade += grades[i][curr];
      }
    }
    average_grade /= (last[0] + last[1] + last[2] + last[3]);
    return average_grade;
  }

  bool is_extent_student () {
    return (student_average_grade() > 9.0);
  }

  friend std::ostream& operator<<(std::ostream& os, const Student& student);
  friend std::istream& operator>>(std::istream& in, Student& student);
  
  /*
  std::basic_iostream<char> operator<<(Student a) {
    char output[255] = ;
    return (this->surname + this->initial_1 + initial_2 + date_of_birth + group);
  }
    */
};

std::ostream& operator << (std::ostream& os, const Student& student) {
    return os << student.surname << " " << student.initial_1 << " " << student.initial_2 << " "
              << student.date_of_birth << " " << student.group << " " << student.average_grade;
}

std::istream& operator >> (std::istream& in, Student& student) {
  char new_surname[255];
  char new_initial_1[255];
  char new_initial_2[255];
  char new_date_of_birth[255];
  char new_group[255];

  in >> new_surname >> new_initial_1 >> new_initial_2 >> new_date_of_birth >> new_group;
  
  for (size_t curr = 0; new_surname[curr] != '\0'; ++curr) {
    student.surname[curr] = curr[new_surname];
  }
  for (size_t curr = 0; new_initial_1[curr] != '\0'; ++curr) {
    student.initial_1[curr] = curr[new_initial_1];
  }
  for (size_t curr = 0; new_initial_2[curr] != '\0'; ++curr) {
    student.initial_2[curr] = curr[new_initial_2];
  }
  for (size_t curr = 0; new_date_of_birth[curr] != '\0'; ++curr) {
    student.date_of_birth[curr] = curr[new_date_of_birth];
  }
  for (size_t curr = 0; new_group[curr] != '\0'; ++curr) {
    student.group[curr] = curr[new_group];
  }
  
  return in;
}



int32_t true_input () { // std::cin but check that input number is number
  char input[255];
  bool is_number;

  do {
    std::cin >> input;
    is_number = true;
    size_t curr = 0;
    for (;input[curr] != '\0'; ++curr) {
      if (input[curr] > '9' || input[curr] < '0') {
        std::cout << "Incorrect data!\nTrue again:\n";
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  return std::stoi(input);
}

int main () {
  size_t n;
  bool no_one_grade_student_with_letter = true;
  bool no_one_grade_student = true;
  const char subjects[4][10] = {"physics", "math", "chemistry", "IT"};

  std::cout << "Write number of student\n";
  n = true_input();

  Student our_group[n];
  for (size_t curr = 0; curr < n; ++curr) {
    std::cout << "Write student №" << curr + 1 << " last name, initials, date of birth and academic group:\n";

    std::cin >> our_group[curr];
    
    for (size_t i = 0; i < 4; i++)
    {
      std::cout << "Write count of grades in " << subjects[i] << ": ";
      size_t count_of_grades = true_input();
      for (size_t curr_grade = 0; curr_grade < count_of_grades; ++curr_grade) {
        our_group[curr].grades[i][our_group[curr].last[i]++] = true_input();
      }
    }
  }

  // добавить ввод чара и ыыыыыыы

  char f_let;
  std::cout << "Type letter:\n";
  std::cin >> f_let;

  for (size_t curr = 0; curr < n; ++curr) {
    if (our_group[curr].surname[0] == f_let
     && our_group[curr].is_extent_student()) {
      std::cout << "Great student whith surname started with letter '" << f_let << "': " << our_group[curr] << std::endl;
      no_one_grade_student_with_letter = false;
    }
    no_one_grade_student = !our_group[curr].is_extent_student() && no_one_grade_student;
    /*
      new_n_o| is-ex n_o           
        0   |   0    0
        1   |   0    1
        0   |   1    0
        0   |   1    1

        !is_ex && n_o
    */
  }

  std::cout << std::endl;

  if (no_one_grade_student) {
    std::cout << "No one grade student in all!!!\n";
    // return 0;
  }

  if (no_one_grade_student_with_letter && !no_one_grade_student) {
    std::cout << "No one grade student with this letter!!!\n";
    // return 0;
  }

  std::cout << "All students:\n";

  for (size_t curr = 0; curr < n; ++curr) {
    std::cout << "Student: " << our_group[curr] << std::endl;
  }

  std::cout << "Eeeend" << std::endl;
  return 0;
}