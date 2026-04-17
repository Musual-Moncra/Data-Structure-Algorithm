/*
Viết chương trình cho phép người dùng nhập vào mã số sinh viên (id) và tìm kiếm trong
danh sách sinh viên, nếu tìm thấy → in ra đầy đủ thông tin sinh viên, nếu không tìm thấy →
in ra “Not found”.
Hint: sử dụng Binary search (vì id đã được sắp xếp)
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
        fflush(stdin); 
        gets(students[i].name);
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
    int searchId;
    printf("\nNhap MA SO SINH VIEN (ID) can tim: ");
    scanf("%d", &searchId);

    int left = 0;
    int right = n - 1;
    int found = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Tìm vị trí ở giữa

        // Nếu tìm thấy ngay ở giữa
        if (students[mid].id == searchId) {
            printf("Found -> ID: %d, Name: %s, Score: %.2f\n", 
                    students[mid].id, students[mid].name, students[mid].score);
            found = 1;
            break;
        }

        // Nếu ID cần tìm lớn hơn ID ở giữa, bỏ qua nửa bên trái
        if (students[mid].id < searchId) {
            left = mid + 1;
        }
        // Nếu ID cần tìm nhỏ hơn ID ở giữa, bỏ qua nửa bên phải
        else {
            right = mid - 1;
        }
    }

    if (found == 0) {
        printf("Not found\n");
    }
}

int main() {
    int n; 
    printf("Nhap so luong sinh vien: ");
    if (scanf("%d", &n) != 1 || n <= 0) return 0;
    Sdt students[n]; 
    nhap(students, n);
    in(students, n);
    tim(students, n);

    return 0;
}

/*
    Ghi chú: So sánh Linear Search & Binary Search
    1. Linear Search (Tìm kiếm tuyến tính)
        - Nguyên lý: "Quét" từ đầu đến cuối mảng. Gặp phần tử khớp thì dừng lại.
        - Điều kiện: Mảng không cần sắp xếp.
        - Độ phức tạp (O): O(n).
        - Khi nào dùng:
            + Mảng nhỏ, dữ liệu lộn xộn.
            + Chỉ tìm kiếm 1-2 lần rồi thôi.
            + Tìm theo các tiêu chí không sắp xếp được (ví dụ: tìm người có sở thích là "chơi game").
    2. Binary Search (Tìm kiếm nhị phân)
        - Nguyên lý: "Chia để trị". Luôn kiểm tra phần tử ở giữa, nếu không phải thì bỏ đi một nửa mảng và lặp lại.
        - Điều kiện: Mảng bắt buộc phải được sắp xếp (ví dụ: ID tăng dần).
        - Độ phức tạp (O): O(log n).
        - Khi nào dùng:
            + Mảng lớn (hàng nghìn đến hàng triệu phần tử).
            + Dữ liệu ít thay đổi nhưng cần tìm kiếm rất nhiều lần.
            + Tìm kiếm theo các khóa định danh như ID, Mã số sinh viên, Số điện thoại.
*/