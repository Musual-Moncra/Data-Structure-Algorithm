#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

struct Student {
    int id;
    char name[30];
    float score;
};

// Hàm đọc file: Dừng khi không thể đọc đủ 3 trường dữ liệu
int load_students(char *filename, struct Student students[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return 0;
    int i = 0;
    while (fscanf(f, "%d %s %f", &students[i].id, students[i].name, &students[i].score) == 3) {
        i++;
    }
    fclose(f); 
    return i;
}

// In danh sách sinh viên
void print_students(struct Student students[], int n) {
    printf("ID\t Name\t Score\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %s\t %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

// Bài tập 1: Sắp xếp theo thứ tự giảm dần của điểm bằng Bubble Sort
void bubbleSortByScoreDesc(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].score < students[j + 1].score) {
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

int main() {
    struct Student students[100];
    int n = load_students("../../../resources/students_Lab05.txt", students);
    
    if (n == 0) {
        printf("Loi: File rong hoac khong ton tai!\n");
        return 1;
    }
    
    printf("--- Danh sach truoc khi sap xep ---\n");
    print_students(students, n);
    
    bubbleSortByScoreDesc(students, n);
    
    printf("\n--- Danh sach sau khi sap xep (Bubble Sort - Diem giam dan) ---\n");
    print_students(students, n);
    
    return 0;
}
