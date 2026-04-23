# 🔄 Tóm tắt Thuật toán Sắp xếp (Sorting Algorithms)

Thư mục này là nơi chứa các thuật toán sắp xếp mảng/danh sách từ cơ bản đến nâng cao. Sorting là nền tảng cốt lõi của rất nhiều thuật toán khác và là công cụ tinh chỉnh Performance mãnh liệt nhất trong môn thuật toán.

## 1. Top thuật toán cơ bản `O(N^2)`
> [!NOTE]
> Những thuật toán này rất dễ code do hai vòng lặp lồng nhau, nhưng hiệu năng sẽ cực kỳ chậm nếu mảng có hàng vạn phần tử. Mặc dù không bao giờ dùng cho thực tế (production), nhưng đi thi môn DSA sẽ rất hay bắt viết code tay. Dưới đây là thông tin kỹ thuật (Technical Details) cho từng thuật toán:

- **Exchange Sort (Đổi chỗ trực tiếp)**: Đứng ở một vị trí và so sánh nó với tất cả các phần tử đứng sau, nếu phần tử sau nhỏ hơn thì đổi chỗ ngay lập tức. Rất dễ hiểu nhưng số lượng phép swap cực kỳ lớn.
  - *Time Complexity*: Best/Average/Worst `O(N^2)`.
  - *Space Complexity*: `O(1)`.
- **Bubble Sort (Nổi bọt)**: So sánh từng cặp phần tử đứng cạnh nhau và đổi chỗ nếu chúng ngược thứ tự, đưa phần tử lớn nhất "nổi bọt" dần về cuối mảng sau mỗi vòng lặp. Có thể tối ưu bằng cờ (flag) để dừng sớm nếu mảng đã được sắp xếp.
  - *Time Complexity*: Best `O(N)` (khi mảng đã xếp sẵn), Average/Worst `O(N^2)`.
  - *Space Complexity*: `O(1)`.
- **Selection Sort (Chọn lọc)**: Luôn quét để đi tìm phần tử nhỏ nhất trong đoạn còn lại rồi đưa nó lên đầu mảng. Code dễ, ít lần đổi (swap) dữ liệu (tối đa `N-1` lần) nhưng số lần quét và so sánh quá nhiều.
  - *Time Complexity*: Best/Average/Worst `O(N^2)`.
  - *Space Complexity*: `O(1)`.
- **Insertion Sort (Chèn)**: Giống như xếp bài tây trên tay vậy. Lấy từng phần tử chèn vào đúng vị trí trong mảng đã sắp xếp ở trước nó. Rất nhanh với những mảng nhỏ hoặc mảng gần như đã được sắp xếp sẵn.
  - *Time Complexity*: Best `O(N)`, Average/Worst `O(N^2)`.
  - *Space Complexity*: `O(1)`.
- **Binary Insertion Sort (Chèn nhị phân)**: Bản nâng cấp của Insertion Sort. Dùng tìm kiếm nhị phân (Binary Search) để dò tìm vị trí chèn thay vì phải quét tuần tự từ cuối đoạn đã sắp xếp về đầu, qua đó giảm triệt để số lượng phép so sánh.
  - *Time Complexity*: Best `O(N log N)`, Average/Worst `O(N^2)` (tuy giảm phép so sánh nhưng vẫn tốn `O(N)` để dịch chuyển phần tử của mảng).
  - *Space Complexity*: `O(1)` (nếu không đệ quy) hoặc `O(log N)` (nếu xài hàm đệ quy Binary Search).

## 2. Top thuật toán bá đạo `O(N log N)`
> [!TIP]
> Loại này hay được dùng làm tiêu chuẩn kỹ thuật (được nhúng sẵn vào hàm thư viện như `qsort` của C hay `.sort()` của Java/Python).
- **Merge Sort (Trộn)**: Chặt mảng ra thành các đoạn nhỏ đến tận 1 phần tử rồi Trộn (Merge) chúng lại theo đúng thứ tự. 
  - Ưu điểm: Luôn luôn có tốc độ cố định, hoạt động cực tốt với Danh sách tuyến tính (Linked list). 
  - Khuyết điểm: Cần bộ nhớ phụ `O(N)` để chứa mảng sao chép lúc trộn.
  - *Time Complexity*: Best/Average/Worst `O(N log N)`.
  - *Space Complexity*: `O(N)`.
- **Quick Sort (Chia để trị cực gắt)**: Chọn bừa 1 cục mốc (Pivot), dồn mấy con nhỏ hơn mốc qua trái, to hơn mốc qua phải, rồi đệ quy chia đôi liên tục.
  - Ưu điểm: Chạy thực tế được chứng minh là "Nhanh nhất" (nhờ hằng số ẩn nhỏ) và không tốn memory (in-place). Xài ở khắp mọi nơi.
  - Khuyết điểm: Xui xui lấy trúng cái mốc dở nhất thì tốc độ tuột dốc không phanh xuống về bằng thuật toán `O(N^2)`.
  - *Time Complexity*: Best/Average `O(N log N)`, Worst `O(N^2)`.
  - *Space Complexity*: `O(log N)` (bộ nhớ cho Stack Frame khi đệ quy).
  
## Mẹo áp dụng (Tips) tính "Ổn định" (Stability)

> [!NOTE]
> **Sort Ổn định (Stable)**: Tức là nếu 2 người bằng điểm nhau, ai vào trước thì đứng trước, ai vào sau thì đứng sau. 
> Các thuật toán có tính chất này: **Merge Sort, Insertion Sort, Bubble Sort**.

> [!WARNING]
> **Sort Không ổn định (Unstable)**: Nó chẳng cần biết cũ mới, hễ bằng nhau nó cho xáo trộn thứ tự lung tung luôn.
> Thuật toán điển hình: **Quick Sort, Selection Sort**. Khi xử lý Data kiểu Object nâng cao có nhiều trường thông tin (fields) thì hãy dè chừng rủi ro này nhé!
