/*
Định nghĩa cấu trúc Student gồm các thông tin cơ bản sau:
- id: kiểu số nguyên
- name: mảng 30 ký tự (để đơn giản, tên chỉ gồm 1 từ như Thanh, Hoa…)
- score: kiểu float
Viết chương trình khởi tạo cố định (lưu ý ID tăng dần) và in ra danh sách các sinh viên
*/

#include <stdio.h>
typedef struct Student 
{
    int id;
    char name[30];
    float score;
} Sdt;

int main() 
{
    int n; 
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    Sdt students[n];
    for (int i = 0; i < n; i++) 
    {
        students[i].id = i + 1;
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Nhap diem sinh vien thu %d: ", i + 1);
        scanf("%f", &students[i].score);
    }
    printf("ID: \t, Name: \t, Score:\n")
    /*
        sdt students[5] = 
        {
            {1, "Tran", 9.0},
            {2, "Hieu", 8.0},
            {3, "Nguyen", 7.0},
            {4, "Van", 6.0},
            {5, "A", 5.0}
        };
    */
    for (int i = 0; i < n; i++) {
        printf("ID: %d\t, Name: %s\t, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    return 0;
}
