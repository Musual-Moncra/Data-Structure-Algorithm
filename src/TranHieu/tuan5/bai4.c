/*
Viết chương trình đọc thông tin sinh viên từ tập tin students.txt và hiển thị menu cho
phép người dùng chọn cột cần sắp xếp (cột name hoặc score), thứ tự sắp xếp
(tăng/increasing hoặc giảm/descending), sau đó in danh sách sinh viên sau khi sắp xếp ra
màn hình và lưu danh sách được sắp xếp vào tập tin students_sorted.txt
Hint: sử dụng con trỏ hàm (function pointer) để tổng quát việc sắp xếp theo cột bất kỳ
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    int id;
    char name[50];
    float grade;
} Student;

// 1. Hàm lấy Tên (phần sau khoảng trắng cuối cùng)
const char* getFirstName(const char* fullName) {
    const char* lastSpace = strrchr(fullName, ' ');
    /*Đầu vào: Một chuỗi (fullName) và một ký tự cần tìm (khoảng trắng ' ').
    Đầu ra: Nó trả về một con trỏ (pointer) trỏ đến vị trí của dấu cách đó. 
    Nếu không tìm thấy dấu cách nào, nó trả về NULL.
    
    strchr(s, ' '): Tìm dấu cách đầu tiên (thường dùng để lấy Họ).
    strrchr(s, ' '): Tìm dấu cách cuối cùng (thường dùng để lấy Tên).*/ 
    if (!lastSpace) return fullName; 
    return lastSpace + 1; 
}

// --- CÁC HÀM SO SÁNH (Dùng cho con trỏ hàm) ---

int compareNameInc(Student a, Student b) {
    return stricmp(getFirstName(a.name), getFirstName(b.name)) > 0;
}

int compareNameDec(Student a, Student b) {
    return stricmp(getFirstName(a.name), getFirstName(b.name)) < 0;
}

int compareGradeInc(Student a, Student b) {
    return a.grade > b.grade;
}

int compareGradeDec(Student a, Student b) {
    return a.grade < b.grade;
}

// --- HÀM TỔNG QUÁT ---

// Hàm sắp xếp dùng con trỏ hàm: int (*cmp)(Student, Student)
void sortStudents(Student students[], int n, int (*cmp)(Student, Student)) {
    /*"Rã đông" cú pháp int (*cmp)(...)Tại sao nó không đơn giản là int cmp?
     Vì máy tính cần biết cái xưởng đó làm ăn thế nào để nó còn chuẩn bị máy móc:
     int: Để máy biết cái xưởng này sẽ trả ra kết quả là một số nguyên.
     (*cmp): Cái ngoặc này để "hét" lên với máy tính rằng: "Đây là một biến chứa 
     địa chỉ xưởng, không phải xưởng thật đâu nhé!".
     (Student, Student): Để máy biết khi máy gọi đến cái địa chỉ này, nó cần phải 
     mang theo 2 ông sinh viên đi cùng.
     
     So sánh cho dễ nhớ
     Kiểu biến          Lưu cái gì?                  Ví dụ
     int x              Con số                      x = 10;
     int *p             Địa chỉ của con số          p = &x;
     int (*f)()         Địa chỉ của hành động      f = compareNameInc;*/
    
    // Selection Sort
    for (int i = 0; i < n - 1; i++) {
        int target_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (cmp(students[target_idx], students[j])) {
                target_idx = j;
            }
        }
        if (target_idx != i) {
            Student temp = students[i];
            students[i] = students[target_idx];
            students[target_idx] = temp;
        }
    }
}

// --- CÁC HÀM XỬ LÝ FILE & HIỂN THỊ ---

