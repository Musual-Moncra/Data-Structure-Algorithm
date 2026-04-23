#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

struct Student {
    int id;
    char name[30];
    float score;
};

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

void print_students(struct Student students[], int n) {
    printf("ID\t Name\t Score\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %s\t %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

// Hàm so sánh 2 sinh viên (Tên tăng dần không phân biệt hoa thường, điểm giảm dần)
int compareStudents(struct Student a, struct Student b) {
    char nameA[30], nameB[30];
    strcpy(nameA, a.name);
    strcpy(nameB, b.name);
    
    // Chuyển toàn bộ về chữ thường để so sánh không phân biệt hoa/thường
    for(int i = 0; nameA[i]; i++) nameA[i] = tolower(nameA[i]);
    for(int i = 0; nameB[i]; i++) nameB[i] = tolower(nameB[i]);
    
    int cmp = strcmp(nameA, nameB);
    if (cmp != 0) {
        return cmp; // cmp < 0 nghĩa là a đứng trước b (Tên tăng dần)
    } else {
        // Tên giống nhau -> So sánh điểm giảm dần
        if (a.score < b.score) return 1;    // a đứng sau b (Điểm giảm dần)
        if (a.score > b.score) return -1;   // a đứng trước b
        return 0;
    }
}

// Bài tập 3: Sắp xếp danh sách với tiêu chí kết hợp (sử dụng Insertion Sort)
void customSort(struct Student students[], int n) {
    for (int i = 1; i < n; i++) {
        struct Student key = students[i];
        int j = i - 1;
        
        // Điều kiện: nếu students[j] lớn hơn key (theo hàm so sánh)
        while (j >= 0 && compareStudents(students[j], key) > 0) {
            students[j + 1] = students[j];
            j = j - 1;
        }
        students[j + 1] = key;
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
    
    customSort(students, n);
    
    printf("\n--- Danh sach sau khi sap xep (Ten tang dan ignore-case, trung thi Diem giam dan) ---\n");
    print_students(students, n);
    
    return 0;
}
