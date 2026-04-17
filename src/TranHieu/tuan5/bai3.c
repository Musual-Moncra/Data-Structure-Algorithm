/*
Viết thêm hàm sắp xếp danh sách sinh viên theo thứ tự tăng dần của tên (không phân biệt
chữ hoa chữ thường), nếu tên giống nhau thì sắp xếp theo thứ tự giảm dần của điểm
(score).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// 1. Hàm load danh sách từ file
int loadStudents(Student students[]) {
    // Lưu ý: Đường dẫn này phải khớp với cấu trúc thư mục có trong folder
    FILE *f = fopen("src/TranHieu/tuan5/students.txt", "r");
    if (f == NULL) {
        printf("Loi: Khong tim thay file students.txt!\n");
        return 0;
    }

    int count = 0;
    // Dùng 0123456789 thay vì 0-9 để tuân thủ chuẩn C nghiêm ngặt, tránh IDE báo dòng đỏ
    while (fscanf(f, "%d %49[^0123456789] %f", &students[count].id, students[count].name, &students[count].grade) == 3) {
        // dấu gạch đỏ ở %49[^0123456789] là do IDE không nhận dạng được ký tự đặc biệt, nhưng vẫn chạy đc
        // CHÚ Ý LỖI LOGIC: Cắt khoảng trắng thừa ở đuôi do "%49[^0123456789]" ăn sát đến trước số
        // Nếu không cắt đi thì hàm strrchr(..., ' ') sẽ lấy khoảng trắng cuối này làm phần Tên -> Lỗi thuật toán Sort!
        int len = strlen(students[count].name);
        while (len > 0 && students[count].name[len - 1] == ' ') {
            students[count].name[len - 1] = '\0';   
            len--;
        }

        count++;

        /*
        // Dùng biến tạm để đọc từng từ trong tên
    char tempName[20];

    // BƯỚC 1: Đọc số ID đầu tiên
    while (fscanf(f, "%d", &students[count].id) == 1) {
        
        // BƯỚC 2: Xóa rỗng chuỗi name trước khi ghép
        students[count].name[0] = '\0'; 

        // BƯỚC 3: Đọc các từ tiếp theo cho đến khi gặp điểm số (số thực)
        // Ta dùng fscanf đọc 1 chuỗi, nếu không phải số thì đó là một phần của tên
        while (fscanf(f, "%s", tempName) == 1) {
            // Kiểm tra nếu từ vừa đọc là số (điểm số) thì dừng
            // (Mẹo: điểm số thường bắt đầu bằng chữ số)
            if (tempName[0] >= '0' && tempName[0] <= '9') {
                students[count].grade = atof(tempName); // Chuyển chuỗi điểm thành số thực
                break;
            } else {
                // Nếu là chữ (họ hoặc tên đệm), ta ghép vào
                strcat(students[count].name, tempName);
                strcat(students[count].name, " "); // Thêm dấu cách giữa các chữ
            }
        }

        // BƯỚC 4: Xóa dấu cách dư ở cuối tên sau khi ghép xong
        int len = strlen(students[count].name);
        if (len > 0) students[count].name[len - 1] = '\0';

        count++;
    }
        */
    }
    fclose(f);
    return count;
}

// 2. Hàm lấy Tên (phần sau khoảng trắng cuối cùng)
const char* getFirstName(const char* fullName) {
    const char* lastSpace = strrchr(fullName, ' '); // Tìm vị trí khoảng trắng cuối cùng
    if (!lastSpace) return fullName; // Nếu không có khoảng trắng, coi cả chuỗi là tên
    return lastSpace + 1; // Trả về phần chữ đứng sau khoảng trắng
}

// 3. Hàm sắp xếp Chọn trực tiếp (Selection Sort) theo yêu cầu
void sortStudentsDetailed(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        int target_idx = i;

    /*
    Trong thuật toán Sắp xếp chọn (Selection Sort), biến target_idx đóng vai trò cực kỳ quan trọng với 3 tác dụng chính:

1. Lưu trữ "Vị trí tốt nhất" (The Best Candidate):

Tại mỗi vòng lặp i, biến này dùng để ghi nhớ vị trí của phần tử thỏa mãn điều kiện sắp xếp nhất (nhỏ nhất nếu xếp tăng dần, hoặc lớn nhất nếu xếp giảm dần) trong đoạn chưa sắp xếp.

Nó giúp chương trình không bị "quên" mục tiêu trong khi đang duyệt qua hàng loạt phần tử khác.

2. Giảm thiểu số lần Hoán vị (Minimize Swaps):

Đây là tác dụng về hiệu suất. Thay vì đổi chỗ liên tục như Bubble Sort, ta chỉ ghi chú lại vị trí.

Kết quả: Trong mỗi vòng lặp lớn, ta chỉ thực hiện duy nhất 1 lần hoán vị (nếu tìm thấy người tốt hơn). Việc này giúp giảm tải cho bộ nhớ và CPU khi làm việc với các kiểu dữ liệu nặng (như struct Student có nhiều thông tin).

3. Làm điều kiện để quyết định hành động:

Dựa vào giá trị của target_idx, ta biết được có cần phải hoán đổi dữ liệu hay không.

Nếu sau khi kết thúc vòng lặp con mà target_idx == i, nghĩa là phần tử hiện tại đã đứng đúng vị trí rồi, máy tính sẽ bỏ qua lệnh swap, giúp mã nguồn chạy thông minh hơn.
    */
        for (int j = i + 1; j < count; j++) {
            
            // So sánh tên không phân biệt hoa thường
            const char* nameJ = getFirstName(students[j].name);
            const char* nameTarget = getFirstName(students[target_idx].name);
            
            int resName = stricmp(nameJ, nameTarget);
            
            if (resName < 0) {
                // tên nào đứng trước thì lấy
                target_idx = j;
            } 
            else if (resName == 0) {
                if (students[j].grade > students[target_idx].grade) {
                    target_idx = j;
                }
                /*
                // Nếu Tên trùng, so sánh cả Họ và Tên
                int resFull = stricmp(students[j].name, students[target_idx].name);
                if (resFull < 0) {
                    target_idx = j;
                }
                else if (resFull == 0) {
                    // Nếu trùng cả Họ Tên, so sánh điểm giảm dần
                    if (students[j].grade > students[target_idx].grade) {
                        target_idx = j;
                    }
                }
                */
            }
        }
        
        // Hoán vị nguyên struct
        if (target_idx != i) {
            Student temp = students[i];
            students[i] = students[target_idx];
            students[target_idx] = temp;
        }
    }
}

// 4. Hàm xuất danh sách
void displayStudents(Student students[], int n) {
    printf("\n%-10s %-20s %-10s\n", "MSSV", "Ho Ten", "Diem");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%-10d %-20s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
    }
}

int main() {
    Student list[100];
    int n = loadStudents(list);

    if (n > 0) {
        printf("--- DANH SACH BAN DAU ---");
        displayStudents(list, n);

        // Gọi đúng tên hàm đã định nghĩa phía trên
        sortStudentsDetailed(list, n);

        printf("\n--- DANH SACH SAU KHI SAP XEP (Ten tang, Diem giam) ---");
        displayStudents(list, n);
    }

    return 0;
}