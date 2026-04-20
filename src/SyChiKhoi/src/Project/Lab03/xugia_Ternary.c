// Cau truc du lieu va Giai thuat - Tim dong xu gia (Chia 3)
// Giang vien: Thay Vu Dinh Khoi
// Ma so sinh vien: 22502168

#include <stdio.h>

int findFakeCoin(int coins[], int left, int right) {
   if (left == right) {
      return left;
   }
   // chia 3 nhóm để trị
   int n = right - left + 1;    //số đồng xu
   int k = n / 3;               //mỗi nhóm có k xu
   
   if (n % 3 != 0 && n % 3 != 1) 
      k++; 
   if (n % 3 == 1 && n > 1) 
      k = n / 3;

   int group1_end = left + k - 1;
   int group2_start = left + k;
   int group2_end = left + 2 * k - 1;

   int weight1 = 0, weight2 = 0;
   int i;

   //tính trọng lượng của 2 nhóm
   for (i = left; i <= group1_end; i++) 
      weight1 += coins[i];
   for (i = group2_start; i <= group2_end; i++) 
      weight2 += coins[i];
   
   //so sánh trọng lượng của hai nhóm
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
   return 0;
}

/*dry-run
   -lần cân 1st:
      left=0 right=8
      n=8-0+1=9 
      k=9/3=3
......
lười chạy tiếp r~

*/
