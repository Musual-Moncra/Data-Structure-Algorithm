#include <stdio.h>
#include <stdbool.h>
#include <string.h>

/**
 * ============================================================================
 * LAB 01: ĐỆ QUY (RECURSION)
 * ============================================================================
 * Ghi chú học thuật:
 * Đệ quy là phương pháp giải quyết bài toán bằng cách chia bài toán lớn thành
 * một hoặc nhiều bài toán con có cùng cấu trúc nhưng kích thước nhỏ hơn, cho
 * đến khi bài toán con đủ nhỏ để có thể giải trực tiếp (trường hợp cơ sở - 
 * base case). Mọi hàm đệ quy đều cần có điều kiện dừng (base case) để tránh lặp vô hạn 
 * (Stack Overflow).
 * ============================================================================
 */

// ----------------------------------------------------------------------------
// Bài tập 1: Viết hàm in ra n dấu * trên cùng một dòng.
// - Base case: Khi n chạm mốc 0, hàm sẽ dùng lệnh return để kết thúc nhánh đệ quy. 
//              Không có tiến trình in nào xảy ra ở n=0.
// - Recursive step: Lùi lại gọi chính nó với n-1, nhằm đẩy quá trình in ấn dồn lại.
//                   Cuối cùng sẽ in ra "*" ở thời điểm Return (tức là n dấu).
// ----------------------------------------------------------------------------
void inSao(int n) {
    if (n == 0) return; // Trường hợp cơ sở (Điều kiện dừng)
    inSao(n - 1);       // Đệ quy: in n-1 dấu * trước
    printf("* ");       // In thêm 1 dấu * cuối cùng để chuẩn hoá dòng
}

// ----------------------------------------------------------------------------
// Bài tập 2: Viết hàm in ra tam giác * (bằng cách đệ quy).
// - Base case: n == 0, dừng lại trả về.
// - Recursive step: Gọi đệ quy hàm inTamGiac với n-1 để tạo 
//                   cấu trúc tam giác đỉnh bé trước, rồi đến dòng dài nhất in ở cuối.
// ----------------------------------------------------------------------------
void inTamGiac(int n) {
    if (n == 0) return; // Trường hợp cơ sở
    inTamGiac(n - 1);   // Tìm cách in phần đỉnh hình tam giác kích thước n-1
    inSao(n);           // In phần đáy của tam giác thời tại (có n dấu *)
    printf("\n");       // Lệnh tạo cấu trúc dòng
}

// ----------------------------------------------------------------------------
// Bài tập 3: Viết hàm in ra tam giác * ngược (bằng cách đệ quy).
// Khác với bài 2, ta sẽ in dòng có độ dài tối đa trước, rồi mới gọi Đệ quy.
// ----------------------------------------------------------------------------
void inTamGiacNguoc(int n) {
    if (n == 0) return;
    inSao(n);               // In dòng có n dấu * đầu tiên (đỉnh ngược)
    printf("\n");
    inTamGiacNguoc(n - 1);  // Đệ quy in các dòng hẹp hơn tiếp theo
}

// ----------------------------------------------------------------------------
// Bài tập 4: Biểu diễn nhị phân (binary) của một số nguyên dương n.
// - Base Case: n == 0 kết thúc.
// - Bản chất: Phép chia 2 cho đến 0, lấy số dư đùn lên (LIFO của Stack Đệ quy). 
// ----------------------------------------------------------------------------
void inNhiPhan(int n) {
    if (n == 0) return;
    inNhiPhan(n / 2);     // Đệ quy chia đôi tìm bit cao hơn
    printf("%d", n % 2);  // In ra phần dư bit thấp xếp sau
}

// Helper giải quyết trường hợp viền n=0
void bai4_NhiPhan(int n) {
    if (n == 0) printf("0");
    else inNhiPhan(n);
}

