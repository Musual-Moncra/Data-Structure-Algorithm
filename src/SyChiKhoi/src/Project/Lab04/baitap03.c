#include <stdio.h>
#include <string.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

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
            if (!found) {
                printf("Tim thay sinh vien:\n");
            }
            printf("ID: %d, NAME: %s, GPA: %.2f\n", students[i].id, students[i].name, students[i].gpa);
            found = 1;
        }
    }
    
    if (!found) {
        printf("Not found\n");
    }
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
    
    char searchName[30];
    printf("Nhap vao ten can tim: ");
    scanf("%29s", searchName);
    searchStudentByName(students, n, searchName);

    return 0;
}

/* ==============================================================================
   GIẢI THÍCH CHI TIẾT LOGIC TÌM KIẾM SINH VIÊN THEO TÊN
   ==============================================================================
   Về hàm searchStudentByName():
   - Lý do ép kiểu chữ HOA (strupr): Để xử lý triệt để việc tìm kiếm không phân biệt
     chữ thường/chữ hoa (Ví dụ: "BINH" vẫn match với "BiNH"). Ta ép cả từ khóa tìm
     kiếm lẫn tên đang soi trong mảng lên IN HOA hết rồi mới đem đi so cho sòng phẳng.
   - Hàm sao chép (strcpy): Mảng (Array) không thể gán trực tiếp bằng dấu bằng (=)
     được (như int a = b), nên ta phải nhờ strcpy nháy lại data ra biến trung gian
     để ép hoa mà không làm hư tên gốc của sinh viên trong cấu trúc struct.
   - Vòng lặp For: Khác với Binary Search chặn đầu chặt đuôi, vòng lặp này bắt buộc 
     phải rà soát từng ô một. Khi thấy (strcmp == 0), bật cờ found = 1.
   - Không có Break: Lệnh Break không được xuất hiện trong vòng if vì biết đâu 
     trong lớp có tới 2, 3 người cùng tên "Binh". Ta phải tiếp tục lùng sục tới 
     tận cuối danh sách để in ra hết bọn họ!
================================================================================= */
