#include <stdio.h>

void xuatNguoc(int n) 
{  
    if (n == 0) 
	{
        return;
    }
    printf("%d", n % 10);
    xuatNguoc(n / 10);
}

int main() 
{
    int n;
    printf("Nhap n: "); 
    scanf("%d", &n);
    if (n == 0) 
	{
        printf("0");
    } 
	else 
	{
        xuatNguoc(n);
    }

    printf("\n");
    return 0;
}
