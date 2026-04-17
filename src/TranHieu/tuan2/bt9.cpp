#include <stdio.h>

int check(long long n) 
{
	if ( n < 10 ) {
		return 1;
	}
	return ( 1 + check (n/10));
}

int main() 
{
	long long  n;
	printf("Nhap n: ");	
	scanf("%lld",&n);
	if ( n<0 ) n = -n; 
	else 
	{
		int kq = check(n);
		printf("So phan tu : %d",kq);
	}
	return 0;
}

