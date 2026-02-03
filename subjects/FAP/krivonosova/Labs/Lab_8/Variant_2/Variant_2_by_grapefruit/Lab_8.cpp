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
#include <stdio.h>

int32_t true_input ( int mode = 1) { // Check that input number is number
  char input[255];
  bool is_number;

  do {
    std::cin >> input;
    is_number = true;
    size_t curr = 0;
    for (;input[curr] != '\0'; ++curr) {
      if (input[curr] > '9' || input[curr] < '0') {
        std::cout << "Incorrect data!\nTry again:\n";
        is_number = false;
        break;
      }
    }
  } while (!is_number);

  return std::stoi(input);
}

struct Student {
  FILE *file = std::fopen("students.txt", "wb");
  bool initial = false;
  char surname[255] = {'\0'};
  char date_of_birth[255] = {'\0'};
  char group[255] = {'\0'};
  int32_t grades[4][20] = {-1};
  size_t last[4] = {0};
 private:
  double average_grade = -1;

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

  void save_to_file() {
    fwrite(surname, sizeof(char), 255, file);
    fwrite(date_of_birth, sizeof(char), 255, file);
    fwrite(group, sizeof(char), 255, file);
    fwrite(grades, sizeof(int32_t), 4 * 20, file);
    fwrite(last, sizeof(size_t), 4, file);
    fwrite(&initial, sizeof(bool), 1, file);
    fwrite(&average_grade, sizeof(double), 1, file);
  }

  void load_from_file() {
    fread(surname, sizeof(char), 255, file);
    fread(date_of_birth, sizeof(char), 255, file);
    fread(group, sizeof(char), 255, file);
    fread(grades, sizeof(int32_t), 4 * 20, file);
    fread(last, sizeof(size_t), 4, file);
    fread(&initial, sizeof(bool), 1, file);
    fread(&average_grade, sizeof(double), 1, file);
  }

  ~Student () {
    fclose(file);
  }

  friend std::ostream& operator<<(std::ostream& os, const Student& student);
  friend std::istream& operator>>(std::istream& in, Student& student);
};

std::ostream& operator << (std::ostream& os, const Student& student) {
  if (!student.initial) {
    return os << "Null student";  
  }
  return os << student.surname << " " << student.date_of_birth << " "
            << student.group << " " << (student.average_grade == -1 ? student.average_grade : 0);
}

std::istream& operator >> (std::istream& in, Student& student) {
  char new_surname[255];
  char new_date_of_birth[255];
  char new_group[255];

  in >> new_surname;
  
  for (size_t curr = 0; new_surname[curr] != '\0'; ++curr) {
    student.surname[curr] = curr[new_surname];
  }
  in >> new_date_of_birth;
  for (size_t curr = 0; new_date_of_birth[curr] != '\0'; ++curr) {
    student.date_of_birth[curr] = curr[new_date_of_birth];
  }
  in >> new_group;
  for (size_t curr = 0; new_group[curr] != '\0'; ++curr) {
    student.group[curr] = curr[new_group];
  }
  
  student.initial = true;
  return in;
}

bool is_equal (const char* a, const char* b) {
  size_t i = 0;
  while (a[i] != '\0' || b[i] != '\0') {
    if(a[i] != b[i]) {
      return false;
    }
    if(a[i] == b[i] == '\0') {
      return true;  
    }
    ++i;
  }
  return true;
}

