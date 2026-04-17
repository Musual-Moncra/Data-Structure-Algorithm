/*
Kết hợp các bài tập 1, 2, 3, 4 viết chương trình:
a. Đọc dữ liệu sinh viên từ tập tin students.txt
b. Hiển thị danh sách sinh viên ra màn hình
c. Hỏi người dùng nhập thông tin cần tìm kiếm như id hoặc name và giá trị cần tìm như
123 hoặc Thanh → hiển thị chi tiết thông tin sinh viên tìm thấy
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // Thư viện để dùng hàm toupper

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

int loadStudents(Student students[]) {
    FILE *f = fopen("src/TranHieu/tuan4/students.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong tim thay file students.txt!\n");
        return 0;
    }

    int count = 0;
    while (fscanf(f, "%d %s %f", &students[count].id, students[count].name, &students[count].grade) == 3) {
        count++;
    }
    fclose(f);
    return count;
}

void displayStudents(Student students[], int n) {
    printf("\n%-10s %-15s %-10s\n", "MSSV", "Ho Ten", "Diem");
    printf("---------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-15s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

// c. Hàm tìm kiếm và hiển thị chi tiết
void searchStudent(Student students[], int n) {
    int choice;
    printf("\nChon kieu tim kiem (1: Theo ID, 2: Theo Ten): ");
    scanf("%d", &choice);

    int found = 0;
    if (choice == 1) {
        int searchId;
        printf("Nhap ID can tim: ");
        scanf("%d", &searchId);
        for (int i = 0; i < n; i++) {
            if (students[i].id == searchId) {
                printf("Tim thay: ID: %d, Ten: %s, Diem: %.2f\n", students[i].id, students[i].name, students[i].grade);
                found = 1;
                break;
            }
        }
    } else if (choice == 2) {
        char searchName[50];
        printf("Nhap Ten can tim: ");
        scanf("%s", searchName);
        strcpy(tempSearch, searchName);
        toUpperCase(tempSearch);
        strcpy(tempStudent, students[i].name);
        toUpperCase(tempStudent);
        for (int i = 0; i < n; i++) {
            if (strcmp(tempStudent, tempSearch) == 0) { // So sánh chuỗi
                printf("Tim thay: ID: %d, Ten: %s, Diem: %.2f\n", students[i].id, students[i].name, students[i].grade);
                found = 1;
            }
        }
    }

    if (!found) printf("Rat tiec, khong tim thay sinh vien nay!\n");
}

int main() {
    Student list[100];
    int n = loadStudents(list);

    if (n > 0) {
        displayStudents(list, n);
        searchStudent(list, n);
    }

    return 0;
}