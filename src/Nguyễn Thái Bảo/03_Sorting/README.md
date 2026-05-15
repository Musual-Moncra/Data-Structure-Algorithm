# Lab 05: Sắp xếp (Sorting)

## Nội dung
- Bubble Sort - Sắp xếp nổi bọt
- Selection Sort - Sắp xếp chọn
- Con trỏ hàm (Function Pointers) trong sắp xếp
- Sắp xếp với nhiều tiêu chí

## Files

| File | Mô tả |
|------|-------|
| `week04_sorting_main.c` | Giải pháp tổng hợp Week 4 - 4 bài tập sorting |
| `week05_sorting_main.c` | Giải pháp tổng hợp Week 5 - Function pointers |
| `baitap01_bubble_sort_gpa.c` | Bubble Sort - Sắp xếp GPA giảm dần |
| `baitap02_selection_sort_name.c` | Selection Sort - Sắp xếp Name tăng dần |
| `baitap03_selection_sort_name_gpa.c` | Selection Sort - Name (case-insensitive) + GPA |
| `students.txt` | Dữ liệu sinh viên đầu vào |

## Biên dịch và chạy

```bash
# Bài tập 1
gcc baitap01_bubble_sort_gpa.c -o baitap01 && ./baitap01

# Bài tập 2
gcc baitap02_selection_sort_name.c -o baitap02 && ./baitap02

# Bài tập 3
gcc baitap03_selection_sort_name_gpa.c -o baitap03 && ./baitap03

# Chương trình tổng hợp
gcc week04_sorting_main.c -o week04 && ./week04
```

## Tài liệu tham khảo
- `CTDL_Lab 05_Sắp xếp I.pdf`
- `Week4.pdf`, `Week5.pdf`