int loadStudents(Student students[]) {
    FILE *f = fopen("src/TranHieu/tuan5/students.txt", "r");
    if (!f) return 0;
    int count = 0;
    while (fscanf(f, "%d", &students[count].id) == 1)
    /*
    Nhiệm vụ: Tìm số nguyên đầu tiên (ID).
    
    Cơ chế: fscanf sẽ trả về 1 nếu nó đọc được đúng 1 số nguyên. Nếu hết file 
    hoặc gặp chữ, nó sẽ trả về số khác và vòng lặp dừng lại.
    
    Tại đây: Nó bốc được số 101 bỏ vào id   */ {
        students[count].name[0] = '\0';
        /*
        NOTE: LỆNH "XÓA BẢNG" TRONG C
        
        1. \0 là gì?
            Lập trình viên gọi đây là Null Terminator (Ký tự kết thúc chuỗi). 
            Máy tính sẽ đọc chuỗi từ trái sang phải và dừng lại ngay lập tức 
            khi thấy ký tự này.
        2. Công dụng của việc gán vào vị trí [0]
            Tạo chuỗi rỗng: Biến cái tên trở thành một trang giấy trắng hoàn toàn 
            (độ dài = 0).
            Xóa "rác" bộ nhớ: RAM trên con LOQ của bạn đôi khi chứa những ký tự 
            cũ từ các chương trình khác. Dòng này giúp chặn đứng đống rác đó, 
            không cho nó dính vào tên sinh viên.
        3. Tại sao phải làm vậy trước khi dùng strcat?
        Hàm strcat (hũ keo dán chuỗi) sẽ đi tìm cái \0 đầu tiên nó thấy để bắt đầu 
        dán chữ mới vào.Nếu có dòng này: Máy thấy \0 ở ngay đầu --> 
        Dán tên "Nguyen..." vào ngay từ đầu --> ĐÚNG.
        Nếu không có: Máy đi tìm \0 trong đống rác --> Dán tên vào sau 
        đống rác đó --> SAI/LỖI.
        */
        char word[20];
        while (fscanf(f, "%s", word) == 1) {
        /*
        Chữ f bên trong ngoặc là gì?
        Dòng code của bạn là: fscanf(f, "%s", word)
        
        Cái chữ f đầu tiên nằm trong ngoặc chính là Con trỏ tập tin (File Pointer).

        Trước đó, bạn đã có dòng lệnh FILE *f = fopen(...);

        Chữ f này giống như một chiếc chìa khóa hoặc một địa chỉ dẫn đến file 
        students.txt trên ổ cứng.

        Bạn phải đưa "chìa khóa" f này vào thì hàm fscanf mới biết nó cần phải 
        mở file nào để đọc.

        Tại sao lại có == 1 và vòng lặp while?
        Đây là cách kiểm tra xem máy tính đã đọc xong file hay chưa:

        Cơ chế của fscanf: Hàm này trả về số lượng món đồ mà nó đọc được thành công.

        Ở đây bạn dùng %s để đọc 1 từ (word).

        Nếu máy tính đọc được 1 từ, nó trả về số 1.

        Nếu nó đụng tới cuối file (hết chữ để đọc) hoặc gặp lỗi, nó sẽ trả về 
        0 hoặc một giá trị đặc biệt là EOF (End Of File).*/
            if (isdigit(word[0])) {
            /*
            isdigit là gì?
            Hàm này nằm trong thư viện <ctype.h>. Nhiệm vụ của nó cực kỳ đơn giản:
            Đầu vào: Một ký tự (char).
            Kết quả: Trả về Đúng (khác 0) nếu ký tự đó là số từ '0' đến '9'. 
            Trả về Sai (bằng 0) nếu là chữ cái, dấu cách, hay ký tự đặc biệt.
            Tại sao lại là word[0]?
            Trong code của bạn, word là một chuỗi (mảng các ký tự). 
            Ví dụ: word = "8.5" hoặc word = "Nguyen". Máy tính không thể 
            quăng nguyên một cái chuỗi vào hàm isdigit được 
            (vì hàm này chỉ ăn mỗi lần 1 ký tự thôi).
            Vì vậy, mình chỉ cần kiểm tra ký tự đầu tiên của từ đó:
            
            Trường hợp 1: word = "Nguyen"
            word[0] là chữ 'N'.
            isdigit('N') -> Sai. Máy hiểu đây vẫn là một phần của cái Tên.
            
            Trường hợp 2: word = "8.5"
            word[0] là chữ số '8'.
            isdigit('8') -> Đúng!. Máy reo lên: "A ha! Đụng tới Điểm số rồi, 
            dừng việc ghép tên lại thôi!".
            */ 
                students[count].grade = atof(word);/*
                vì lấy thông tin từ file text dù là số hay chữ, máy tính đêì hiểu chúng dưới dạng ký tự 
                atof (ASCII to Float):
                 Đây là một "nhân viên chuyển đổi". Nó bốc chuỗi "8.5" và biến 
                 thành con số thực 8.5 để lưu vào biến grade.
                */
                break;
                /*break: Ngay sau khi tìm thấy điểm, nó ra lệnh "Dừng lại!". Nó 
                không đọc thêm từ nào cho sinh viên này nữa và quay lại vòng lặp 
                ngoài để tìm ID của sinh viên tiếp theo.*/
            } else {
                if (strlen(students[count].name) > 0) strcat(students[count].name, " ");
                strcat(students[count].name, word);
                /*
                strcat(dest, src):
                Nhiệm vụ: Nối chuỗi src (nguồn) vào sau chuỗi dest (đích).
                
                Tại sao lại có: if (strlen(students[count].name) > 0) ?
                Đây là một bước "dọn vệ sinh" để đảm bảo tên được ngăn cách đúng.
                
                Trường hợp 1: Tên rỗng (students[count].name đang trống).
                strlen() == 0. Điều kiện sai. Câu lệnh strcat không chạy.
                
                Trường hợp 2: Đã có tên (ví dụ: "Nguyen").
                strlen() > 0. Điều kiện đúng.
                Máy tính chèn một dấu cách " " vào sau "Nguyen", biến nó thành "Nguyen ".
                Sau đó, nó nối từ tiếp theo vào (ví dụ: "Van") -> "Nguyen Van".
                
                Tóm lại: Dấu cách ở đây có vai trò như một "người trung gian" 
                đảm bảo các từ không dính chặt vào nhau khi ghép lại thành tên.
                */
            }
        }
        count++;
    }
    fclose(f);
    return count;
}

