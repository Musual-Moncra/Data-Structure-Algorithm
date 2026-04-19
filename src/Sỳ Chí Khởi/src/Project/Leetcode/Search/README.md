# 🔍 Tóm tắt Thuật toán Tìm kiếm (Search Algorithms)

Thư mục này chuyên dùng để chứa các thuật toán tìm kiếm. Đây là một trong những dạng bài cơ bản và xuất hiện nhiều nhất trong môn DSA cũng như khi giải Leetcode.

## 1. Linear Search (Tìm kiếm tuyến tính)
- **Mô tả**: Quét từng phần tử trong mảng từ đầu đến cuối xem có khớp với x không.
- **Điều kiện**: Mảng **không cần** sắp xếp.
- **Độ phức tạp**: 
  - Time: `O(N)` (trung bình và tệ nhất)
  - Space: `O(1)`
- **Khi nào dùng**: Mảng không có quy luật, kích thước mảng nhỏ, hoặc chỉ tìm một lần duy nhất.

## 2. Binary Search (Tìm kiếm nhị phân)
- **Mô tả**: Thay vì dò từng cái, ta so sánh x với phần tử ở **chính giữa** mảng. Dựa vào kết quả mà vứt bỏ một nửa mảng không chứa đáp án.
- **Điều kiện tiên quyết bắt buộc**: Mảng **BẮT BUỘC** phải được sắp xếp trước (tăng/giảm dần) hoặc thoả mãn tính chất đơn điệu.
- **Độ phức tạp**:
  - Time: `O(log N)` - Cực kỳ nhanh!
  - Space: `O(1)` (Ngang O(log N) nếu viết bằng đệ quy do tốn Call Stack).
- **Tuyệt chiêu cần nhớ**:
  - Công thức tính `mid` an toàn để chống lỗi tràn số (overflow) ở Java/C++: 
    `int mid = left + (right - left) / 2;` thay vì `(left + right) / 2`.
  - Lúc nào biến `left = mid + 1` và `right = mid - 1` để chống vô hạn vòng lặp (infinite loop).

## Mẹo áp dụng (Tips)
- Nếu đề bài bắt tìm kiếm mà cho dữ kiện **thời gian chạy `O(log N)`**, hoặc chèn thêm câu "mảng đã được sắp xếp", 99% họ muốn bạn xài Binary Search!
- Bạn có thể áp dụng Binary Search cho việc **Quy hoạch động** (Tìm kết quả nhỏ nhất thỏa mãn một điều kiện nào đó) chứ không thuần túy là tìm số trong mảng.
