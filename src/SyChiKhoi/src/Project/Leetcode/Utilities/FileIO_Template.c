#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* ==============================================================================
   BÍ KÍP BỎ TÚI (CHEAT SHEET) CHO THAO TÁC FILE TRONG C (FILE I/O)
   ==============================================================================
   1. Mở file (fopen): 
      - "w" (Write):  Xóa sạch nội dung cũ, viết lại từ đầu. (Cực ngầu nhưng dễ bay màu data)
      - "a" (Append): Ghi NỐI TIẾP vào cuối file. Không xóa data cũ. (Safe)
      - "r" (Read):   Chỉ đọc file. Không làm hư dữ liệu.
   2. Kiểm tra Null: if (f == NULL)
   3. Ghi / Đọc:     fprintf (Ghi) / fscanf hoặc fgets (Đọc)
   4. Đóng file:     fclose(f)
================================================================================= */

// [CHỨC NĂNG 1] - Ghi nối tiếp Dữ liệu "Vừa được thêm vào" xuống ổ cứng
void the_them_du_lieu_vao_file(const char* filename, const char* new_data) {
    // Mở ở chế độ "a" (Append). Đặc biệt nếu file txt chưa ra đời, hệ điều hành tự tạo mới!
    FILE *f = fopen(filename, "a"); 
    if (f == NULL) {
        printf("Loi xay ra! Khong the thao tac voi o cung.\n");
        return;
    }
    
    // Ghi y hệt như printf, có cả \n xuống dòng cho dữ liệu kế tiếp
    fprintf(f, "%s\n", new_data);
    printf(">> [+] Da luu dong chu: '%s' the vao cuoi file.\n", new_data);
    
    fclose(f); // CHỐT SỔ: Phải đóng thì dữ liệu mới thực sự in xuống ổ đĩa, nếu không nó treo ở RAM.
}

// [CHỨC NĂNG 2] - Đọc file và Truy xuất (Tìm kiếm) - Phù hợp với tính chất của mục Search
void doc_va_truy_xuat_file(const char* filename, const char* search_word) {
    // Mở chế độ "r" để đọc thật an toàn
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("File rong hoac khong ton tai!\n");
        return;
    }

    printf("\n---------- TRICH XUAT NHUNG GI CHUA TRONG FILE ----------\n");
    char line[100]; // Tạo bộ nhớ đệm 100 chữ cái cho 1 dòng
    int found = 0;
    int line_num = 1;

    // Lệnh fgets sẽ gắp tứng dòng chữ trọn vẹn trong file, cho tới khi đụng cuối file (NULL) thì dừng lặp
    while (fgets(line, sizeof(line), f) != NULL) {
        
        // Mẹo vặt: lúc fgets nó nuốt luôn cả dấu enter (xuống dòng) \n ở cuối. Lệnh dưới đây cắt bỏ nó đi
        line[strcspn(line, "\n")] = 0;
        
        printf("Dong %d: %s\n", line_num, line);
        
        // [TRUY XUẤT TÌM KIẾM]: Hàm strstr (trong thư viện string.h) dùng để "Dò mìn" 
        // nó sẽ xét xem chữ search_word có lẩn trốn ở đâu đó trong dòng 'line' này hay không
        if (strstr(line, search_word) != NULL) {
            printf("   => [BINGO!] Tim thay cai ban can tim (%s) o dong so %d!\n", search_word, line_num);
            found = 1;
        }
        line_num++;
    }

    if (found == 0) {
         printf("   => Khong tim thay '%s' trong file nay.\n", search_word);
    }

    fclose(f);
}

int main() {
    // Tên file ảo để làm ví dụ
    const char* filename = "demo_dsa_db.txt";
    
    printf("--- B1: THU TAI THEM DU LIEU VAO FILE ---\n");
    the_them_du_lieu_vao_file(filename, "MaSV: 111 - Nguyen Thai Bao - Diem: 8.0");
    the_them_du_lieu_vao_file(filename, "MaSV: 222 - Sy Chi Khoi - Diem: 9.5");
    the_them_du_lieu_vao_file(filename, "MaSV: 333 - Test Thu Thuat"); // <-- Đây là dữ liệu Vừa Được Thêm Vào
    
    printf("\n--- B2: THU TAI MO FILE TEXT TU O CUNG & QUET SEARCH ---\n");
    // Nhờ máy đọc lại file và truy xuất xem đồng chí "Sy Chi Khoi" trốn ở đâu
    doc_va_truy_xuat_file(filename, "Sy Chi Khoi");
    
    return 0;
}
