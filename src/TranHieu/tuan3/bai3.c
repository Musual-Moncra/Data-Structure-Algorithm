/*
Xác định số thao tác tính toán trong thuật toán tìm giá trị lớn nhất trong mảng các số
nguyên trong trường hợp tốt nhất (best case), xấu nhất (worst case), trung bình (average
case)
*/

#include <stdio.h>

int findMax(int a[], int n) {
    int max = a[0];    // (1) 1 phép gán
    long count = 1;    // Biến đếm thao tác
    
    for (int i = 1; i < n; i++) { // (2) n phép so sánh i<n, n-1 phép tăng i++
        count += 2;               // Đếm cho (i < n) và (i++)
        
        count++;                  // (3) 1 phép so sánh (a[i] > max)
        if (a[i] > max) {
            max = a[i];           // (4) 1 phép gán cập nhật max
            count++;
        }
    }
    count++; // Phép so sánh cuối cùng để thoát vòng lặp
    return max;
}

int main() {
    int n = 5;
    int a[] = {3, 2, 2, 1, 10}; // Mảng ví dụ

    printf("--- Bat dau tim Max ---\n");
    
    // Gọi hàm findMax mà bạn đã viết ở trên
    int max_val = findMax(a, n);

    printf("Gia tri lon nhat tim duoc la: %d\n", max_val);

    return 0;
}