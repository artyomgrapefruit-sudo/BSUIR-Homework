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

int32_t true_input(int mode = 1) { // Check that input number is number
    char* input = new char[255];
    bool is_number;

    do {
        std::cin >> input;
        is_number = true;
        size_t curr = 0;
        for (; input[curr] != '\0'; ++curr) {
            if (input[curr] > '9' || input[curr] < '0' || mode == 0 && input[curr] == '0') {
                std::cout << "Incorrect data!\nTry again:\n";
                is_number = false;
                break;
            }
        }
    } while (!is_number);

    return std::atoi(input);
}

struct Student {
    char surname[255] = {'\0'};
    char date_of_birth[255] = {'\0'};
    char group[255] = {'\0'};
    int32_t grades[4][20] = {{-1}};
    size_t last[4] = {0};
    bool initial = false;
    double average_grade = 0.0;

    void calculate_average_grade() {
        average_grade = 0.0;
        size_t total_grades = 0;
        for (size_t i = 0; i < 4; ++i) {
            for (size_t curr = 0; curr < last[i]; ++curr) {
                average_grade += grades[i][curr];
            }
            total_grades += last[i];
        }
        if (total_grades > 0) {
            average_grade /= total_grades;
        }
    }

    bool is_excellent_student() {
        calculate_average_grade();
        return (average_grade >= 9.5);
    }

    void save_to_file(FILE* file) {
        fwrite(surname, sizeof(char), 255, file);
        fwrite(date_of_birth, sizeof(char), 255, file);
        fwrite(group, sizeof(char), 255, file);
        fwrite(grades, sizeof(int32_t), 4 * 20, file);
        fwrite(last, sizeof(size_t), 4, file);
        fwrite(&initial, sizeof(bool), 1, file);
        fwrite(&average_grade, sizeof(double), 1, file);
    }

    void load_from_file(FILE* file) {
        fread(surname, sizeof(char), 255, file);
        fread(date_of_birth, sizeof(char), 255, file);
        fread(group, sizeof(char), 255, file);
        fread(grades, sizeof(int32_t), 4 * 20, file);
        fread(last, sizeof(size_t), 4, file);
        fread(&initial, sizeof(bool), 1, file);
        fread(&average_grade, sizeof(double), 1, file);
    }

    void input_from_console() {
        std::cout << "Enter surname and initials: ";
        std::cin >> surname;
        std::cout << "Enter date of birth: ";
        std::cin >> date_of_birth;
        std::cout << "Enter group number: ";
        std::cin >> group;
        initial = true;
    }

    void print_to_console() {
        if (!initial) {
            std::cout << "Null student\n";
            return;
        }
        std::cout << "Surname: " << surname << "\n";
        std::cout << "Date of birth: " << date_of_birth << "\n";
        std::cout << "Group: " << group << "\n";
        std::cout << "Average grade: " << average_grade << "\n";
    }

    void print_to_file(FILE* file) {
        fprintf(file, "Surname: %s\n", surname);
        fprintf(file, "Date of birth: %s\n", date_of_birth);
        fprintf(file, "Group: %s\n", group);
        fprintf(file, "Average grade: %.2f\n\n", average_grade);
    }
};

bool is_equal(const char* a, const char* b) {
    size_t i = 0;
    while (a[i] != '\0' && b[i] != '\0') {
        if (a[i] != b[i]) {
            return false;
        }
        ++i;
    }
    return a[i] == b[i];
}

void save_all_students(Student* students, size_t n, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (!file) {
        std::cout << "Error opening file for writing\n";
        return;
    }
    fwrite(&n, sizeof(size_t), 1, file);
    for (size_t i = 0; i < n; ++i) {
        students[i].save_to_file(file);
    }
    fclose(file);
}

size_t load_all_students(Student*& students, const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (!file) {
        return 0;
    }
    size_t n;
    fread(&n, sizeof(size_t), 1, file);
    students = new Student[n];
    for (size_t i = 0; i < n; ++i) {
        students[i].load_from_file(file);
    }
    fclose(file);
    return n;
}

