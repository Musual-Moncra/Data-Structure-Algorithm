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

int seraching_id(SinhVien std[], int n, int id) {
  for (int i = 0; i < n; i++) {
    if (std[i].id == id) {
      return i;
    }
  }
  return -1;
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

  int id;
  printf("Enter ID: ");
  scanf("%d", &id);

  int index = seraching_id(std_list, n, id);
  if (index != -1) {
    printf("Name: %s\n", std_list[index].name);
    printf("ID: %d\n", std_list[index].id);
    printf("GPA: %.2f\n", std_list[index].gpa);
  } else {
    printf("Not found\n");
  }
}