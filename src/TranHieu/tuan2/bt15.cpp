#include <stdio.h>

int Max(int a[], int n) 
{
    if (n == 1) 
	{
        return a[0];
    }

    //  Goi de quy tim Max cua (n-1) phan tu truoc
    int max_rest = findMax(a, n - 1);

    // So sanh phan tu cuoi voi Max cua phan tu con lai
    if (a[n - 1] > max_rest) 
	{
        return a[n - 1];
    } 
	else 
	{
        return max_rest;
    }
}

int main() 
{
    int a[] = {3, 9, 2, 15, 7};
    int n = sizeof(a) / sizeof(a[0]);
    int max_val = findMax(a, n);
    printf("Gia tri lon nhat la: %d\n", max_val);
    return 0;
}
