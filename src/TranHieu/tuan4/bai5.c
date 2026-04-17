/*
Viết hàm đọc dữ liệu sinh viên từ tập tin students.txt và hiển thị danh sách sinh viên ra
màn hình.
Tên hàm: loadStudents(Student students[])
Cấu trúc file students.txt
123 Binh 7.50
124 An 7.50
125 Khoa 8.50
126 Thanh 9.50
127 Nguyen 5.50
128 Mai 6.70
129 Hung 7.30
130 Viet 5.90 
*/

#include <stdio.h>
// #include <stdlib.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

void loadStudents(Student students[]) {
    /*
    "r"
Ý nghĩa: Tham số thứ hai là chế độ mở file (Mode).

"r" (Read): Chỉ mở để đọc. Nếu file không tồn tại, hàm sẽ trả về NULL.

Các mode khác thường gặp:

"w" (Write): Mở để ghi mới (xóa hết nội dung cũ).

"a" (Append): Mở để ghi thêm vào cuối file*/
    FILE *f = fopen("src/TranHieu/tuan4/students.txt", "r");
    
    // Kiểm tra xem file có tồn tại không
    if (f == NULL) {
        printf("Loi: Khong tim thay file students.txt!\n");
        return;
        /* if (f == NULL) {
    printf("Loi file!");
    exit(1); // Hàm này nằm trong stdlib.h đấy!
}*/
    }

    int i = 0;
    printf("%-10s %-15s %-10s\n", "MSSV", "Ho Ten", "Diem");
    printf("---------------------------------------\n");

    /*
    1. fscanf(f, "%d %s %f", ...) là gì?
    Đây là một "máy quét" có chọn lọc. Nó nhìn vào file f và tìm đúng "khuôn mẫu" mà bạn yêu cầu:
    %d: Nhặt một con số nguyên (bỏ vào id).
    %s: Nhặt một chuỗi ký tự (bỏ vào name).
    %f: Nhặt một con số thực (bỏ vào grade).
    2. Tại sao lại là == 3?
    Đây là phần thông minh nhất. Hàm fscanf trả về số lượng món đồ mà nó đã nhặt thành công.
    Nếu nó nhặt được đủ 1 cái ID, 1 cái Tên, và 1 cái Điểm $\rightarrow$ Nó trả về 3.
    Nếu dòng cuối cùng bị thiếu dữ liệu (ví dụ chỉ có ID và Tên nhưng không có Điểm) $\rightarrow$ Nó trả về 2.
    Nếu đã hết file, không còn gì để nhặt $\rightarrow$ Nó trả về -1 (EOF).
    Ý nghĩa: while (... == 3) có nghĩa là: "Chừng nào bạn vẫn còn nhặt được đủ bộ 3 món (ID, Tên, Điểm) thì hãy tiếp tục làm việc".
    3. Các tham số & và không có &
    Hiếu chú ý chỗ này kẻo bị thầy bắt bẻ nhé:
    &students[i].id và &students[i].grade: Phải có dấu & vì đây là biến kiểu số cơ bản. Bạn cần đưa "địa chỉ nhà" của biến đó để fscanf ship dữ liệu vào đúng chỗ.
    students[i].name: Không có dấu &. Vì trong C, tên mảng (chuỗi) bản thân nó đã là một địa chỉ rồi. Bạn không cần đưa thêm dấu & nữa.*/
    while (fscanf(f, "%d %s %f", &students[i].id, students[i].name, &students[i].grade) == 3) {
        printf("%-10d %-15s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
        i++;
        // while (feof(f)) -> Hàm kiểm tra xem đã hết file chưa, thường cuối file có ký tự EOF 
    }

    fclose(f); // Đóng file sau khi dùng xong
}

int main() {
    Student list[100];
    
    loadStudents(list);

    return 0;
}