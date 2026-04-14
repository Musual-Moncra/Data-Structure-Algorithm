// CTDL & GT - Lab 04
// Giang vien: Thay Vu Dinh Khoi
// Sinh vien: Sy Chi Khoi - MSSV: 22502168

#include <stdio.h>
#include <string.h>

// Bai 1
typedef struct {
   int id;
   char name[30];
   float score;
} Student;

void printStudent(Student s) {
   printf("%d\t%-10s\t%.2f\n", s.id, s.name, s.score);
}

// Bai 2
void searchById(Student students[], int n, int targetId) {
   int i;
   for (i = 0; i < n; i++) {
      if (students[i].id == targetId) {
         printStudent(students[i]);
         return; 
      }
   }
   printf("Not found\n"); 
}

// Bai 3
void searchByName(Student students[], int n, char targetName[]) {
   int i;
   int found = 0;
   char tempName[30];
   char tempTarget[30];

   strcpy(tempTarget, targetName);
   strupr(tempTarget);

   for (i = 0; i < n; i++) {
      strcpy(tempName, students[i].name);
      strupr(tempName);

      if (strcmp(tempName, tempTarget) == 0) {
         printStudent(students[i]);
         found = 1;
      }
   }

   if (!found) {
      printf("Not found\n");
   }
}

int main() {
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
   int targetId;
   char targetName[30];
   
   // Bai 2
   printf("Nhap ID can tim: ");
   scanf("%d", &targetId);
   searchById(students, n, targetId);
   
   // Bai 3
   printf("\nNhap ten can tim: ");
   scanf("%s", targetName);
   searchByName(students, n, targetName);
   
   return 0;
}