int main () {
  FILE *filer = std::fopen("students.dat", "wb");
  fwrite("lalalala", sizeof(char), 8, filer);

  char Add[] = {'a', 'd', 'd', '\0', '\0'};
  char Get[] = {'g', 'e', 't', '\0', '\0'};
  char Edit[] = {'e', 'd', 'i', 't', '\0'};
  char Task[] = {'t', 'a', 's', 'k', '\0'};
  char Exit[] = {'e', 'x', 'i', 't', '\0'};
  char Help[] = {'h', 'e', 'l', 'p', '\0'};
  
  size_t n;
  bool no_one_grade_student_with_letter = true;
  bool no_one_grade_student = true;
  const char subjects[4][10] = {"physics", "math", "chemistry", "IT"};

  std::cout << "Write number of student: ";
  n = true_input();

  Student our_group[n];

  std::cout << "Choose option:\nAdd\nGet\nEdit\nTask\nExit\n";

  while (true) {
    char command[5] = {'\0'};
    std::cout << "$: ";
    std::cin >> command;
    for (size_t i = 0; i < 5; ++i) {
      if (command[i] != '\0') command[i] |= 0b100000;
    }

    if (is_equal(command, Help)) { // ------------------------------
      char command_help[5] = {'\0'};
      std::cin >> command_help;
      for (size_t i = 0; i < 5; ++i) {
        if (command_help[i] != '\0') command_help[i] |= 0b100000;
      }
      if (is_equal(command_help, Add)) { 
        std::cout << "commmand: add [number of student] [last name of student] [date of birth] [academic group]\nWhere 0 < number of student < count of students, last name is string, date of birth is integer, academic group is string\nResult 'Success' say that command work correct. Else you may see error mesage and command will be aborted\n";
      }
      if (is_equal(command_help, Get)) { 
        std::cout << "commmand: get [number of student]\nWhere 0 < number of student < count of students\n";
      }
      if (is_equal(command_help, Edit)) { 
        std::cout << "commmand: edit [number of student]\nWhere 0 < number of student < count of students\n";
      }
      if (is_equal(command_help, Exit)) { 
        std::cout << "commmand: exit\n Abort program\n";
      }
      
      continue;
    } // -----------------------

    if (is_equal(command, Add)) {
      std::cout << "Choose which student you want to add (enter number of student)\n";

      size_t student = true_input(0);
      if (student > n) {
        std::cout << "We can`t make this operation with this student";
        continue;
      }
      std::cout << "Write student №" << student << " last name, date of birth and academic group:\n";
      std::cin >> our_group[student - 1];
      std::cout << "Success! Student " << student << " was add\n"; // << our_group[student - 1] << std::endl;
      continue;
    }

    if (is_equal(command, Get)) {
      // std::cout << "Get\n";
      size_t student = true_input(0);
      if (student > n) {
        std::cout << "We can`t make this operation with this student\n";
        continue;
      }
      our_group[student - 1].is_extent_student();
      std::cout << our_group[student - 1] << std::endl;
      continue;
    }

    if (is_equal(command, Edit)) {

      size_t student = true_input(0);

      if (student > n) {
        std::cout << "We can`t make this operation with this student\n";
        continue;
      }

      for (size_t i = 0; i < 4; i++) {
        std::cout << "Write count of grades in " << subjects[i] << ": ";
        size_t count_of_grades = true_input();
        for (size_t curr_grade = 0; curr_grade < count_of_grades; ++curr_grade) {
          our_group[student - 1].grades[i][our_group[student - 1].last[i]++] = true_input();
        }
      }
      our_group[student - 1].is_extent_student();
      std::cout << "Success\n";
      continue;
    }

    if (is_equal(command, Task)) {
      // check all students was initialize?

      char f_let;
      // std::cout << "Type letter:\n";
      std::cin >> f_let;

      for (size_t curr = 0; curr < n; ++curr) {
        if (our_group[curr].surname[0] == f_let
        && our_group[curr].is_extent_student()) {
          std::cout << "Great student whith surname started with letter '" << f_let << "': " << our_group[curr] << std::endl;
          no_one_grade_student_with_letter = false;
        }
        no_one_grade_student = !our_group[curr].is_extent_student() && no_one_grade_student;
      }

      std::cout << std::endl;

      if (no_one_grade_student) {
        std::cout << "No one grade student in all group!!!\n";
        continue;;
      }

      if (no_one_grade_student_with_letter && !no_one_grade_student) {
        std::cout << "No one grade student with this letter!!!\n";
        continue;;
      }
      continue;
    }

    if (is_equal(command, Exit)) {
      std::cout << "Bye-bye!\n";
      return 0;
    }
    std::cout << "Command was not recognised\n";
  }

  std::cout << "Eeeend" << std::endl;
  return 0;
}