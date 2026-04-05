/*
Xác định số thao tác tính toán trong thuật toán tìm một số x (có xuất hiện hay không?) trong
mảng các số nguyên trong trường hợp tốt nhất (best case), xấu nhất (worst case), trung bình
(average case)
*/

/*
1. Quy tắc "Một hàm - Một kết quả" trong C:
-Một hàm thông thường chỉ có thể sử dụng lệnh return để trả về duy nhất một giá trị.
2. Phân tích Bài 3 (Truyền tham trị - Pass by Value):
-Mục tiêu: Hàm tìm Max chỉ cần trả về đúng một thông tin duy nhất (giá trị lớn nhất).
-Cách làm: Sử dụng biến thường và lệnh return. Máy tính sẽ tạo ra một "bản sao" của biến để tính toán 
trong hàm. Khi hàm kết thúc, bản sao này bị hủy, chỉ có giá trị được return là được giữ lại.
3. Phân tích Bài 4 (Truyền tham chiếu - Pass by Reference):
-Mục tiêu: Hàm tìm kiếm x cần báo cáo cùng lúc hai kết quả:
    Vị trí tìm thấy số x (trả về kiểu int qua return).
    Tổng số thao tác tính toán (trả về kiểu long qua Con trỏ).
-Cách làm: Vì không thể return hai lần, ta đưa cho hàm cái "địa chỉ" của biến operations ở hàm main 
thông qua con trỏ *ops.
-Kết quả: Nhờ nắm giữ địa chỉ, hàm có thể thay đổi trực tiếp giá trị của biến gốc ở main. 
Khi hàm kết thúc, biến ở main đã tự động cập nhật số thao tác mà không cần lệnh return.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Hàm tìm kiếm x và đếm số thao tác
int linearSearch(int a[], int n, int x, long *ops) {
    *ops = 0; // Khởi tạo biến đếm
    
    // (1) Khởi tạo i = 0 (1 phép gán)
    (*ops)++; 
    for (int i = 0; i < n; i++) {
        // (2) So sánh i < n (mỗi vòng lặp 1 lần)
        (*ops)++; 
        
        // (3) So sánh a[i] == x (mỗi vòng lặp 1 lần)
        (*ops)++; 
        if (a[i] == x) {
            return i; // Tìm thấy, thoát hàm ngay lập tức
        }
        
        // (4) Tăng i++ (mỗi vòng lặp 1 lần)
        (*ops)++; 
    }
    
    // Phép so sánh i < n cuối cùng khi thoát vòng lặp
    (*ops)++; 
    return -1; // Không tìm thấy
}

int main() {
    int n = 10;
    int a[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    long operations;
    int x;

    printf("Mang hien tai: ");
    for(int i=0; i<n; i++) printf("%d ", a[i]);
    
    printf("\n\nNhap so x can tim: ");
    scanf("%d", &x);

    int index = linearSearch(a, n, x, &operations);

    if (index != -1)
        printf("Tim thay %d tai vi tri: %d\n", x, index);
    else
        printf("Khong tim thay %d trong mang.\n", x);

    printf("Tong so thao tac tinh toan: %ld\n", operations);

    return 0;
}


