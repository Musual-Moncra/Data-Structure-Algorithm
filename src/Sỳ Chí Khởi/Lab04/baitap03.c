#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

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
    
    char searchName[30];
    printf("Nhap vao ten can tim: ");
    scanf("%29s", searchName);
    
    // Tạo mảng phụ để lưu tên cần tìm đã viết hoa
    char targetNameUpper[30];
    strcpy(targetNameUpper, searchName);
    // Hàm _strupr dùng để chuyển chuỗi thành chữ hoa trong compiler của Windows.
    // Nếu bị warning, có thể dùng _strupr hoặc tự viết vòng lặp toupper.
    strupr(targetNameUpper); 
    
    int found = 0;
    for (int i = 0; i < n; i++) {
        char currentNameUpper[30];
        strcpy(currentNameUpper, students[i].name);
        // Chuyển tên học sinh hiện tại sang chữ hoa để so sánh không phân biệt hoa thường
        strupr(currentNameUpper); 
        
        // Sử dụng strcmp để so sánh 2 chuỗi đã viết hoa
        if (strcmp(currentNameUpper, targetNameUpper) == 0) {
            if (!found) {
                printf("Tim thay sinh vien:\n");
            }
            printf("ID: %d, NAME: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            found = 1;
            // Không có break ở đây vì có thể có nhiều sinh viên trùng tên
        }
    }
    
    if (!found) {
        printf("Not found\n");
    }

    return 0;
}