int main() {
    const char* binary_filename = "students.txt";
    const char* text_filename = "students_report.txt";
    
    char Create[] = {'c', 'r', 'e', 'a', 't', 'e', '\0'};
    char View[] = {'v', 'i', 'e', 'w', '\0'};
    char Correct[] = {'c', 'o', 'r', 'r', 'e', 'c', 't', '\0'};
    char Task[] = {'t', 'a', 's', 'k', '\0'};
    char Exit[] = {'e', 'x', 'i', 't', '\0'};
    char Help[] = {'h', 'e', 'l', 'p', '\0'};

    Student* our_group = nullptr;
    size_t n = 0;

    // Try to load existing data
    // n = load_all_students(our_group, binary_filename);
    n = 0;
    if (n == 0) {
        std::cout << "No existing data found or error reading file.\n";
        std::cout << "Enter number of students: ";
        n = true_input(0);
        if (n == 0) {
            std::cout << "Number of students must be greater than 0\n";
            return 1;
        }
        our_group = new Student[n];
    } else {
        std::cout << "Loaded " << n << " students from file.\n";
    }

    std::cout << "\nChoose option:\ncreate\nview\ncorrect\ntask\nexit\nhelp [command]\n";

    while (true) {
        char command[10] = {'\0'};
        std::cout << "$: ";
        std::cin >> command;
        for (size_t i = 0; i < 10 && command[i] != '\0'; ++i) {
            command[i] = tolower(command[i]);
        }

        if (is_equal(command, Help)) {
            char command_help[10] = {'\0'};
            std::cin >> command_help;
            for (size_t i = 0; i < 10 && command_help[i] != '\0'; ++i) {
                command_help[i] = tolower(command_help[i]);
            }
            
            if (is_equal(command_help, Create)) {
                std::cout << "Command: create [student_number]\n";
                std::cout << "Creates new student record. Student number must be between 1 and " << n << "\n";
            } else if (is_equal(command_help, View)) {
                std::cout << "Command: view [student_number] or view all\n";
                std::cout << "Displays student information\n";
            } else if (is_equal(command_help, Correct)) {
                std::cout << "Command: correct [student_number]\n";
                std::cout << "Allows to edit student grades\n";
            } else if (is_equal(command_help, Task)) {
                std::cout << "Command: task [letter]\n";
                std::cout << "Finds excellent students whose surnames start with specified letter\n";
            } else if (is_equal(command_help, Exit)) {
                std::cout << "Command: exit\n";
                std::cout << "Exits the program and saves all data\n";
            } else {
                std::cout << "Available commands: create, view, correct, task, exit\n";
            }
            continue;
        }

        if (is_equal(command, Create)) {
            std::cout << "Enter student number (1-" << n << "): ";
            size_t student = true_input(0);
            if (student < 1 || student > n) {
                std::cout << "Invalid student number\n";
                continue;
            }
            our_group[student - 1].input_from_console();
            save_all_students(our_group, n, binary_filename);
            std::cout << "Student created and saved\n";
            continue;
        }

        if (is_equal(command, View)) {
            char param[10] = {'\0'};
            std::cin >> param;
            
            if (is_equal(param, "all")) {
                FILE* text_file = fopen(text_filename, "w");
                if (!text_file) {
                    std::cout << "Error opening text file\n";
                    continue;
                }
                fprintf(text_file, "=== ALL STUDENTS ===\n\n");
                for (size_t i = 0; i < n; ++i) {
                    if (our_group[i].initial) {
                        std::cout << "\nStudent " << (i + 1) << ":\n";
                        our_group[i].print_to_console();
                        our_group[i].print_to_file(text_file);
                    }
                }
                fclose(text_file);
                std::cout << "\nAll data also saved to " << text_filename << "\n";
            } else {
                size_t student = std::atoi(param);
                if (student < 1 || student > n) {
                    std::cout << "Invalid student number\n";
                    continue;
                }
                our_group[student - 1].print_to_console();
            }
            continue;
        }

        if (is_equal(command, Correct)) {
            std::cout << "Enter student number (1-" << n << "): ";
            size_t student = true_input(0);
            if (student < 1 || student > n) {
                std::cout << "Invalid student number\n";
                continue;
            }
            
            if (!our_group[student - 1].initial) {
                std::cout << "Student not initialized. Use 'create' command first.\n";
                continue;
            }
            
            const char subjects[4][15] = {"physics", "math", "IT", "chemistry"};
            for (size_t i = 0; i < 4; i++) {
                std::cout << "Enter number of grades for " << subjects[i] << " (max 20): ";
                size_t count_of_grades = true_input();
                if (count_of_grades > 20) count_of_grades = 20;
                
                our_group[student - 1].last[i] = 0;
                for (size_t curr_grade = 0; curr_grade < count_of_grades; ++curr_grade) {
                    std::cout << "Enter grade " << (curr_grade + 1) << ": ";
                    int32_t grade = true_input();
                    if (grade < 1 || grade > 5) {
                        std::cout << "Grade must be between 1 and 5\n";
                        curr_grade--;
                        continue;
                    }
                    our_group[student - 1].grades[i][our_group[student - 1].last[i]++] = grade;
                }
            }
            
            our_group[student - 1].calculate_average_grade();
            save_all_students(our_group, n, binary_filename);
            std::cout << "Student data updated and saved\n";
            continue;
        }

        if (is_equal(command, Task)) {
            char letter;
            std::cout << "Enter first letter of surname: ";
            std::cin >> letter;
            
            FILE* text_file = fopen(text_filename, "a");
            if (!text_file) {
                std::cout << "Error opening text file\n";
                continue;
            }
            
            fprintf(text_file, "\n=== EXCELLENT STUDENTS WITH SURNAME STARTING WITH '%c' ===\n\n", letter);
            
            bool found = false;
            for (size_t i = 0; i < n; ++i) {
                if (our_group[i].initial && 
                    our_group[i].surname[0] == letter && 
                    our_group[i].is_excellent_student()) {
                    
                    std::cout << "\nExcellent student found:\n";
                    our_group[i].print_to_console();
                    our_group[i].print_to_file(text_file);
                    found = true;
                }
            }
            
            if (!found) {
                std::cout << "No excellent students with surname starting with '" << letter << "'\n";
                fprintf(text_file, "No excellent students with surname starting with '%c'\n", letter);
            }
            
            fclose(text_file);
            std::cout << "\nResults saved to " << text_filename << "\n";
            continue;
        }

        if (is_equal(command, Exit)) {
            save_all_students(our_group, n, binary_filename);
            delete[] our_group;
            std::cout << "Data saved. Bye!\n";
            return 0;
        }

        std::cout << "Unknown command. Type 'help' for list of commands.\n";
    }

    return 0;
}