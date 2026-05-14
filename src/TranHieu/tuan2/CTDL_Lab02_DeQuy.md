# Cấu trúc dữ liệu & giải thuật - Bài tập thực hành

## Lab 01: Đệ quy

### A. Chuẩn bị
- Đọc kỹ slide bài giảng.
- Tài liệu tham khảo: [1] Robert Sedgewick. (1998). Algorithms in C, Part 1-4, Third Edition. Addison-Wesley.

### B. Hướng dẫn
1. Tạo thư mục `CTDL-BTTH-TuanX-MSSV` (với XX là tuần học, ví dụ Tuan1, Tuan2,…)
2. Làm bài & Lưu tất cả file bài làm vào thư mục trên.
3. Xóa các file `.exe` → Nén thư mục này → tạo file nén `CTDL-BTTH-TuanX-MSSV.zip`
4. Nộp file nén `CTDL-BTTH-TuanX-MSSV.zip` vào mục “Bài tập thực hành tuần X” trên mLearning.

### C. Thực hành

**Bài tập 1.**
Viết hàm in ra `n` dấu `*` trên cùng một dòng.
*Ví dụ:* `n = 6` → `* * * * * *`
*Gợi ý:* 
- Trường hợp cơ sở / điều kiện dừng: `n = 0` → không in ký tự nào và kết thúc (trả về).
- `n = 6`: dòng có 6 dấu `*` bao gồm dòng có 5 dấu `*` (đệ quy) và in thêm một dấu `*` cuối cùng.

**Bài tập 2.**
Viết hàm in ra tam giác `*` (bằng cách đệ quy).
*Ví dụ:* `n = 6`
```text
Nhap n: 6
*
* *
* * *
* * * *
* * * * *
* * * * * *
```

**Bài tập 3.**
Viết hàm in ra tam giác `*` ngược (bằng cách đệ quy).
*Ví dụ:* `n = 6`
```text
* * * * * *
* * * * *
* * * *
* * *
* *
*
```

**Bài tập 4.**
Viết hàm đệ quy cho phép biểu diễn nhị phân của một số nguyên dương `n`.
*Ví dụ:* `n = 13` → `1101`
*Gợi ý:* `1101` là nhị phân của `13` tương ứng với nhị phân của `(13 / 2)` là `110` và `1` là số dư của `(13 % 2)`.

**Bài tập 5.**
Viết hàm đệ quy cho phép nhập số giây và chuyển thành giờ, phút, giây. 
*Ví dụ:* nhập `3665` -> `1 giờ 1 phút 5 giây`

**Bài tập 6.**
Viết hàm đệ quy cho phép kiểm tra xem một số có phải số nguyên tố không?

**Bài tập 7.**
Viết hàm đệ quy cho phép tính tổng các chữ số của một số nguyên dương `n`.
*Ví dụ:* `n = 1980` → tổng = `1 + 9 + 8 + 0 = 18`

**Bài tập 8.**
Viết hàm đệ quy cho phép xuất ngược một số nguyên dương `n`.
*Ví dụ:* `n = 1980` → `0891`

**Bài tập 9.**
Sử dụng đệ quy để đếm số các chữ số của một số nguyên dương `n`.
*Ví dụ:* `n = 44253`
*Kết quả:* `5`

**Bài tập 10.**
Sử dụng vòng lặp để đếm số các chữ số của một số nguyên dương `n`.
*Ví dụ:* `n = 44253`
*Kết quả:* `5`

**Bài tập 11.**
Sử dụng đệ quy để tìm phần tử nhỏ nhất trong mảng số nguyên `a`.

**Bài tập 12.**
Tính tổng `n` số tự nhiên đầu tiên bằng đệ quy.

**Bài tập 13.**
Sử dụng đệ quy để kiểm tra xem một từ đã cho có phải đọc ngược xuôi giống nhau (chuỗi đối xứng) hay không?
*Ví dụ:* các từ `radar`, `madam` là chuỗi đối xứng.

**Bài tập 14.**
Cho mảng `a` có `n` phần tử, tính tổng các phần tử trong mảng bằng đệ quy.
*Ví dụ:* `a[] = {1, 2, 5}` → tổng = `8`

**Bài tập 15.**
Cho mảng `a` có `n` phần tử, tìm giá trị lớn nhất trong mảng bằng đệ quy.
    