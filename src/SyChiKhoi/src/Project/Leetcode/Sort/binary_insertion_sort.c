#include <stdio.h>

int binarySearch(int arr[], int item, int low, int high);
void binaryInsertionSort(int arr[], int n);
void printArray(int arr[], int n);

// Hàm tìm kiếm nhị phân để tìm vị trí chèn
int binarySearch(int arr[], int item, int low, int high) {
    if (high <= low)
        return (item > arr[low]) ? (low + 1) : low;
    
    int mid = (low + high) / 2;
    
    if (item == arr[mid])
        return mid + 1;
    
    if (item > arr[mid])
        return binarySearch(arr, item, mid + 1, high);
        
    return binarySearch(arr, item, low, mid - 1);
}

void binaryInsertionSort(int arr[], int n) {
    int i, loc, j, selected;
    
    for (i = 1; i < n; ++i) {
        j = i - 1;
        selected = arr[i];
        
        // Tìm vị trí cần chèn phần tử `selected`
        loc = binarySearch(arr, selected, 0, j);
        
        // Dịch chuyển các phần tử sau vị trí chèn sang phải
        while (j >= loc) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = selected;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {37, 23, 0, 17, 12, 72, 31, 46, 100, 88, 54};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Original array: \n");
    printArray(arr, n);
    
    binaryInsertionSort(arr, n);
    
    printf("Sorted array: \n");
    printArray(arr, n);
    
    return 0;
}
