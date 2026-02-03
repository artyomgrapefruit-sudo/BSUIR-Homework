#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

struct TZap {
    char Fam[21];
    int brth;
    int group;
    int fiz;
    int math;
    int inf;
    int chem;
};

FILE* Fz, * Ft;

char File_Zap[] = "zapisi.dat";
char File_Rez[] = "rezult.txt";
void Out(TZap);

double fs_b(int f, int m, int i, int c) {
    return (f + m + i + c) / 4.0;
}

void Out(TZap Zap) {
  double s_b = fs_b(Zap.fiz, Zap.math, Zap.inf, Zap.chem);
  printf("\n%20s , Год рождения: %d, Группа: %d, Средний балл: %.2lf\n", Zap.Fam, Zap.brth, Zap.group, s_b);
  fprintf(Ft, "\n%20s , Год рождения: %d, Группа: %d, Средний балл: %.2lf\n", Zap.Fam, Zap.brth, Zap.group, s_b);
}

int main() {
  setlocale(LC_ALL, "rus");
  int size = sizeof(TZap);
  int kod, i, j, kol;
  long len;
  TZap st, * mas_Z;

  Ft = fopen(File_Rez, "w");
  if (Ft == NULL) {
      cout << "Ошибка при открытии файла для записи результатов!" << endl;
      return 1;
  }

  while (1) {
    puts("\n Создать – 1\n Добавить – 2\n Просмотреть – 3\n Вывести студентов с баллом выше среднего – 4\n EXIT – 0");
    scanf("%d", &kod);

    switch (kod) {
    case 1:
        Fz = fopen(File_Zap, "wb");
        if (Fz == NULL) {
            puts("\n Ошибка при создании!");
            return 1;
        }
        fclose(Fz);
        printf("\n Создали файл %s !\n", File_Zap);
        break;

    case 2:
        Fz = fopen(File_Zap, "ab");
        if (Fz == NULL) {
            puts("\n Ошибка при открытии файла для добавления!");
            return 1;
        }

        printf("\n Фамилия и инициалы (Иванов И.И.): ");
        scanf("%s", st.Fam);
        printf("Год рождения - ");
        scanf("%d", &st.brth);
        printf("Номер группы  – ");
        scanf("%d", &st.group);
        printf("\n Отметка по физике – ");
        scanf("%d", &st.fiz);
        printf("\n Отметка по математике – ");
        scanf("%d", &st.math);
        printf("\n Отметка по информатике – ");
        scanf("%d", &st.inf);
        printf("\n Отметка по химии – ");
        scanf("%d", &st.chem);
        fwrite(&st, size, 1, Fz);
        fclose(Fz);
        break;

    case 3:
        Fz = fopen(File_Zap, "rb");
        if (Fz == NULL) {
            puts("\n Open ERROR!");
            return 1;
        }
        printf("\n\t--------- Informations ---------");
        fprintf(Ft, "\n\t--------- Informations ---------");

        while (fread(&st, size, 1, Fz) == 1) {
            Out(st);
        }
        fclose(Fz);
        break;

    case 4:
        Fz = fopen(File_Zap, "rb");
        if (Fz == NULL) {
            puts("\n Open ERROR!");
            return 1;
        }

        fseek(Fz, 0, SEEK_END);
        len = ftell(Fz);
        kol = len / size;
        mas_Z = new TZap[kol];

        fseek(Fz, 0, SEEK_SET);
        fread(mas_Z, size, kol, Fz);
        fclose(Fz);

        double total_score = 0.0;

        for (i = 0; i < kol; i++) {
            total_score += fs_b(mas_Z[i].fiz, mas_Z[i].math, mas_Z[i].inf, mas_Z[i].chem);
        }

        double average_score = 0.0;
        if (kol > 0) {
            average_score = total_score / kol;
        }

        printf("\nОбщий средний балл всех студентов: %.2lf\n", average_score);
        fprintf(Ft, "\nОбщий средний балл всех студентов: %.2lf\n", average_score);

        printf("\nСтуденты с баллом выше общего среднего:\n");
        fprintf(Ft, "\nСтуденты с баллом выше общего среднего:\n");
        for (i = 0; i < kol; i++) {
            double student_score = fs_b(mas_Z[i].fiz, mas_Z[i].math, mas_Z[i].inf, mas_Z[i].chem);
            if (student_score > average_score) {
                Out(mas_Z[i]);
            }
        }

        delete[] mas_Z;
        break;

        fclose(Ft);
        return 0;
    }
  }

  return 0;
}