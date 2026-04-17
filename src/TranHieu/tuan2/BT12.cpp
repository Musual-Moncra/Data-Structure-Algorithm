#include <stdio.h>

long tinhTong(int n) 
{
    if (n == 0) 
	{
        return 0;
    }
    return n + tinhTong(n - 1);
}

int main() 
{
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    if (n < 0) 
	{
        printf("Vui long nhap n >= 0\n");
    } 
	else 
	{
        long kq = tinhTong(n);
        printf("Tong tu 1 den %d la: %ld\n", n, kq);
    }
    return 0;
}
