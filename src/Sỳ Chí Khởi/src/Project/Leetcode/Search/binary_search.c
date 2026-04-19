// Thuật toán tìm kiếm nhị phân (Binary Search)
// (binary_search.c)
#include <stdio.h>

// x: giá trị cần tìm (search key)
int binary_search(int arr[], int n, int x) {
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1; // không tìm thấy
}

// Đệ quy
int recursive_binary_search(int arr[], int left, int right, int x) {
    if (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid] < x)
            return recursive_binary_search(arr, mid + 1, right, x);
        else
            return recursive_binary_search(arr, left, mid - 1, x);
    }
    return -1; // không tìm thấy
}

void main() {
    int arr[] = {2, 5, 6, 8, 10, 15, 16, 17, 18, 20};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 6;
    int result = binary_search(arr, n, x);
    if (result == -1)
        printf("Not found %d in list\n", x);
    else
        printf("Found %d at index %d\n", x, result);

    result = recursive_binary_search(arr, 0, n - 1, x);
    if (result == -1)
        printf("Not found %d in list\n", x);
    else
        printf("Found %d at index %d\n", x, result);
}
