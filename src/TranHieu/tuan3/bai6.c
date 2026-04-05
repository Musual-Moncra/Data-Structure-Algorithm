/* * =========================================================================
 * NOTE: PHÂN TÍCH ĐỘ PHỨC TẠP THỜI GIAN (TIME COMPLEXITY) - BÀI TẬP 6
 * =========================================================================
 * Thuật toán: Tính lũy thừa $a^n$ bằng phương pháp Đệ quy tuyến tính (Linear Recursion).
 * * 1. Thiết lập phương trình đệ quy:
 * - Trường hợp cơ sở (Base case): Nếu $n = 0$, thời gian thực thi là hằng số $O(1)$.
 * - Bước đệ quy: Để tính $T(n)$, máy phải tính $T(n-1)$ rồi thực hiện 1 phép nhân.
 * => Công thức tổng quát: $T(n) = T(n-1) + 1$
 * * 2. Giải phương trình bằng phương pháp thế (Substitution Method):
 * $T(n) = T(n-1) + 1$
 * $T(n) = [T(n-2) + 1] + 1 = T(n-2) + 2$
 * $T(n) = [T(n-3) + 1] + 2 = T(n-3) + 3$
 * ...
 * $T(n) = T(n-k) + k$
 * * Khi $k = n$, ta có: $T(n) = T(0) + n$
 * * 3. Kết luận:
 * - Độ phức tạp thời gian: $T(n) = O(n)$ (Tuyến tính).
 * - Giải thích: Số lần gọi hàm đệ quy đúng bằng giá trị của số mũ $n$.
 * - Độ phức tạp không gian (Space Complexity): $O(n)$ do hệ thống phải lưu trữ 
 * $n$ lời gọi hàm vào Stack cho đến khi chạm tới trường hợp cơ sở.
 * =========================================================================
 */

double recursive_power(double a, int n) {
    if (n == 0) {
        return 1;
    }
    return a * recursive_power(a, n - 1);
}