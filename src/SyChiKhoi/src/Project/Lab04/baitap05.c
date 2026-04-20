#include <stdio.h>
#include <stdlib.h>

struct Student {
    int id;
    char name[30];
    float gpa;
};

int count_lines(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) { 
        printf("Khong the mo duoc file %s\n", filename);
        return 0; 
    }

    int count = 0;
    char c;
    while ((c = fgetc(f)) != EOF) {
        if (c == '\n') {
            count++;
        }
    }
    
    fclose(f); 
    return count;
}

void load_students(char *filename, struct Student students[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Khong the mo duoc du lieu file.\n");
        return;
    }

    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%d %s %f", &students[i].id, students[i].name, &students[i].gpa);
        i++;
    }
    fclose(f); 
}

void print_students(struct Student students[], int n) {
    printf("========== DANH SACH DOC TU TXT ==========\n");
    printf("ID\t Name\t Score\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %s\t %.2f\n", students[i].id, students[i].name, students[i].gpa);
    }
}

int main() {
    char *filename = "students.txt";
    int n = count_lines(filename);
    if (n == 0) {
        return 1;
    }
    
    struct Student students[n];
    
    load_students(filename, students);
    print_students(students, n);

    return 0;
}

/* ==============================================================================
   GIẢI THÍCH CHI TIẾT CÁC HÀM XỬ LÝ FILE I/O MẪU BÊN TRÊN
   ==============================================================================
   Hàm count_lines(): Đếm tổng số dòng có trong file
   - MỞ FILE: fopen(..., "r") với "r" (read) dùng để đọc file đã tồn tại.
   - KIỂM TRA LỖI: Cực kỳ quan trọng. f sẽ bị NULL nếu file không tồn tại.
   - ĐỌC TỪNG KÝ TỰ: Hàm fgetc() đọc từng ký tự một cho đến khi đụng EOF (End Of File).
     Nếu đụng ký tự xuống dòng '\n' thì tăng biến count lên 1 (đếm số dòng).
   - ĐÓNG FILE: Xong việc phải đóng nắp lại bằng fclose(f) trả tài nguyên về HĐH.

   Hàm load_students(): Hút dữ liệu từ file ra mảng
   - feof(f): Kiểm tra xem vòng lặp đọc file đã chạm lủng đáy (cuối file) hay chưa.
   - fscanf(): Thay vì dừng lại chờ người gõ phím như scanf(), nó nhảy thẳng vào 
     file để móc dữ liệu. Nó tự động ngắt chữ dựa vào dấu cách / enter.

   Hàm main(): Luồng chạy tổng quan
   - BƯỚC A: Gọi hàm count_lines() để đếm tổng số dòng -> Xác định tổng số lượng sinh viên.
   - BƯỚC B: Khởi tạo mảng vừa khít (kích thước n) để không bị hụt và không dư code.
   - BƯỚC C: Rút ruột file ném vào mảng.
   - BƯỚC D: Vòng lặp for quen thuộc in danh sách ra kiểm chứng màn hình.
================================================================================= */
