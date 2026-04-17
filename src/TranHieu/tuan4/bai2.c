/*
    Viết chương trình cho phép người dùng nhập vào Mã số sinh viên (ID) bất kỳ và tìm kiếm
trong danh sách sinh viên, nếu tìm thấy → in ra đầy đủ thông tin sinh viên, nếu không tìm
thấy → in ra “Not found”.
*/

#include <stdio.h>
typedef struct Student 
{
    int id;
    char name[30];
    float score;
} Sdt;

void nhap(Sdt *students, int n)
{
    printf("ID: \t, Name: \t, Score:\n")

    for (int i = 0; i < n; i++) 
    {
        students[i].id = i + 1;
        printf("Nhap ten sinh vien thu %d: ", i + 1);
        fflush(stdin);
        fgets(students[i].name, sizeof(students[i].name), stdin);
        printf("Nhap diem sinh vien thu %d: ", i + 1);
        scanf("%f", &students[i].score);
    }
}

void in(Sdt *students, int n)
{
    for (int i = 0; i < n; i++) {
        printf("ID: %d\t, Name: %s\t, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

void tim(Sdt *students, int n)
{
    int id;
    printf("Nhap ID can tim: ");
    scanf("%d", &id);
    for (int i = 0; i < n; i++) {
        if (students[i].id == id) {
            printf("FOUND -> ID: %d\t, Name: %s\t, Score: %.2f\n", students[i].id, students[i].name, students[i].score);
            return;
        }
    }
    printf("Not found\n");
}

int main() 
{
    int n; 
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    Sdt students[n];
    nhap(students, n);
    /*
        sdt students[5] = 
        {
            {1, "Tran", 9.0},
            {2, "Hieu", 8.0},
            {3, "Nguyen", 7.0},
            {4, "Van", 6.0},
            {5, "A", 5.0}
        };
        int n = sizeof(students) / sizeof(students[0]);//students ở đây là mảng
        in(students, n);
        tim(students, n);
    */
    return 0;
}
