#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Bài tập 2: Thuật toán chọn trực tiếp sắp xếp tăng dần theo cột tên
void selectionSortByNameAsc(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // So sánh chuỗi tăng dần
            if (strcmp(students[j].name, students[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            struct Student temp = students[i];
            students[i] = students[min_idx];
            students[min_idx] = temp;
        }
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
    
    selectionSortByNameAsc(students, n);
    
    printf("\n--- Danh sach sau khi sap xep (Selection Sort - Ten tang dan) ---\n");
    print_students(students, n);
    
    return 0;
}
