# Cấu Trúc Dữ Liệu & Giải Thuật
## Tài Liệu Học Thuật Tổng Hợp

**Sinh viên:** Nguyễn Thái Bảo  
**Môn học:** Cấu trúc dữ liệu & Giải thuật  
**Ngôn ngữ:** C

---

## Mục Lục

1. [Tổng quan về Cấu trúc dữ liệu](#1-tổng-quan-về-cấu-trúc-dữ-liệu)
2. [Đệ quy (Recursion)](#2-đệ-quy-recursion)
3. [Cấu trúc dữ liệu và Giải thuật cơ bản](#3-cấu-trúc-dữ-liệu-và-giải-thuật-cơ-bản)
4. [Tìm kiếm (Searching)](#4-tìm-kiếm-searching)
5. [Sắp xếp (Sorting)](#5-sắp-xếp-sorting)
6. [Danh sách liên kết (Linked List)](#6-danh-sách-liên-kết-linked-list)
7. [Con trỏ hàm (Function Pointers)](#7-con-trỏ-hàm-function-pointers)
8. [Bài tập thực hành](#8-bài-tập-thực-hành)

---

## 1. Tổng quan về Cấu trúc dữ liệu

### 1.1 Định nghĩa

**Cấu trúc dữ liệu (Data Structure)** là cách tổ chức, lưu trữ và quản lý dữ liệu trong máy tính sao cho việc truy cập và thao tác trên dữ liệu được hiệu quả.

### 1.2 Phân loại

| Loại | Mô tả | Ví dụ |
|------|-------|-------|
| Cấu trúc dữ liệu tuyến tính | Các phần tử được sắp xếp theo thứ tự tuần tự | Mảng, Danh sách liên kết, Stack, Queue |
| Cấu trúc dữ liệu phi tuyến | Các phần tử không theo thứ tự tuần tự | Cây, Graph |

### 1.3 Độ phức tạp thuật toán (Big O Notation)

| Ký hiệu | Tên gọi | Mô tả |
|---------|---------|-------|
| O(1) | Hằng số | Thời gian không đổi |
| O(log n) | Logarit | Giảm một nửa sau mỗi bước |
| O(n) | Tuyến tính | Tỷ lệ thuận với kích thước |
| O(n²) | Bình phương | Hai vòng lặp lồng nhau |
| O(2ⁿ) | Hàm mũ | Tăng gấp đôi mỗi bước |

---

## 2. Đệ quy (Recursion)

### 2.1 Định nghĩa

**Đệ quy** là kỹ thuật mà một hàm gọi chính nó để giải quyết vấn đề bằng cách chia nhỏ thành các bài toán con tương tự.

### 2.2 Thành phần của hàm đệ quy

```c
// Cấu trúc chung
void recursive_function(params) {
    // 1. Điều kiện dừng (Base case)
    if (base_condition) {
        return base_result;
    }
    
    // 2. Phần đệ quy (Recursive case)
    return recursive_function(modified_params);
}
```

### 2.3 Ví dụ: Tính giai thừa

```c
int factorial(int n) {
    if (n <= 1) return 1;          // Base case
    return n * factorial(n - 1);   // Recursive case
}
```

### 2.4 Ví dụ: Dãy Fibonacci

```c
int fibonacci(int n) {
    if (n <= 1) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
```

### 2.5 Ưu điểm và nhược điểm

| Ưu điểm | Nhược điểm |
|---------|------------|
| Code ngắn gọn, dễ đọc | Tốn bộ nhớ stack |
| Phù hợp bài toán chia để trị | Có thể gây stack overflow |
| Tự nhiên cho cấu trúc cây | Chậm hơn vòng lặp (overhead) |

---

## 3. Cấu trúc dữ liệu và Giải thuật cơ bản

### 3.1 Mảng (Array)

```c
// Khai báo mảng
int arr[100];
int n = 10;

// Truy cập phần tử
arr[0] = 5;        // Phần tử đầu tiên
arr[n-1] = 10;     // Phần tử cuối cùng
```

### 3.2 Con trỏ (Pointer)

```c
int x = 10;
int *ptr = &x;     // ptr lưu địa chỉ của x
printf("%d", *ptr); // Truy cập giá trị qua con trỏ
```

### 3.3 Struct (Cấu trúc)

```c
typedef struct {
    int id;
    char name[50];
    float score;
} Student;

Student s1 = {1, "An", 8.5};
```

---

## 4. Tìm kiếm (Searching)

### 4.1 Tìm kiếm tuyến tính (Linear Search)

```c
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) return i;
    }
    return -1; // Không tìm thấy
}
```

| Độ phức tạp | Trường hợp |
|-------------|------------|
| O(1) | Tốt nhất (phần tử đầu tiên) |
| O(n) | Trung bình và xấu nhất |

### 4.2 Tìm kiếm nhị phân (Binary Search)

```c
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        
        if (arr[mid] == key) return mid;
        if (arr[mid] < key) left = mid + 1;
        else right = mid - 1;
    }
    return -1;
}
```

| Yêu cầu | Mảng đã sắp xếp |
|---------|-----------------|
| O(1) | Tốt nhất |
| O(log n) | Trung bình và xấu nhất |

---

## 5. Sắp xếp (Sorting)

### 5.1 Bubble Sort (Sắp xếp nổi bọt)

**Nguyên lý:** So sánh hai phần tử kề nhau, nếu sai vị trí thì đổi chỗ. Lặp lại cho đến khi mảng được sắp xếp.

```c
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

| Trường hợp | Độ phức tạp |
|------------|-------------|
| Tốt nhất | O(n) - đã sắp xếp |
| Trung bình | O(n²) |
| Xấu nhất | O(n²) |

### 5.2 Selection Sort (Sắp xếp chọn)

**Nguyên lý:** Tìm phần tử nhỏ nhất (hoặc lớn nhất) trong phần chưa sắp xếp và đưa về vị trí đúng.

```c
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
```

| Trường hợp | Độ phức tạp |
|------------|-------------|
| Tất cả | O(n²) |

### 5.3 So sánh Bubble Sort và Selection Sort

| Tiêu chí | Bubble Sort | Selection Sort |
|----------|-------------|----------------|
| Độ phức tạp | O(n²) | O(n²) |
| Số lần swap | Nhiều (O(n²)) | Ít (O(n)) |
| Ổn định | Có | Không |
| Tối ưu khi đã sorted | Có (với flag) | Không |

---

## 6. Danh sách liên kết (Linked List)

### 6.1 Định nghĩa

**Danh sách liên kết đơn** là cấu trúc dữ liệu gồm các node, mỗi node chứa dữ liệu và con trỏ đến node tiếp theo.

```c
typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SinglyLinkedList {
    Node *head;
} SinglyLinkedList;
```

### 6.2 Các thao tác cơ bản

#### Khởi tạo
```c
void init_list(SinglyLinkedList *list) {
    list->head = NULL;
}
```

#### Tạo node mới
```c
Node* create_node(int data) {
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}
```

#### Chèn vào đầu danh sách
```c
void insert_head(SinglyLinkedList *list, Node *node) {
    node->next = list->head;
    list->head = node;
}
```

#### Chèn vào cuối danh sách
```c
void insert_tail(SinglyLinkedList *list, Node *node) {
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node *current = list->head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}
```

#### Chèn vào danh sách có thứ tự
```c
void insert_sorted(SinglyLinkedList *list, Node *node) {
    Node *current = list->head;
    Node *previous = NULL;
    
    while (current != NULL && current->data < node->data) {
        previous = current;
        current = current->next;
    }
    
    if (previous == NULL) {
        node->next = list->head;
        list->head = node;
    } else {
        previous->next = node;
        node->next = current;
    }
}
```

#### Tìm kiếm
```c
Node* search(SinglyLinkedList *list, int value) {
    Node *current = list->head;
    while (current != NULL) {
        if (current->data == value) return current;
        current = current->next;
    }
    return NULL;
}
```

#### Xóa phần tử
```c
void delete(SinglyLinkedList *list, int value) {
    Node *current = list->head;
    Node *previous = NULL;
    
    while (current != NULL && current->data != value) {
        previous = current;
        current = current->next;
    }
    
    if (current != NULL) {
        if (previous != NULL) {
            previous->next = current->next;
        } else {
            list->head = current->next;
        }
        free(current);
    }
}
```

### 6.3 Độ phức tạp các thao tác

| Thao tác | Độ phức tạp |
|----------|-------------|
| Truy cập | O(n) |
| Tìm kiếm | O(n) |
| Chèn đầu | O(1) |
| Chèn cuối | O(n) |
| Xóa | O(n) |

---

## 7. Con trỏ hàm (Function Pointers)

### 7.1 Định nghĩa

**Con trỏ hàm** là biến lưu địa chỉ của một hàm, cho phép truyền hàm như tham số.

```c
// Khai báo con trỏ hàm
int (*compare)(int a, int b);

// Gán hàm cho con trỏ
compare = &myCompareFunction;

// Gọi qua con trỏ
int result = compare(5, 10);
```

### 7.2 Ứng dụng trong sắp xếp

```c
// Hàm so sánh tăng dần
int compareAsc(int a, int b) {
    return a > b;
}

// Hàm so sánh giảm dần
int compareDesc(int a, int b) {
    return a < b;
}

// Hàm sort tổng quát
void sort(int arr[], int n, int (*compare)(int, int)) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1])) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
```

### 7.3 Ưu điểm

- Giảm code trùng lặp (DRY principle)
- Linh hoạt, dễ mở rộng
- Nền tảng cho callback và polymorphism

---

## 8. Bài tập thực hành

### 8.1 Bài tập 1: Bubble Sort - Sắp xếp GPA giảm dần

**Yêu cầu:** Dùng Bubble Sort sắp xếp danh sách sinh viên theo điểm GPA giảm dần.

**Giải pháp:** Xem file `Tasks/baitap01_sv.c`

```c
void sort_by_gpa(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (s[j].gpa < s[j + 1].gpa) {
                Student temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }
}
```

### 8.2 Bài tập 2: Selection Sort - Sắp xếp Name tăng dần

**Yêu cầu:** Dùng Selection Sort sắp xếp danh sách sinh viên theo tên tăng dần.

**Giải pháp:** Xem file `Tasks/baitap02_sv.c`

```c
void sort_by_name(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (strcmp(s[j].name, s[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Student temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
    }
}
```

### 8.3 Bài tập 3: Selection Sort - Sắp xếp Name (case-insensitive) + GPA

**Yêu cầu:** Sắp xếp theo tên tăng dần (không phân biệt hoa thường), nếu trùng tên thì sắp xếp theo GPA giảm dần.

**Giải pháp:** Xem file `Tasks/baitap03_sv.c`

```c
void strToLower(char *src, char *dest) {
    int i = 0;
    while (src[i]) {
        dest[i] = tolower((unsigned char)src[i]);
        i++;
    }
    dest[i] = '\0';
}

void sort_by_name_gpa(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            char name1[30], name2[30];
            strToLower(s[j].name, name1);
            strToLower(s[min_idx].name, name2);
            int cmp = strcmp(name1, name2);
            if (cmp < 0 || (cmp == 0 && s[j].gpa > s[min_idx].gpa)) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            Student temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
    }
}
```

### 8.4 Bài tập 4: Function Pointer - Menu sắp xếp tổng quát

**Yêu cầu:** Sử dụng con trỏ hàm để tạo menu cho phép chọn cột sắp xếp và thứ tự.

**Giải pháp:** Xem file `Gemini/Week4/main.c`

---

## Phụ lục: Hướng dẫn biên dịch và chạy

### Biên dịch chương trình C

```bash
gcc <file.c> -o <output_name>
./<output_name>
```

### Ví dụ

```bash
cd "src/Nguyễn Thái Bảo/Tasks"
gcc baitap01_sv.c -o baitap01
./baitap01
```

---

## Tài liệu tham khảo

1. CTDL_Lab 02_Đệ quy.pdf
2. CTDL_Lab 04_Tìm kiếm.pdf
3. CTDL_Lab 05_Sắp xếp I.pdf
4. CTDL_Lab 07_Danh sách liên kết.pdf
5. Week4.pdf, Week5.pdf

---

*Tài liệu được biên soạn bởi Nguyễn Thái Bảo*
