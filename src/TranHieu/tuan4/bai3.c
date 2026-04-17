/*
Viết chương trình cho phép người dùng nhập vào tên sinh viên (name) bất kỳ và tìm kiếm
trong danh sách sinh viên, nếu tìm thấy → in ra đầy đủ thông tin tất cả các sinh viên, nếu
không tìm thấy → in ra “Not found”.
Hint: sử dụng hàm strcmp(), strupr() của thư viện string.h để so sánh 2 chuỗi ký tự.
*/

#include <stdio.h>
#include <string.h>

typedef struct Student 
{
    int id;
    char name[30];
    float score;
} Sdt;

void nhap(Sdt *students, int n)
{
    for (int i = 0; i < n; i++) 
    {
        students[i].id = i + 1;
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin); // Xóa bộ nhớ đệm để không bị trôi lệnh nhập chuỗi
        gets(students[i].name); // Dùng gets để nhận cả khoảng trắng
        printf("Nhap diem sinh vien thu %d: ", i + 1);
        scanf("%f", &students[i].score);
    }
}

void in(Sdt *students, int n)
{
    printf("\n--- DANH SACH SINH VIEN ---\n");
    for (int i = 0; i < n; i++) {
        printf("ID: %d\t, Name: %s\t, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

void tim(Sdt *students, int n)
{
    char searchName[50];
    char tempName[50]; 
    int found = 0;

    printf("\nNhap ten sinh vien can tim: ");
    fflush(stdin);
    gets(searchName); 

    // Chuẩn hóa tên cần tìm sang chữ HOA
    strupr(searchName);

    for (int i = 0; i < n; i++) {
        // Copy tên từ danh sách ra biến tạm để không làm hỏng tên gốc
        strcpy(tempName, students[i].name);
        // Viết hoa tên trong biến tạm
        strupr(tempName);

        if (strcmp(tempName, searchName) == 0) {
            printf("Found -> ID: %d, Name: %s, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
            found = 1; 
        }
    }

    if (found == 0) {
        printf("Not found\n");
    }
}

int main() {
    int n; 
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);

    Sdt students[n]; 
    nhap(students, n);
    in(students, n);
    tim(students, n);

    return 0;
}