# 🔄 Tóm tắt Thuật toán Sắp xếp (Sorting Algorithms)

Thư mục này là nơi chứa các thuật toán sắp xếp mảng/danh sách từ cơ bản đến nâng cao. Sorting là nền tảng cốt lõi của rất nhiều thuật toán khác và là công cụ tinh chỉnh Performance mãnh liệt nhất trong môn thuật toán.

## 1. Top thuật toán cơ bản `O(N^2)`
Những thuật toán này rất dễ code do hai vòng lặp lồng nhau, nhưng bị chê là chậm nếu mảng có hàng vạn phần tử. Không bao giờ dùng cho thực tế (production) nhưng đi thi môn DSA sẽ hay bắt viết code tay.
- **Bubble Sort (Nổi bọt)**: So sánh từng cặp đứng cạnh nhau và đổi chỗ dần dọc theo mảng. Chạy siêu chậm.
- **Selection Sort (Chọn lọc)**: Luôn đi tìm phần tử nhỏ nhất trong đoạn còn lại rồi tống nó lên đầu mảng. Code dễ, ít lần đổi (swap) dữ liệu nhưng số lần quét và so sánh quá tay.
- **Insertion Sort (Chèn)**: Giống như xếp bài tây trên tay vậy. Rất nhanh với mấy mảng gần như đã được sắp xếp sẵn, nhưng mảng lộn xộn thì siêu chậm.

## 2. Top thuật toán bá đạo `O(N log N)`
Loại này hay được dùng làm tiêu chuẩn kỹ thuật (được nhúng sẵn vào hàm thư viện như `qsort` của C hay `.sort()` của Java/Python).
- **Merge Sort (Trộn)**: Chặt mảng ra thành các đoạn nhỏ đến tận 1 phần tử rồi Trộn (Merge) chúng lại theo đúng thứ tự. 
  - Ưu: Luôn luôn có tốc độ cố định, hoạt động cực tốt với Danh sách tuyến tính (Linked list). 
  - Khuyết: Cần bộ nhớ phụ `O(N)` để chứa mảng sao chép lúc trộn.
- **Quick Sort (Chia để trị cực gắt)**: Chọn bừa 1 cục mốc (Pivot), dồn mấy con nhỏ hơn mốc qua trái, to hơn mốc qua phải, rồi đệ quy chia đôi liên tục.
  - Ưu: Chạy thực tế được chứng minh là "Nhanh nhất" và không tốn memory (in-place). Xài ở khắp mọi nơi.
  - Khuyết: Xui xui lấy trúng cái mốc dở nhất thì tốc độ tuột dốc không phanh xuống về bằng Bubble Sort `O(N^2)`.
  
## Mẹo áp dụng (Tips) tính "Ổn định" (Stability)
- Sort **Ổn định (Stable)**: Tức là nếu 2 người bằng điểm nhau, ai vào trước thì đứng trước, ai vào sau thì đứng sau. 
  - Các thuật toán có tính chất này: Merge Sort, Insertion Sort, Bubble Sort.
- Sort **Không ổn định (Unstable)**: Nó chẳng cần biết cũ mới, hễ bằng nhau nó cho xáo trộn thứ tự lung tung luôn.
  - Thuật toán vô trách nhiệm điển hình: Quick Sort, Selection Sort. Khi xử lý Data kiểu Object nâng cao có nhiều field thông tin thì hãy dè chừng thuật lý này nhé!
