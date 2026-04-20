#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

// Đếm số dòng trong file
int count_lines(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return 0; 
    int count = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') count++;
    }
    fclose(f); 
    return count;
}

// Lấy dữ liệu từ file ra mảng
void load_students(char *filename, struct Student students[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) return;
    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%d %s %f", &students[i].id, students[i].name, &students[i].gpa);
        i++;
    }
    fclose(f); 
}

// In danh sách sinh viên
void print_students(struct Student students[], int n) {
    printf("\n--- Danh sach sinh vien ---\n");
    printf("ID\t Name\t Score\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %s\t %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

// Binary Search theo ID
int binarySearchStudentById(struct Student students[], int n, int searchId) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].id == searchId) return mid;
        if (students[mid].id > searchId) right = mid - 1;
        else left = mid + 1;
    }
    return -1;
}

// Tuyến tính theo Tên (không phân biệt hoa/thường)
void searchStudentByName(struct Student students[], int n, const char* searchName) {
    char targetNameUpper[30];
    strcpy(targetNameUpper, searchName);
    strupr(targetNameUpper); 
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        char currentNameUpper[30];
        strcpy(currentNameUpper, students[i].name);
        strupr(currentNameUpper); 
        
        if (strcmp(currentNameUpper, targetNameUpper) == 0) {
            printf("ID: %d \t| NAME: %s \t| GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien nao ten '%s'\n", searchName);
    }
}

// Menu thực thi các thao tác tìm kiếm cho người dùng
void user_search_menu(struct Student students[], int n) {
    int filter_type;
    printf("\n--- Menu Tim Kiem ---\n");
    printf("1. Tim kiem theo ID\n");
    printf("2. Tim kiem theo Ten\n");
    printf("Moi chon (1 hoac 2): ");
    scanf("%d", &filter_type);
    
    if (filter_type == 1) {
        int id;
        printf("Nhap ID can tim: ");
        scanf("%d", &id);
        
        int index = binarySearchStudentById(students, n, id);
        if (index != -1) {
            printf("Found: ID: %d \t| NAME: %s \t| GPA: %.2f\n", students[index].id, students[index].name, students[index].gpa);
        } else {
            printf("Not found ID: %d\n", id);
        }
        
    } else if (filter_type == 2) {
        char name[30];
        printf("Nhap Ten can tim: ");
        scanf("%29s", name);
        printf("Result:\n");
        searchStudentByName(students, n, name);
    } else {
        printf("Lua chon khong hop le.\n");
    }
}

int main() {
    char *filename = "students.txt";
    int n = count_lines(filename);
    
    if (n == 0) {
        printf("Loi: File rong hoac khong ton tai!\n");
        return 1;
    }
    struct Student students[n];
    
    // a. Đọc dữ liệu sinh viên
    load_students(filename, students);
    
    // b. Hiện thị danh sách
    print_students(students, n);
    
    // c. Hỏi người dùng thao tác tìm kiếm
    user_search_menu(students, n);

    return 0;
}
