#include <stdio.h>

void analyzeArray(int a[], int n) 
{
    if (n <= 0) 
    {
        printf("Mang rong.\n");
        return;
    }
    long sum = 0;
    for (int i = 0; i < n; i++) 
    {
        sum += a[i];
    }
    double mean = (double)sum / n;
    printf("Gia tri trung binh (mean): %.2f\n", mean);

    // Đếm số phần tử lớn hơn mean
    int count = 0;
    for (int i = 0; i < n; i++) 
    {
        if (a[i] > mean) 
        {
            count++;
        }
    }

    printf("So phan tu lon hon gia tri trung binh: %d\n", count);
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int a[n];
    printf("Nhap cac phan tu (so nguyen duong):\n");
    for (int i = 0; i < n; i++) 
    {
        scanf("%d", &a[i]);
    }

    analyzeArray(a, n);

    return 0;
}