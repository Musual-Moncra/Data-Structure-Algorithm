/*
Cho cấu trúc file students.txt
(lưu ý: tên chỉ gồm 1 từ, các cột thông tin cách nhau khoảng trắng).
123 Binh 7.50
124 An 7.50
125 Khoa 8.50
126 Thanh 9.50
127 Nguyen 5.50
128 Mai 6.70
129 Hung 7.30
130 Viet 5.90
Viết chương trình đọc thông tin sinh viên từ tập tin students.txt và sử dụng Bubble sort
để sắp xếp danh sách sinh viên theo thứ tự giảm dần của cột điểm (score) và xuất ra màn
hình kết quả sau khi sắp xếp.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

int loadStudents(Student students[]) {
    FILE *f = fopen("src/TranHieu/tuan5/students.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong tim thay file students.txt!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(f, "%d %s %f", &students[count].id, students[count].name, &students[count].grade) == 3) {
        count++;
    }
    fclose(f);
    return count;// đếm số lượng sinh viên
}

void displayStudents(Student students[], int n) {
    printf("\n%-10s %-15s %-10s\n", "MSSV", "Ho Ten", "Diem");
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

void bubbleSort(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {// or for (int j = n - 1; j > i; j--) {
            if (students[j].grade < students[j + 1].grade) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    Student list[100];
    int n = loadStudents(list);

    if (n > 0) {
        displayStudents(list, n);
        bubbleSort(list, n);
        displayStudents(list, n);
    }

    return 0;
}