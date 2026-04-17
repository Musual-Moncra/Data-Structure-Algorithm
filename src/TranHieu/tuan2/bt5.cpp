#include <stdio.h>

void chuyen(int n, int cap)
{
	if ( n == 0 )
	{
		return ;
	}
	else 
	{
		chuyen(n/60, cap ++);
	}
	printf("%d",n%60);
	if ( cap == 1 ) printf("giay ");
	else if ( cap==2 ) printf("phut ");
	else if ( cap==3 ) printf("gio ");
}

int main()
{
	int n;
	printf("Nhap n: ");
	scanf("%d",&n);
	if ( n ==0 )
		printf("0 giay");
	else
		chuyen(n,1);
	return 0;
}
