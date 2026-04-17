#include <stdio.h>

int check(long long n) 
{
	int count = 0;
	if (n == 0) 
	{
        count = 1;
    } 
	else 
	{
        if (n < 0) n = -n;
	}
	while ( n > 0)
	{
		n/=10;
		count++;
	}
	return count;
}

int main() 
{
	long long  n;
	printf("Nhap n: ");	
	scanf("%lld",&n);
	int kq = check(n);
	printf("So phan tu : %d",kq);
	return 0;
}

