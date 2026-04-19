#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

// Hàm tìm kiếm mảng dữ liệu đã được mong chờ sắp xếp tăng dần 
// (Tại bài 2, danh sách ID từ 120 -> 129 vốn dĩ đã có thứ tự tăng dần rất lý tưởng cho thuật này)
int binarySearchStudentById(struct Student students[], int n, int searchId) {
    int left = 0;
    int right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (students[mid].id == searchId) {
            return mid;
        }
        if (students[mid].id > searchId) {
            right = mid - 1;
        } 
        else {
            left = mid + 1;
        }
    }
    return -1;
}

int main() {
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
    
    int searchId;
    printf("Nhap vao ID can tim: ");
    scanf("%d", &searchId);
    
    int index = binarySearchStudentById(students, n, searchId);
    
    if (index != -1) {
        printf("Tim thay sinh vien (BANG BINARY SEARCH):\n");
        printf("ID: %d, NAME: %s, GPA: %.2f\n", students[index].id, students[index].name, students[index].gpa);
    } else {
        printf("Not found\n");
    }

    return 0;
}
