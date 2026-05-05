// Cau truc du lieu va Giai thuat - Greedy Algorithm
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168

#include <stdio.h>

void demtien(int money, int notes[]) {
    int quantity = 0;
    int i = 0;
    while (money > 0) {
        quantity = money / notes[i];
        if (quantity > 0) printf("%d note(s) of %d\n", quantity, notes[i]);
        money = money % notes[i];
        i++;
    }
}

int main() {
    int notes[] = {10, 5, 2, 1}; // phai sap xep giam dan
    int money = 18;
    
    printf("So tien can doi: %d\n", money);
    printf("Ket qua:\n");
    demtien(money, notes);
    
    return 0;
}
