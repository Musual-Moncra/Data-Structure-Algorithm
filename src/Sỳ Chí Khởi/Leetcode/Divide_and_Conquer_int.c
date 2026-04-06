// Cau truc du lieu va Giai thuat - Divide and Conquer (kiểu int)
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168
#include <stdio.h>

// Can cac dong xu va tra ve tong khoi luong
int weight(int coins[], int start, int end) {
   int sum = 0;
   for (int i = start; i < end; i++) {
      sum += coins[i];
   }
   return sum;
}

// Tim vi tri dong xu gia trong mang coins tu vi tri start den end
void fake_coin(int coins[], int start, int end) {
   // Chi co 1 dong xu duy nhat: tra ve index cua dong xu do
   if (start == end - 1) {
      printf("Fake coin may be at position %d\n", start);
      return;
   }
   
   int mid = (start + end) / 2;
   
   // Neu khoi luong 2 phan khac nhau, dong xu gia nam trong 2 phan nay
   if (weight(coins, start, mid) != weight(coins, mid, end)) {
      fake_coin(coins, start, mid);
      fake_coin(coins, mid, end);
   }
   return;
}

int main() {
   int n = 16;
   int coins[n];
   
   for (int i = 0; i < n; i++) {
      coins[i] = 10;
   }
   coins[3] = 9; // vi tri dong xu gia
   
   fake_coin(coins, 0, n);
   
   return 0;
}
