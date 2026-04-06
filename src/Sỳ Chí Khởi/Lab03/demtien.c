// Cau truc du lieu va Giai thuat
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168
#include <stdio.h>

void doiTien(int A[], int n, int money) {
    int i;
    printf("Cac to tien duoc chon: ");
    for (i = 0; i < n; i++) {
        while (money >= A[i]) {
            money -= A[i];
            printf("%d ", A[i]);
        }
    }
    printf("\n");
}

int main() {
    int A[] = {10, 5, 2, 1}; // Menh gia phai sap xep giam dan
    int n = sizeof(A) / sizeof(A[0]);
    int money = 18;
    
    doiTien(A, n, money);
    
    return 0;
}