void saveToFile(Student students[], int n) {
    FILE *f = fopen("students_sorted.txt", "w");
    for (int i = 0; i < n; i++) {
        fprintf(f, "%d %s %.2f\n", students[i].id, students[i].name, students[i].grade);
    }
    fclose(f);
}
/*1. Sức mạnh của chế độ "w" (Write)
Khi bạn gọi fopen("students_sorted.txt", "w"), hệ điều hành trên con Lenovo LOQ của bạn sẽ thực hiện một quy trình kiểm tra cực nhanh:

Trường hợp 1 (File chưa tồn tại): Máy tính sẽ tự động tạo mới một file tên là students_sorted.txt nằm ngay trong thư mục dự án của bạn.

Trường hợp 2 (File đã có sẵn): Máy tính sẽ xóa sạch nội dung cũ của file đó và chuẩn bị viết lại từ đầu (giống như bạn cầm cục tẩy xóa trắng tờ giấy cũ để viết bài mới vậy).

2. Giải mã các lệnh bên trong
fprintf(f, "%d %s %.2f\n", ...)
Lệnh này gần như y hệt lệnh printf mà bạn vẫn dùng để in ra màn hình.

Chữ f ở đầu: Nói với máy tính: "Đừng in ra màn hình, hãy in vào cái file f (students_sorted.txt) cho tôi".

Nó sẽ ghi ID, Tên và Điểm của từng sinh viên vào file theo đúng định dạng bạn muốn.

fclose(f);
Đây là bước cực kỳ quan trọng.

Nếu bạn không đóng file, dữ liệu có thể vẫn còn nằm ở bộ nhớ đệm (RAM) mà chưa thực sự được "khắc" xuống ổ cứng.

Lưu ý: Nếu quên fclose, đôi khi bạn mở file ra sẽ thấy nó... trống không đấy!

3. So sánh với chế độ "r" (Read)
Hãy nhớ lại hàm loadStudents bạn dùng lúc nãy:

Dùng "r": Máy tính chỉ đi Tìm file để đọc. Nếu không thấy file, nó sẽ báo lỗi (trả về NULL).

Dùng "w": Máy tính đi Xây file. Nếu không thấy, nó tự xây luôn.
*/

void display(Student students[], int n) {
    printf("\n%-10s %-20s %-10s\n", "ID", "Full Name", "Grade");
    printf("--------------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%-10d %-20s %-10.2f\n", students[i].id, students[i].name, students[i].grade);
}

int main() {
    Student list[100];
    int n = loadStudents(list);
    if (n == 0) { printf("Khong doc duoc file!\n"); return 1; }

    int col, order;
    printf("Chon cot sap xep (1. Name, 2. Score): "); scanf("%d", &col);
    printf("Chon thu tu (1. Tang dan, 2. Giam dan): "); scanf("%d", &order);

    // Sử dụng con trỏ hàm để quyết định cách so sánh
    int (*cmpPtr)(Student, Student) = NULL;
    /*
    1. Nó là gì?
    Thay vì tạo biến chứa số (int x), bạn tạo biến chứa hành động.

    Nó giống như một cái "Điều khiển đa năng": Bạn chưa bấm nút chọn kênh nào cả, 
    nhưng bạn phải có cái điều khiển trong tay đã.

    2. Tại sao phải có nó?
    Để linh hoạt: Bạn không biết người dùng sẽ chọn xếp theo Tên hay Điểm.

    Làm trạm trung chuyển: Bạn tạo cái "hố" này để lát nữa người dùng chọn gì thì bạn "nhét" 
    hàm đó vào, rồi mới đưa cái "hố" đó cho hàm sortStudents chạy.

3. Tại sao lại bằng NULL?
    Cho an toàn: Để máy tính biết cái "hố" này đang trống. Nếu bạn quên không nhét hàm vào 
    mà lỡ tay gọi nó, máy sẽ báo lỗi ngay lập tức thay vì chạy linh tinh rồi làm treo máy.
    */

    if (col == 1) {
        cmpPtr = (order == 1) ? compareNameInc : compareNameDec;
    } else {
        cmpPtr = (order == 1) ? compareGradeInc : compareGradeDec;
    }

    sortStudents(list, n, cmpPtr);
    display(list, n);
    saveToFile(list, n);
    printf("\nDa luu ket qua vao students_sorted.txt\n");

    return 0;
}