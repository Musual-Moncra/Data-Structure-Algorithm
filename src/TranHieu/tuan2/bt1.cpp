#include <stdio.h>

void chay(int n)
{
	if ( n == 0 )
	{
		return ;
	}
	else 
	{
		chay(n-1);
	}
	printf("* ");
}

int main()
{
	int n = 6;
	chay(n);
	return 0;
}
