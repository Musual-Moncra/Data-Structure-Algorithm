/* * =========================================================================
 * NOTE: PHÂN TÍCH ĐỘ PHỨC TẠP THỜI GIAN (TIME COMPLEXITY) - BÀI TẬP 7
 * =========================================================================
 * Thuật toán: Lũy thừa nhanh (Binary Exponentiation) - Chia để trị.
 * * 1. Cơ chế: 
 * - Nếu $n$ chẵn: $a^n = (a^{n/2})^2$. Máy tính chỉ cần tính $a^{n/2}$ một lần.
 * - Nếu $n$ lẻ: $a^n = a * a^{n-1}$.
 * * 2. Phân tích:
 * - Sau mỗi bước đệ quy (hoặc tối đa 2 bước), giá trị $n$ giảm đi một nửa.
 * - Số lần gọi hàm tỷ lệ thuận với số lần chia đôi của $n$.
 * * 3. Kết luận:
 * - Độ phức tạp thời gian: $T(n) = O(\log n)$.
 * - So sánh: Nhanh hơn rất nhiều so với $O(n)$ của Bài 6 khi $n$ lớn.
 * =========================================================================
 */
double power(double a, int n) {
    if (n == 0) return 1;
    if (n % 2 == 0) {
        double half = power(a, n / 2);
        return half * half;
    } else {
        return a * power(a, n - 1);
    }
}