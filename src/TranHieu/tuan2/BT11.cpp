#include <stdio.h>


int findMin(int a[], int n) 
{
    if (n == 1) 
	{
        return a[0];
    }
    int min = findMin(a, n - 1);
    if (a[n - 1] < min) 
	{
        return a[n - 1];
    } else {
        return min;
    }
}

int main() 
{
    int a[] = {12, 45, 2, 67, 8, 10};
    printf("a[] = {12, 45, 2, 67, 8, 10}");
    int n = sizeof(a) / sizeof(a[0]); 
	// Gia su mang: int a[] = {10, 20, 30, 40, 50};
	// Moi so kieu 'int' chiem 4 Bytes.
	// -> sizeof(a) = 5 phan tu * 4 Bytes = 20 Bytes (Tong kich thuoc mang)
	// -> sizeof(a[0]) = 4 Bytes (Kich thuoc 1 phan tu dau tien)
	// -> n = sizeof(a) / sizeof(a[0]) = 20 / 4 = 5 (So luong phan tu)

    int min_val = findMin(a, n);
    printf("Phan tu nho nhat trong mang la: %d\n", min_val);

    return 0;
}

