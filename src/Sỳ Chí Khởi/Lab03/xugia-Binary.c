// Cau truc du lieu va Giai thuat - Tim dong xu gia (Chia 2)
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168

#include <stdio.h>

int findFakeCoin(int coins[], int left, int right) {
   // Truong hop co so: Chi con 1 dong xu
   if (left == right) {
      return left;
   }

   int n = right - left + 1;
   int mid = left + (right - left) / 2;
   int weight1 = 0, weight2 = 0;
   int i;

   // case 1: So luong dong xu la CHAN
   if (n % 2 == 0) {
      for (i = left; i <= mid; i++) weight1 += coins[i];
      for (i = mid + 1; i <= right; i++) weight2 += coins[i];

      if (weight1 < weight2) {
         return findFakeCoin(coins, left, mid);
      } else {
         return findFakeCoin(coins, mid + 1, right);
      }
   } 
   // case 2: So luong dong xu la LE
   else {
      for (i = left; i < mid; i++) weight1 += coins[i];
      for (i = mid + 1; i <= right; i++) weight2 += coins[i];

      if (weight1 == weight2) {
         return mid;
      } else if (weight1 < weight2) {
         return findFakeCoin(coins, left, mid - 1);
      } else {
         return findFakeCoin(coins, mid + 1, right);
      }
   }
}

int main() {
   int coins[] = {2, 2, 2, 2, 1, 2, 2, 2, 2};
   int n = sizeof(coins) / sizeof(coins[0]);
   
   int index = findFakeCoin(coins, 0, n - 1);
   
   printf("Dong xu gia nam tai vi tri chi so: %d\n", index);
   return 0;
}
