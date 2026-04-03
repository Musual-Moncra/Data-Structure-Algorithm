// Cau truc du lieu va Giai thuat - Tim dong xu gia
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168

#include <stdio.h>

int findFakeCoin(int coins[], int left, int right) {
   if (left == right) {
      return left;
   }

   int n = right - left + 1;
   int k = n / 3;
   if (n % 3 != 0 && n % 3 != 1) k++; 
   if (n % 3 == 1 && n > 1) k = n / 3;

   int group1_end = left + k - 1;
   int group2_start = left + k;
   int group2_end = left + 2 * k - 1;

   int weight1 = 0, weight2 = 0;
   int i;
   for (i = left; i <= group1_end; i++) weight1 += coins[i];
   for (i = group2_start; i <= group2_end; i++) weight2 += coins[i];

   if (weight1 < weight2) {
      return findFakeCoin(coins, left, group1_end);
   } else if (weight1 > weight2) {
      return findFakeCoin(coins, group2_start, group2_end);
   } else {
      return findFakeCoin(coins, group2_end + 1, right);
   }
}

int main() {
   int coins[] = {2, 2, 2, 2, 1, 2, 2, 2, 2}; // Dong xu gia nang 1, con lai nang 2
   int n = sizeof(coins) / sizeof(coins[0]);
   
   int index = findFakeCoin(coins, 0, n - 1);
   
   printf("Dong xu gia nam tai vi tri chi so: %d\n", index);
   printf("Gia tri cua dong xu do la: %d\n", coins[index]);

   return 0;
}
