/*
Viết chương trình đọc thông tin sinh viên từ tập tin students.txt và hiển thị menu cho
phép người dùng chọn cột cần sắp xếp (cột name hoặc score), thứ tự sắp xếp
(tăng/increasing hoặc giảm/descending), sau đó in danh sách sinh viên sau khi sắp xếp ra
màn hình và lưu danh sách được sắp xếp vào tập tin students_sorted.txt
Hint: sử dụng con trỏ hàm (function pointer) để tổng quát việc sắp xếp theo cột bất kỳ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// 1. Hàm lấy Tên (phần sau khoảng trắng cuối cùng)
const char* getFirstName(const char* fullName) {
    const char* lastSpace = strrchr(fullName, ' '); 
    if (!lastSpace) return fullName; 
    return lastSpace + 1; 
}

// --- CÁC HÀM SO SÁNH (Dùng cho con trỏ hàm) ---

int compareNameInc(Student a, Student b) {
    return stricmp(getFirstName(a.name), getFirstName(b.name)) > 0;
}

int compareNameDec(Student a, Student b) {
    return stricmp(getFirstName(a.name), getFirstName(b.name)) < 0;
}

int compareGradeInc(Student a, Student b) {
    return a.grade > b.grade;
}

int compareGradeDec(Student a, Student b) {
    return a.grade < b.grade;
}

// --- HÀM TỔNG QUÁT ---

// Hàm sắp xếp dùng con trỏ hàm: int (*cmp)(Student, Student)
void sortStudents(Student students[], int n, int (*cmp)(Student, Student)) {
    for (int i = 0; i < n - 1; i++) {
        int target_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (cmp(students[target_idx], students[j])) {
                target_idx = j;
            }
        }
        if (target_idx != i) {
            Student temp = students[i];
            students[i] = students[target_idx];
            students[target_idx] = temp;
        }
    }
}

// --- CÁC HÀM XỬ LÝ FILE & HIỂN THỊ ---

int loadStudents(Student students[]) {
    FILE *f = fopen("src/TranHieu/tuan5/students.txt", "r");
    if (!f) return 0;
    int count = 0;
    while (fscanf(f, "%d", &students[count].id) == 1) {
        students[count].name[0] = '\0';
        char word[20];
        while (fscanf(f, "%s", word) == 1) {
            if (isdigit(word[0])) {
                students[count].grade = atof(word);
                break;
            } else {
                if (strlen(students[count].name) > 0) strcat(students[count].name, " ");
                strcat(students[count].name, word);
            }
        }
        count++;
    }
    fclose(f);
    return count;
}

void saveToFile(Student students[], int n) {
    FILE *f = fopen("students_sorted.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    fclose(f);
}

void display(Student students[], int n) {
    printf("\n%-10s %-20s %-10s\n", "ID", "Full Name", "Grade");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-10d %-20s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
}

int main() {
    Student list[100];
    int n = loadStudents(list);
    if (n == 0) { printf("Khong doc duoc file!\n"); return 1; }

    int col, order;
    printf("Chon cot sap xep (1. Name, 2. Score): "); scanf("%d", &col);
    printf("Chon thu tu (1. Tang dan, 2. Giam dan): "); scanf("%d", &order);

    // Sử dụng con trỏ hàm để quyết định cách so sánh
    int (*cmpPtr)(Student, Student) = NULL;

    if (col == 1) {
        cmpPtr = (order == 1) ? compareNameInc : compareNameDec;
    } else {
        cmpPtr = (order == 1) ? compareGradeInc : compareGradeDec;
    }

    sortStudents(list, n, cmpPtr);
    display(list, n);
    saveToFile(list, n);
    printf("\nDa luu ket qua vao students_sorted.txt\n");

    return 0;
}