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
	intamgiac(n-1);
	insao(n);
	printf("\n");
}

int main()
{
	int n = 6;
	intamgiac(n);
	return 0;
}
