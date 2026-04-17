# Sổ Tay Kỹ Thuật Cá Nhân (Technical Notes)
*Ghi chép của: Nguyễn Thái Bảo*
*Chủ đề: Sắp xếp sơ cấp (Sorting I) & Ứng dụng con trỏ hàm trong C*

## 1. So sánh nhanh Bubble Sort và Selection Sort
- **Bubble Sort (Sắp xếp nổi bọt):**
  - **Nguyên lý:** "Đẩy bong bóng", nghĩa là mình cứ so sánh 2 số kề nhau, số nào lớn/nhỏ hơn mình swap luôn. Cứ thế phần tử lớn (hoặc nhỏ) nhất sẽ bị "đẩy" về cuối mảng sau 1 vòng duyệt.
  - **Độ phức tạp:** $O(N^2)$.
  - **Bài học từ lúc code:** Cách dễ bị nhầm nhất là limit vòng for quá dài dẫn đến bị lỗi Out-of-bound array. Ở bài 1 mình code cái này rất mượt để sắp xếp điểm giảm dần, mình thấy nó dễ triển khai nhất nhưng chắc với list vài trăm nghìn dòng thì nó sẽ chạy rất chậm.

- **Selection Sort (Sắp xếp chọn):**
  - **Nguyên lý:** Khác với Bubble là đổi chỗ liên tục, Selection Sort sẽ lấy một mốc và dò tìm "ứng cử viên max/min" trong danh sách còn lại, chốt được xong mới chịu swap một lần.
  - **Độ phức tạp:** Đồng hạng $O(N^2)$, tuy nhiên do thực hiện swap ít hơn (vì chỉ swap $O(N)$ lần) nên thực tế nó hiệu năng hơn chút đỉnh so với Bubble sort nếu tốn bộ nhớ hoán vị cao. 
  - Mình áp dụng thuật toán này ổn thỏa vào việc sắp xếp theo Alphabet theo chiều tăng dần cho tên ở bài 2.

## 2. Kỹ thuật so sánh chuỗi (String Comparison string.h)
- Bình thường `strcmp(a, b)` chỉ trả về kết quả tuỳ vào mã ASCII nên có sự tách biệt khi dùng chữa hoa chữ thường.
- Cụ thể ở bài 3, thầy yêu cầu so sánh `KHÔNG phân biệt hoa/thường`. Giải pháp của mình:
  1. Viết riêng cho nó 1 hàm tên `strToLower()`. Hàm này mượn buffer tự dựng để hứng nguyên dãy ký tự của name chạy theo vòng for và đổi tụi nó thành lower case hết (Dùng `<ctype.h>` hàm `tolower`).
  2. Việc ép chuẩn (normalize) dữ liệu trước khi pass vào `strcmp()` tránh đi được rất nhiều Bug sai khác. Cực kỳ kinh nghiệm.

## 3. Callback và Function Pointer (Con trỏ hàm)
- **Tình huống bài toán:** Làm menu chọn cột sắp xếp (Name/Score) và thứ tự (Asc/Desc). Nếu dùng cách if/else lồng for loop vào bên trong thì mình sẽ có 4 lần phải copy cái khung thuật toán (DRY - Don't Repeat Yourself chê cách này).
- **Cách mình giải quyết:** 
  - Khai báo con trỏ hàm cực ngắn gọn tại Parameter: `void sort(..., int (*compare)(Student a, Student b))`
  - Tự cắt nhỏ logic so sánh nhỏ (Tăng dần bằng Name, Tăng dần bằng Điểm...) thành 4 public methods rành mạch.
  - Khởi tạo xong gọi `sort(temp, count, compareDescName)` -> Xong.
  - Vụ học này cho mình cái base cực vững chắc cho việc nhép interface vào cấu trúc đa hình (Polymorphism) nếu sau này đổi sang Code OOP.

## 4. Kỹ thuật Input Stream căn bản
- Mình dùng `fscanf(file, "%d %99s %f", ...)` để giới hạn chuỗi string đầu vào, như vậy tránh được lỗi Buffer Overflow (tràn bộ đệm) khá hay bị dính trong C. Mọi thứ khá hoàn hảo!
