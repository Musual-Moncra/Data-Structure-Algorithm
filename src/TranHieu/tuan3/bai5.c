/*
Viết chương trình xác định 4 số nguyên dương có khác biệt hay không.
Trường hợp tốt nhất (best case) và xấu nhất (worst case) cần bao nhiêu phép toán/thao tác
so sánh?
Ví dụ: 5, 8, 2, 7 là các số nguyên khác biệt
*/

#include <stdio.h>

// Hàm kiểm tra 4 số có khác biệt không
// Trả về 1 nếu khác biệt, 0 nếu có số trùng
int isDistinct(int a, int b, int c, int d, int *ops) {
    *ops = 0;

    // Cặp 1: a vs b
    (*ops)++;
    if (a == b) return 0;

    // Cặp 2: a vs c
    (*ops)++;
    if (a == c) return 0;

    // Cặp 3: a vs d
    (*ops)++;
    if (a == d) return 0;

    // Cặp 4: b vs c
    (*ops)++;
    if (b == c) return 0;

    // Cặp 5: b vs d
    (*ops)++;
    if (b == d) return 0;

    // Cặp 6: c vs d
    (*ops)++;
    if (c == d) return 0;

    return 1; // Tất cả đều khác nhau
}

int main() {
    int a, b, c, d, operations;
    printf("Nhap 4 so nguyen duong: ");
    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (isDistinct(a, b, c, d, &operations)) {
        printf("Ket qua: Cac so KHAC BIET.\n");
    } else {
        printf("Ket qua: Co so TRUNG NHAU.\n");
    }

    printf("So thao tac so sanh da thuc hien: %d\n", operations);

    return 0;
}