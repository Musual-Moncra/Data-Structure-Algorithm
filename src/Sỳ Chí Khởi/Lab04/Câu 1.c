#include <stdio.h>

// Bai 1: Dinh nghia cau truc Student (tuong tu nhu class)
typedef struct {
   int id;
   char name[30];
   float score;
} Student;

int main() {
   // Khoi tao co dinh danh sach sinh vien theo de bai
   Student students[] = {
      {123, "Binh", 7.50},
      {124, "An", 7.50},
      {125, "Khoa", 8.50},
      {126, "Thanh", 9.50},
      {127, "Nguyen", 5.50},
      {128, "Mai", 6.70},
      {129, "Hung", 7.30},
      {130, "Viet", 5.90}
   };
   
   int n = sizeof(students) / sizeof(students[0]);
   
   // In danh sach sinh vien
   printf("ID\tName\t\tScore\n");
   for (int i = 0; i < n; i++) {
      printf("%d\t%-10s\t%.2f\n", students[i].id, students[i].name, students[i].score);
   }
   
   return 0;
}
