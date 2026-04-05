// Cau truc du lieu va Giai thuat
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168
#include <stdio.h>

void doiTien(int coins[], int n, int money) {
    int i;
    printf("Cac to tien duoc chon: ");
    for (i = 0; i < n; i++) {
        while (money >= coins[i]) {
            money -= coins[i];
            printf("%d ", coins[i]);
        }
    }
    printf("\n");
}

int main() {
    int coins[] = {10, 5, 2, 1}; // Menh gia phai sap xep giam dan
    int n = sizeof(coins) / sizeof(coins[0]);
    int money = 18;
    
    doiTien(coins, n, money);
    
    return 0;
}
