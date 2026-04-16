#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

int main() {
    // Khởi tạo cố định mảng danh sách sinh viên
    struct Student students[] = {
        {120, "Binh", 7.50},
        {121, "An", 7.50},
        {122, "Khoa", 8.50},
        {123, "Thanh", 9.50},
        {124, "Nguyen", 5.50},
        {125, "Mai", 6.70},
        {126, "Hung", 7.30},
        {127, "Viet", 5.90},
        {128, "BiNH", 8.00},
        {129, "Phong", 6.70}
    };
    int n = sizeof(students) / sizeof(students[0]);

    // In danh sách sinh viên
    printf("Student list:\n");
    printf("ID\tNAME\tGPA\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%.2f\n", students[i].id, students[i].name, students[i].gpa);
    }

    return 0;
}
