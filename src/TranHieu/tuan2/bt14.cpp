#include <stdio.h>

int tinhTongMang(int a[], int n) 
{
    if (n <= 0) 
	{
        return 0;
    }
    
    // 2. Buoc de quy: Lay phan tu cuoi + tong cua (n-1) phan tu truoc
    return a[n - 1] + tinhTongMang(a, n - 1);
}

int main() 
{
    int a[] = {1, 2, 5};
    int n = sizeof(a) / sizeof(a[0]); 
    int tong = tinhTongMang(a, n);
    printf("Tong cac phan tu trong mang la: %d\n", tong);
    return 0;
}
