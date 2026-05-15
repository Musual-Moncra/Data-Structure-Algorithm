<div align="center">

# 📘 Data Structures & Algorithms — Academic Workspace

[![C](https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=white)](https://en.wikipedia.org/wiki/C_(programming_language))
[![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Java](https://img.shields.io/badge/Language-Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)](https://en.wikipedia.org/wiki/Java_(programming_language))
[![Status](https://img.shields.io/badge/Status-Active-success?style=for-the-badge)](https://github.com/Musual-Moncra/Data-Structure-Algorithm)
[![License](https://img.shields.io/badge/License-MIT-yellow.svg?style=for-the-badge)](LICENSE)

> **Nghiên cứu, triển khai và hệ thống hóa các cấu trúc dữ liệu & giải thuật nền tảng trong Khoa học Máy tính.**

[Khái quát](#-khái-quát) · [Cấu trúc](#-cấu-trúc-dự-án) · [Thuật toán](#-bảng-tổng-hợp-thuật-toán) · [Hướng dẫn](#-hướng-dẫn-biên-dịch) · [Đội ngũ](#-đội-ngũ-nghiên-cứu)

</div>

---

## 🎓 Khái quát

Repository này là không gian học thuật tập thể, nơi các thành viên cùng nhau **nghiên cứu**, **triển khai** và **tài liệu hóa** các giải thuật cốt lõi của môn học **Cấu trúc dữ liệu & Giải thuật**. Mục tiêu không chỉ dừng lại ở việc viết code chạy đúng — mà còn hướng tới việc xây dựng một **tài liệu tham chiếu chuẩn** cho toàn bộ nhóm.

### 🎯 Mục tiêu học thuật

| Mục tiêu | Mô tả |
|:---|:---|
| **Chuẩn hóa mã nguồn** | Xây dựng các implementation rõ ràng, có chú thích, tuân thủ nguyên tắc Clean Code |
| **Phân tích độ phức tạp** | Đánh giá Big-O cho từng thuật toán về thời gian và bộ nhớ |
| **Hệ thống hóa kiến thức** | Tổ chức tài liệu theo module, dễ tra cứu và mở rộng |
| **Thực hành nhóm** | Rèn luyện quy trình Git, code review và giải quyết conflict |

---

## 📂 Cấu trúc dự án

```
Data-Structure-Algorithm/
│
├── README.md                          # Tài liệu tổng quan (file này)
│
└── src/
    ├── Nguyễn Thái Bảo/               # Workspace — Thái Bảo
    │   ├── 01_Recursion/              #   ▸ Đệ quy & ứng dụng
    │   ├── 02_Searching/              #   ▸ Tìm kiếm (Linear, Binary)
    │   ├── 03_Sorting/                #   ▸ Sắp xếp (Bubble, Selection, Function Pointer)
    │   ├── 04_Linked_Lists/           #   ▸ Danh sách liên kết đơn
    │   ├── 05_Advanced_Topics/        #   ▸ Chủ đề nâng cao
    │   ├── Documents/                 #   ▸ Tài liệu học thuật
    │   ├── Storage/                   #   ▸ Ghi chú kỹ thuật
    │   ├── Tasks/                     #   ▸ PDF đề bài Lab
    │   └── README.md                  #   ▸ Hướng dẫn chi tiết
    │
    ├── SyChiKhoi/                     # Workspace — Chí Khởi
    │   ├── docs/                      #   ▸ Tài liệu & đề bài
    │   ├── resources/                 #   ▸ Resource files (students.txt...)
    │   └── src/Project/               #   ▸ Source code
    │       ├── Lab02/                 #     ▸ Lab 02 — Đệ quy
    │       ├── Lab03/                 #     ▸ Lab 03 — Greedy & Xấp xỉ
    │       ├── Lab04/                 #     ▸ Lab 04 — Tìm kiếm
    │       ├── Lab05/                 #     ▸ Lab 05 — Sắp xếp
    │       └── Leetcode/              #     ▸ LeetCode practice
    │
    ├── TranHieu/                      # Workspace — Trần Hiếu
    │   ├── tuan2/                     #   ▸ Tuần 2 — Đệ quy (C++)
    │   ├── tuan3/                     #   ▸ Tuần 3 — Tìm kiếm
    │   ├── tuan4/                     #   ▸ Tuần 4 — Sắp xếp
    │   └── tuan5/                     #   ▸ Tuần 5 — Sắp xếp nâng cao
    │
    └── Trần Thành Đạt/                # Workspace — Thành Đạt
```

---

## 📊 Bảng tổng hợp thuật toán

### Sắp xếp (Sorting)

| Thuật toán | Best | Average | Worst | Space | Ổn định |
|:---|:---:|:---:|:---:|:---:|:---:|
| **Bubble Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| **Selection Sort** | O(n²) | O(n²) | O(n²) | O(1) | ❌ |
| **Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| **Binary Insertion Sort** | O(n) | O(n²) | O(n²) | O(1) | ✅ |
| **Exchange Sort** | O(n²) | O(n²) | O(n²) | O(1) | ✅ |

### Tìm kiếm (Searching)

| Thuật toán | Best | Average | Worst | Yêu cầu |
|:---|:---:|:---:|:---:|:---|
| **Sequential Search** | O(1) | O(n) | O(n) | Không |
| **Binary Search** | O(1) | O(log n) | O(log n) | Mảng đã sắp xếp |

### Cấu trúc dữ liệu

| Cấu trúc | Truy cập | Tìm kiếm | Chèn | Xóa |
|:---|:---:|:---:|:---:|:---:|
| **Mảng (Array)** | O(1) | O(n) | O(n) | O(n) |
| **Danh sách liên kết** | O(n) | O(n) | O(1)* | O(n) |

> *Chèn đầu danh sách liên kết: O(1)

---

## 🛠 Hướng dẫn biên dịch

### C — GCC Compiler

```bash
# Biên dịch
gcc -o output_name path/to/file.c -lm

# Biên dịch với cảnh báo
gcc -Wall -Wextra -o output_name path/to/file.c -lm

# Chạy
./output_name
```

### C++ — G++ Compiler

```bash
# Biên dịch
g++ -std=c++17 -o output_name path/to/file.cpp

# Chạy
./output_name
```

### Java

```bash
# Biên dịch
javac path/to/File.java

# Chạy
java -cp path/to File
```

### Ví dụ cụ thể

```bash
# Bài tập Sorting — Thái Bảo
cd "src/Nguyễn Thái Bảo/03_Sorting"
gcc baitap01_bubble_sort_gpa.c -o sort && ./sort

# LeetCode Sorting — Chí Khởi
cd src/SyChiKhoi/src/Project/Leetcode/Sort
gcc bubble_sort.c -o bubble && ./bubble

# Tuần 2 Đệ quy — Trần Hiếu (C++)
cd src/TranHieu/tuan2
g++ -std=c++17 bt1.cpp -o bt1 && ./bt1
```

---

## 📚 Tài liệu tham khảo

### Tài liệu nội bộ

| Tài liệu | Đường dẫn |
|:---|:---|
| Academic Documentation | `src/Nguyễn Thái Bảo/Documents/Academic_Documentation.md` |
| Technical Notes | `src/Nguyễn Thái Bảo/Storage/Technical_Notes.md` |
| Project Documentation | `src/Nguyễn Thái Bảo/Documents/Project_Documentation.md` |
| Workspace README | `src/Nguyễn Thái Bảo/README.md` |

### Tài liệu Lab (PDF)

| Module | Nội dung |
|:---|:---|
| NMLT Labs | Cơ bản lập trình C (Lab 01–03) |
| CTDL Lab 02 | Đệ quy (Recursion) |
| CTDL Lab 03 | Tổng quan CTDL & GT |
| CTDL Lab 04 | Tìm kiếm (Searching) |
| CTDL Lab 05 | Sắp xếp (Sorting I) |
| CTDL Lab 07 | Danh sách liên kết (Linked List) |

---

## 👥 Đội ngũ nghiên cứu

| Thành viên | GitHub | Vai trò |
|:---|:---|:---|
| **Nguyễn Thái Bảo** | [@Musual-Moncra](https://github.com/Musual-Moncra) | Lead · Sorting & Linked Lists |
| **Sỳ Chí Khởi** | [@SyChiKhoi](https://github.com/SyChiKhoi) | Contributor · Searching & LeetCode |
| **Trần Hiếu** | [@Henryquy](https://github.com/Henryquy) | Contributor · Recursion & C++ |
| **Trần Thành Đạt** | — | Contributor |

---

## 📜 Giấy phép

Dự án được phân phối dưới giấy phép **MIT License**. Xem file [LICENSE](LICENSE) để biết thêm chi tiết.

---

<div align="center">

**DSA Academic Workspace** · Nơi tư duy gặp gỡ mã nguồn

© 2026 DSA Team — Built with rigor and collaboration in mind.

</div>
