#include <stdio.h>

typedef struct SinhVien {
  char name[100];
  int id;
  float gpa;
} SinhVien;

void print_std(SinhVien std[], int n) {
  for (int i = 0; i < n; i++) {
    printf("Name: %s\n", std[i].name);
    printf("ID: %d\n", std[i].id);
    printf("GPA: %.2f\n", std[i].gpa);
  }
}

void main() {
  SinhVien std_list[] = {
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0}, {"Nguyen Thai Bao", 20246026, 9.0},
      {"Nguyen Thai Bao", 20246026, 9.0},
  };

  int n = sizeof(std_list) / sizeof(std_list[0]);

  print_std(std_list, n);
}