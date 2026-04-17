#include <stdio.h>

int check(int n) 
{
	if ( n < 2 ) {
		return 0;
	}
	return ( n% 10 + check(n/10));
}

int main() 
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	if ( n == 0 ) printf("Sum=0");
	else 
	{
		int kq = check(n);
		printf("Sum = %d ",kq);
	}
	return 0;
}

