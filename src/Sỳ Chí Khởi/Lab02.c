// Cau truc du lieu va Giai thuat - Lab 02: De quy
// Giang vien: Thay Vu Dinh Khoi
// Sy Chi Khoi-22502168

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void bai1(int n) {
   if (n <= 0) return;
   printf("*");
   bai1(n - 1);
}

void bai2(int n) {
   int i;
   if (n <= 0) return;
   bai2(n - 1);
   for (i = 0; i < n; i++) printf("*");
   printf("\n");
}

void bai3(int n) {
   int i;
   if (n <= 0) return;
   for (i = 0; i < n; i++) printf("*");
   printf("\n");
   bai3(n - 1);
}

void bai4(int n) {
   if (n == 0) return;
   bai4(n / 2);
   printf("%d", n % 2);
}

void bai5(int s, int step) {
   if (step == 1) {
      printf("%d gio ", s / 3600);
      bai5(s % 3600, 2);
   } else if (step == 2) {
      printf("%d phut ", s / 60);
      bai5(s % 60, 3);
   } else if (step == 3) {
      printf("%d giay\n", s);
   }
}

bool bai6(int n, int i) {
   if (n <= 2) return n == 2;
   if (n % i == 0) return false;
   if (i * i > n) return true;
   return bai6(n, i + 1);
}

int bai7(int n) {
   if (n == 0) return 0;
   return (n % 10) + bai7(n / 10);
}

void bai8(int n) {
   if (n == 0) return;
   printf("%d", n % 10);
   bai8(n / 10);
}

int bai9(int n) {
   if (n < 10) return 1;
   return 1 + bai9(n / 10);
}

int bai10(int n) {
   int count = 0;
   if (n == 0) return 1;
   while (n > 0) {
      count++;
      n /= 10;
   }
   return count;
}

int bai11(int a[], int n) {
   int min;
   if (n == 1) return a[0];
   min = bai11(a, n - 1);
   return a[n - 1] < min ? a[n - 1] : min;
}

int bai12(int n) {
   if (n == 0) return 0;
   return n + bai12(n - 1);
}

bool bai13(char s[], int l, int r) {
   if (l >= r) return true;
   if (s[l] != s[r]) return false;
   return bai13(s, l + 1, r - 1);
}

int bai14(int a[], int n) {
   if (n == 0) return 0;
   return a[n - 1] + bai14(a, n - 1);
}

int bai15(int a[], int n) {
   int max;
   if (n == 1) return a[0];
   max = bai15(a, n - 1);
   return a[n - 1] > max ? a[n - 1] : max;
}

int main() {
   int na, n = 1980;
   int a[] = {1, 2, 5, -3, 8};
   int b[] = {1, 2, 5};
   char str[] = "radar";

   printf("Bai 1 (n=6): ");
   bai1(6);
   
   printf("\n\nBai 2 (n=6):\n");
   bai2(6);
   
   printf("\nBai 3 (n=6):\n");
   bai3(6);
   
   printf("\nBai 4 (n=13): ");
   if(13 == 0) printf("0"); else bai4(13);
   
   printf("\n\nBai 5 (3665s): ");
   bai5(3665, 1);
   
   printf("\nBai 6 (n=17): %s\n", bai6(17, 2) ? "La so nguyen to" : "Khong la so nguyen to");
   
   printf("\nBai 7 (n=1980): %d\n", bai7(1980));
   
   printf("\nBai 8 (n=1980): ");
   if(1980 == 0) printf("0"); else bai8(1980);
   
   printf("\n\nBai 9 (n=44253): %d\n", bai9(44253));
   
   printf("\nBai 10 (n=44253): %d\n", bai10(44253));
   
   na = sizeof(a) / sizeof(a[0]);
   printf("\nBai 11 (Min cua mang a): %d\n", bai11(a, na));
   
   printf("\nBai 12 (n=5): %d\n", bai12(5));
   
   printf("\nBai 13 (chuoi 'radar'): %s\n", bai13(str, 0, strlen(str) - 1) ? "Palindrome" : "Khong phai palindrome");
   
   printf("\nBai 14 (Tong mang b = {1, 2, 5}): %d\n", bai14(b, 3));
   
   printf("\nBai 15 (Max cua mang a): %d\n", bai15(a, na));

   return 0;
}
