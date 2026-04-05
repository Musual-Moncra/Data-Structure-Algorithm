/*Cài đặt thuật toán đếm các cặp số chia hết cho 5 trong mảng n số nguyên ngẫu nhiên.
Tính thời gian thực hiện trên máy nếu n = 5000, n = 10000, n = 25000, n= 50000
*/
 #include <stdio.h>
 #include <stdlib.h>
 #include <time.h>

 void count_pair(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr[i] + arr[j]) % 5 == 0) {
                count++;
            }
        }
    }
    printf("So cap so chia het cho 5: %d\n", count);
 }

 void randomArray(int arr[], int n) {
    srand(time(NULL));
    int max = n - 1;
    int value;
    for (int i = 0; i < n; i++) {
        value = rand() % max;
        arr[i] = value;
    }
 }

 void printArray(int a[], int n) {
    printf("\n--- Cac gia tri trong mang ---\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t", a[i]);
        
        // Cứ in được 10 số thì tự động xuống dòng
        if ((i + 1) % 10 == 0) {
            printf("\n");
        }
    }
    printf("\n----------------------------\n");
}

 int main() {
    int n;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &n);
    int arr[n];
    randomArray(arr,n);
    if (n <= 100) {
        printArray(arr, n);
    } else {
        printf("Mang qua lon (%d phan tu), chi in 10 so dau tien: \n", n);
        for(int i = 0; i < 10; i++) {
            printf("%d ", arr[i]);
        }
        printf("...\n");
    }
    float start, end;
    start = clock();
    count_pair(arr, n);
    end = clock();
    printf("Thoi gian thuc hien: %f", end - start);
    return 0;
 }