// ----------------------------------------------------------------------------
// Bài tập 5: Chuyển số giây thành giờ, phút, giây đệ quy.
// - Ghi chú học thuật: Ta kết hợp khái niệm Level trong đệ quy để phân tầng 
//   đơn vị (2: Giây -> 1: Phút -> 0: Giờ). Mỗi lần chia lấy dư 60 và qua level.
// ----------------------------------------------------------------------------
void chuyenDoiThoiGian(int giatri, int level) {
    if (level == 0) {
        if (giatri > 0) printf("%d giờ ", giatri);
        return;
    }
    
    chuyenDoiThoiGian(giatri / 60, level - 1); // Đạt đến level lớn hơn (phút, giờ)
    
    int hienTai = giatri % 60; // Gía trị của level hiện tại
    if (level == 1 && (hienTai > 0 || giatri / 60 > 0)) {
        printf("%d phút ", hienTai);
    } else if (level == 2) {
        printf("%d giây", hienTai);
    }
}

void bai5_ThoiGian(int giay) {
    if (giay == 0) printf("0 giây");
    else chuyenDoiThoiGian(giay, 2); 
}

// ----------------------------------------------------------------------------
// Bài tập 6: Kiểm tra số nguyên tố đệ quy.
// Sử dụng i làm biến tiến độ (iterator). Nếu có bất kỳ phép chia hết nào -> false.
// Kỹ thuật này giả lập vòng lặp while/for bằng các tầng đệ quy nhánh.
// ----------------------------------------------------------------------------
bool kiemTraNguyenTo(int n, int i) {
    if (n <= 1) return false;      
    if (i * i > n) return true;    // Tối ưu thuật toán ở bậc căn n 
    if (n % i == 0) return false;  // Chia hết cho 1 biến đếm trong giới hạn -> Trượt SNT
    return kiemTraNguyenTo(n, i + 1);
}

// ----------------------------------------------------------------------------
// Bài tập 7: Tính tổng các chữ số của một số nguyên dương n.
// Dùng phép (n % 10) bóc tách số tận cùng, phần đệ quy lo cho (n / 10).
// ----------------------------------------------------------------------------
int tongCacChuSo(int n) {
    if (n == 0) return 0;
    return (n % 10) + tongCacChuSo(n / 10);
}

// ----------------------------------------------------------------------------
// Bài tập 8: Xuất ngược một số nguyên dương n.
// ----------------------------------------------------------------------------
void xuatNguoc(int n) {
    if (n < 10) {
        printf("%d", n);
        return;
    }
    printf("%d", n % 10); // Xuất ngay con số nhỏ nhất trước khi đi Đệ Quy
    xuatNguoc(n / 10);
}

// ----------------------------------------------------------------------------
// Bài tập 9: Đếm số lượng chữ số (digits) bằng Đệ quy
// Recursive Step là cộng 1 cho mỗi lần có thể chia 10.
// ----------------------------------------------------------------------------
int demChuSoDeQuy(int n) {
    if (n < 10) return 1;
    return 1 + demChuSoDeQuy(n / 10);
}

// ----------------------------------------------------------------------------
// Bài tập 10: Đếm số chữ số của n bằng vòng lặp.
// Ghi chú học thuật: Việc dùng While (Iteration) cho bài này tối ưu không gian hơn
// so với Recursion (chiếm bộ nhớ Stack call tỉ lệ thuận số chữ số).
// ----------------------------------------------------------------------------
int demChuSoVongLap(int n) {
    int dem = 0;
    if (n == 0) return 1;
    while (n > 0) {
        dem++;
        n /= 10;
    }
    return dem;
}

// ----------------------------------------------------------------------------
// Bài tập 11: Tìm phần tử nhỏ nhất (min) trong mảng đệ quy.
// Khái niệm Divide & Conquer, ta tách 1 phần tử của danh sách để đọ với toàn
// bộ Min của những phần tử còn lại. Tốn O(N) Space stack calls.
// ----------------------------------------------------------------------------
int timMinDeQuy(int a[], int n) {
    if (n == 1) return a[0]; 
    int minRest = timMinDeQuy(a, n - 1);
    return (a[n - 1] < minRest) ? a[n - 1] : minRest;
}

// ----------------------------------------------------------------------------
// Bài tập 12: Tính tổng n số tự nhiên đầu tiên đệ quy.
// S(n) = n + S(n-1) vói S(1) = 1.
// ----------------------------------------------------------------------------
int timTongN(int n) {
    if (n <= 1) return n;
    return n + timTongN(n - 1);
}

