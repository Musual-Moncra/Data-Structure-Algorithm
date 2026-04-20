// Thuật toán tìm kiếm tuần tự (Sequential Search)
// (sequential_search.c)
#include <stdio.h>

// x: giá trị cần tìm (search key)
int sequential_search(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1; // không tìm thấy
}

void main() {
    int arr[] = {5, 2, 3, 7, 6, 1, 4, 0, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 5;
    int result = sequential_search(arr, n, x);
    if (result == -1) {
        printf("Not found %d in list\n", x);
    } else {
        printf("Found %d at index %d\n", x, result);
    }
}
