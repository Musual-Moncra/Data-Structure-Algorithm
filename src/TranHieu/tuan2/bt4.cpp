#include <stdio.h>

void chuyen(int n)
{
	if ( n == 0 )
	{
		return ;
	}
	else 
	{
		chuyen(n/2);
	}
	printf("%d",n%2);
}

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	if ( n ==0 )
		printf("0");
	else
		chuyen(n);
	return 0;
}