// ----------------------------------------------------------------------------
// Bài tập 13: Kiểm tra từ đặng đọc ngược xuôi giống nhau (Palindrome) đệ quy.
// Sử dụng Left(l) và Right(r) thu hẹp dần dần đến ngưỡng tâm chuỗi (l >= r).
// ----------------------------------------------------------------------------
bool kiemTraPalindrome(char str[], int l, int r) {
    if (l >= r) return true; // Cắt nhau tức là hoàn tất xét không tì vết.
    if (str[l] != str[r]) return false; // Triệt tiêu ngay khi 1 bên sai.
    return kiemTraPalindrome(str, l + 1, r - 1);
}

// ----------------------------------------------------------------------------
// Bài tập 14: Tổng các phần tử trong mảng.
// ----------------------------------------------------------------------------
int tongMangDeQuy(int a[], int n) {
    if (n == 0) return 0;
    if (n == 1) return a[0];
    return a[n - 1] + tongMangDeQuy(a, n - 1);
}

// ----------------------------------------------------------------------------
// Bài tập 15: Tìm giá trị lớn nhất trong mảng đệ quy.
// Tương đường Bài 11 nhưng đổi dấu đối sánh Max.
// ----------------------------------------------------------------------------
int timMaxDeQuy(int a[], int n) {
    if (n == 1) return a[0];
    int maxRest = timMaxDeQuy(a, n - 1);
    return (a[n - 1] > maxRest) ? a[n - 1] : maxRest;
}

// ============================================================================
// Hàm main để test mã
// ============================================================================
int main() {
    printf("========== LAB 01: DEMO RECURSION ==========\n\n");

    printf("Bai 1 - In n dau *: n=6 -> "); inSao(6); printf("\n\n");
    printf("Bai 2 - Tam giac * (n=6):\n"); inTamGiac(6); printf("\n");
    printf("Bai 3 - Tam giac * nguoc (n=6):\n"); inTamGiacNguoc(6); printf("\n");
    printf("Bai 4 - Nhi phan cua 13: "); bai4_NhiPhan(13); printf("\n\n");
    printf("Bai 5 - Chuyen doi 3665 giay: "); bai5_ThoiGian(3665); printf("\n\n");
    
    printf("Bai 6 - Nguyen to (17): %s\n", kiemTraNguyenTo(17, 2) ? "Co" : "Khong");
    printf("Bai 6 - Nguyen to (18): %s\n\n", kiemTraNguyenTo(18, 2) ? "Co" : "Khong");
    
    printf("Bai 7 - Tong chu so cua 1980: %d\n\n", tongCacChuSo(1980));
    printf("Bai 8 - Xuat nguoc 1980: "); xuatNguoc(1980); printf("\n\n");
    
    printf("Bai 9 - Dem chu so bang de quy (44253): %d\n", demChuSoDeQuy(44253));
    printf("Bai 10 - Dem chu so bang vong lap (44253): %d\n\n", demChuSoVongLap(44253));

    int a[] = {5, 2, 9, 1, 7, 3};
    int nArr = sizeof(a) / sizeof(a[0]);
    printf("Mang A: [ 5 2 9 1 7 3 ]\n");
    printf("Bai 11 - Min trong mang: %d\n", timMinDeQuy(a, nArr));
    printf("Bai 14 - Tong mang: %d\n", tongMangDeQuy(a, nArr));
    printf("Bai 15 - Max trong mang: %d\n\n", timMaxDeQuy(a, nArr));

    printf("Bai 12 - Tong 5 so tu nhien dau tien: %d\n\n", timTongN(5));

    char str1[] = "radar";
    char str2[] = "hello";
    printf("Bai 13 - Palindrome ('radar'): %s\n", kiemTraPalindrome(str1, 0, strlen(str1)-1) ? "True" : "False");
    printf("Bai 13 - Palindrome ('hello'): %s\n\n", kiemTraPalindrome(str2, 0, strlen(str2)-1) ? "True" : "False");

    printf("============================================\n");
    return 0;
}
