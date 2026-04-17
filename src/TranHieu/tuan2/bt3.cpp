#include <stdio.h>

void insao(int n)
{
	if ( n == 0 )
	{
		return ;
	}
	else 
	{
		insao(n-1);
	}
	printf("* ");
}

void intamgiac(int n)
{
	if ( n == 0 )
	{
		return ;
	}
	insao(n);
	printf("\n");
	intamgiac(n-1);
}

int main()
{
	int n = 6;
	intamgiac(n);
	return 0;
}
