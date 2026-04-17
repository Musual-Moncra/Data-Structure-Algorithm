/*
Sử dụng thuật toán Chọn trực tiếp (Selection sort), viết thêm hàm sắp xếp danh sách sinh
viên theo thứ tự tăng dần của cột tên (name) và xuất ra màn hình kết quả sau khi sắp xếp
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

// Hàm sắp xếp Chọn trực tiếp (Selection Sort) theo tên
void selectionSortByName(Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Giả sử vị trí i là vị trí của phần tử nhỏ nhất
        int min_idx = i;
        
        for (int j = i + 1; j < n; j++) {
            // So sánh tên sinh viên (thứ tự từ điển)
            if (ds[j].name < ds[min_idx].name) {
                min_idx = j;
            }
        }
        
        // Hoán đổi phần tử nhỏ nhất tìm thấy với phần tử tại vị trí i
        if (min_idx != i) {// Nếu sau khi đi kiểm tra một vòng, tôi tìm thấy một người khác (min_idx) nhỏ hơn người ban đầu ở vị trí i thì hoán đổi
            swap(students[i], students[min_idx]);
            /* or hoặc lấy cái dưới cx được
            Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            */
        }
    }
}

int main() {
    Student list[100];
    int n = loadStudents(list);

    if (n > 0) {
        displayStudents(list, n);
        selectionSortByName(list, n);
        displayStudents(list, n);
    }

    return 0;
}