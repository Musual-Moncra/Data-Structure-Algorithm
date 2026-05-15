#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Định nghĩa số lượng sinh viên tối đa mảng có thể chứa
// Dùng #define để sau này muốn quản lý kích thước mảng thì chỉ cần sửa ở đây 1 lần
#define MAX_STUDENTS 100

// Đây là struct (cấu trúc) để lưu trữ thông tin của 1 bạn Sinh Viên
typedef struct {
    int id;            // Mã số sinh viên (ví dụ: 123)
    char name[100];    // Tên sinh viên (đề bài bảo chỉ có 1 từ, chứa tối đa 99 ký tự + 1 ký tự kết thúc chuỗi '\0')
    float score;       // Điểm số, dùng float vì có phần thập phân (ví dụ 7.50)
} Student;

// ===== PHẦN KHAI BÁO NGUYÊN MẪU HÀM (FUNCTION PROTOTYPES) =====
// Cần khai báo trước ở đây để C biết sự tồn tại của các hàm này trước khi vào hàm main()

// Các hàm thao tác chung (đọc từ file txt, in ra Terminal, lưu lại vào file txt)
void readStudents(const char* filename, Student students[], int* count);
void printStudents(Student students[], int count);
void saveStudents(const char* filename, Student students[], int count);

// Bài 1: Sắp xếp nổi bọt (Bubble sort) -> Giảm dần theo cột điểm số
void bubbleSortByScoreDesc(Student students[], int count);

// Bài 2: Sắp xếp chọn (Selection sort) -> Tăng dần theo cột tên (thứ tự từ A -> Z)
void selectionSortByNameAsc(Student students[], int count);

// Bài 3: Bubble sort kết hợp 2 điều kiện để sắp xếp 
// ĐK 1: Tên tăng dần (không thèm phân biệt chữ hoa, chữ thường)
// ĐK 2: Nếu 2 bạn rủi ro trùng tên y hệt nhau -> ai điểm cao hơn sẽ xếp trên (điểm giảm dần)
void sortByNameAscScoreDesc(Student students[], int count);


// Bài 4: Sử dụng Con trỏ hàm (Function pointers) để làm Menu tổng quát
// 4 hàm con nhỏ xíu xốp lẻ tẻ dưới đây sẽ định nghĩa CHIỀU HƯỚNG ĐỔI CHỖ cho hàm sort() dùng chung
int compareAscName(Student a, Student b);   // Trả dấu hiệu sai chiều nếu Tên bị tăng dần
int compareDescName(Student a, Student b);  // Trả dấu hiệu sai chiều nếu Tên bị giảm dần
int compareAscScore(Student a, Student b);  // Trả dấu hiệu sai chiều nếu Điểm bị tăng dần
int compareDescScore(Student a, Student b); // Trả dấu hiệu sai chiều nếu Điểm bị giảm dần

// Hàm sort CHUẨN MỰC (có nhận thêm con trỏ hàm). Nó sẽ mượn 1 trong 4 hàm compare ở trên để quyết định lúc nào thì Swap
void sort(Student students[], int count, int (*compare)(Student a, Student b));

// Các hàm tiện ích bổ trợ linh tinh
void swap(Student* a, Student* b);                  // Dùng để đổi chỗ địa chỉ 2 bạn sinh viên trong mảng struct
char* strToLower(const char* str, char* res);       // Hàm tự chế giúp chuyển chuỗi In Hoa lung tung thành chữ in thường (để so tên bài 3)

// Menu UI tương tác với người dùng ở Bài 4
void menu(Student students[], int count);


// ===== BẮT ĐẦU CHƯƠNG TRÌNH CHÍNH (MAIN FUNCTION) =====
int main() {
    Student students[MAX_STUDENTS]; // Tạo mảng rỗng chứa được nhiều nhất là 100 ông Sinh Viên
    int count = 0;                  // Biến count dùng để đếm xem thực sự đọc được bao nhiêu dòng hợp lý từ txt file
    
    // Đọc danh sách từ file vào mảng gốc. Chú ý: mình truyền &count vào để hàm đọc có thể sửa được biến count của hàm main
    readStudents("students.txt", students, &count);
    
    // Validate thử phát, nếu file rỗng hoặc không mở ra được thì báo bug và văng ra ngoài kết thúc sớm
    if (count == 0) {
        printf("Loi: Khong the doc file hoac file txt dang mo bi rong tec.\n");
        return 1;
    }
    
    // In danh sách gốc (chưa qua pha xử lý nào) ra màn hình để mắt thấy tai nghe
    printf("--- DANH SACH SINH VIEN GOC (CHUA SAP XEP) ---\n");
    printStudents(students, count);
    
    // Tại sao phải tao 1 mảng 'temp' copy? 
    // Trả lời: Do mình có 4 lab, nếu sắp xếp thẳng lặp đi lặp lại ở mảng 'students' thì các lab sau sẽ chạy array đã bị xáo trộn mất rồi.
    Student temp[MAX_STUDENTS];
    
    // --- CHẠY LAB 1 ---
    // hàm `memcpy` cực xịn dùng để clone mảng A sang mảng B nhanh gọn lẹ theo số byte
    memcpy(temp, students, sizeof(Student) * count);
    printf("\n--- Bai 1: Chay thu Bubble Sort (Diem bi ha dan tu Cao > Thap) ---\n");
    bubbleSortByScoreDesc(temp, count);
    printStudents(temp, count);
    
    // --- CHẠY LAB 2 ---
    memcpy(temp, students, sizeof(Student) * count);
    printf("\n--- Bai 2: Chay Selection Sort (Ten bi tang dan tu chu A > chu Z) ---\n");
    selectionSortByNameAsc(temp, count);
    printStudents(temp, count);
    
    // --- CHẠY LAB 3 ---
    memcpy(temp, students, sizeof(Student) * count);
    printf("\n--- Bai 3: Ten tang dan kieu Ignore-case. Neu trung ho ten thi Diem ha dan ---\n");
    sortByNameAscScoreDesc(temp, count);
    printStudents(temp, count);
    
    // --- CHẠY LAB 4 ---
    printf("\n--- Bai 4: Tinh nang Mo rong bang Menu tuong tac (Co xai Function Pointer) ---\n");
    // Nhúng mảng temp lại từ đầu phát nữa
    memcpy(temp, students, sizeof(Student) * count);
    
    // Gọi hàm menu. Tại đây trình terminal sẽ khựng lại đòi người dùng lựa phím số từ 1->2 để trải nghiệm App.
    // Nếu ai chạy tự động mà không gõ phím được thì cứ command dòng này lại gọi thẳng hàm sort() nha.
    menu(temp, count);
    
    return 0; // Trả về 0 báo tín hiệu chương trình ngon, xong nhiệm vụ.
}


// =========================================================================
//            CHI TIẾT MỔ XẺ CÁC HÀM XỬ LÝ (IMPLEMENTATION)
// =========================================================================

/**
 * [Hàm Swap - Hoán đổi linh hồn 2 vật thể]
 * C truyền biến theo giá trị (pass-by-value) nên mình phải truyền con trỏ (dấu *) vô.
 * Nếu không xài * mà ghi `Student a` không thì C chỉ đổi vỏ chứ mảng vẫn im lìm y như cũ.
 */
void swap(Student* a, Student* b) {
    Student temp = *a; // Lấy cái hộp phụ bọc lấy thân xác của bạn A
    *a = *b;           // Đẩy linh hồn bạn B qua cho A
    *b = temp;         // Đưa cái xác cũ của A cho bạn B
}

/**
 * [strToLower - Hàm ép ký tự về kiểu chữ in Thường]
 * Bài yêu cầu so sánh chuỗi không thèm để ý HOA thường. (Chữa luôn cái sự khó ở của strcmp vì 'A' vs 'a' theo mã ASCII là cực kỳ chênh lệch)
 */
char* strToLower(const char* str, char* res) {
    int i;
    // Vòng for chập choẹ chạy cho tới khi đụng kí tự NULL kết thúc chuỗi \0
    for(i = 0; str[i]; i++){
        // Xài hàm tolower để hạ cấp, kẹp thêm (unsigned char) để khỏi crash gặp dấu tiếng Việt.
        res[i] = tolower((unsigned char)str[i]);
    }
    res[i] = '\0'; // Nhớ thòng cái đuôi vào cho an tâm C mới hiểu chuỗi ngưng ở đâu.
    return res;
}

/**
 * [readStudents - Đọc list file thẳng vào mảng]
 * - fscanf return số liệu nó gom thành công. Nếu trúng cú pháp "%d %s %f" liên tục thì nó trả số đếm = 3. 
 * => Nghĩa là đủ bộ thông tin, duyệt count ++.
 * - "%99s" để bảo kê mảng name[100] không bao giờ bị overflow và dính warning vớ vẩn.
 */
void readStudents(const char* filename, Student students[], int* count) {
    FILE* file = fopen(filename, "r");
    if (!file) return; 
    
    *count = 0; 
    while (fscanf(file, "%d %99s %f", &students[*count].id, students[*count].name, &students[*count].score) == 3) {
        (*count)++; 
    }
    fclose(file); // Mở file xong nhớ dội nước, à nhầm nhớ close giải phóng Ram.
}

/**
 * [printStudents - In ra màn hình Terminal bằng printf]
 * - %d và %.2f thì ai cũng rành là dính với Int với Float rồi, 2 số lẻ ngoài sau chữ.
 * - %-10s : In Tên căn lề trái (-) với bề dài cưỡng chế là 10 phím khoảng trắng nha, in ra bảng đẹp như Excell luôn.
 */
void printStudents(Student students[], int count) {
    for (int i = 0; i < count; i++) {
        printf("%d\t%-10s\t%.2f\n", students[i].id, students[i].name, students[i].score);
    }
}

/**
 * [saveStudents - Ghi hết ruột gan xuống file text theo yêu cầu Bài 4]
 * Dùng mode "w" để Write thay vì r. Mất file cũ tự đẻ file mới.
 */
void saveStudents(const char* filename, Student students[], int count) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        printf("Khong thay file hoac het quyen luu file roi.\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d %s %.2f\n", students[i].id, students[i].name, students[i].score);
    }
    fclose(file); 
}

// ---------------------------------------------------------
// THUẬT TOÁN BÀI 1: NỔI BỌT (BUBBLE SORT) - ĐIỂM SỐ GIẢM DẦN
// ---------------------------------------------------------
// Trái tim của Bubble sort: Đứng chung cạnh nhau, cứ nếu (Đằng trước < Đằng sau) gây nghịch mắt luân lý > Swap luôn cho tao.
// Vòng thứ I chạy lồng vòng J nhằm mục đích ép cái thằng bị nhỏ con nhất rớt lại tận tít đuôi.
void bubbleSortByScoreDesc(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            
            // Do cần GIẢM DẦN, nghĩa là Trái phải LỚN HƠN Phải. 
            // Nếu thằng j.score lén nhỏ hơn j+1 thì mình gọi swap đổi chỗ còng đầu nó ngay.
            if (students[j].score < students[j+1].score) {
                swap(&students[j], &students[j+1]); 
            }
        }
    }
}

// ---------------------------------------------------------
// THUẬT TOÁN BÀI 2: CHỌN LỌC (SELECTION SORT) - TÊN CHỮ CÁI TĂNG DẦN
// ---------------------------------------------------------
// Selection Sort kiên nhẫn hơn, nó tìm cả 1 lượt xem ai "Xứng đáng Max, Min" nhất thì nó mới chịu ra tay, do đó nó tiết kiệm số lượng Swap hơn.
void selectionSortByNameAsc(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        
        int min_idx = i; // Tạm xùy vị trí i là người nắm tên Nhỏ nhất hiện tại chuẩn bị đổi chỗ.
        
        for (int j = i + 1; j < count; j++) {
            // Hàm strcmp() trả số < 0 TỨC LÀ chuỗi tên vị trí J theo thứ tự từ điển thực sự Nằm Trước vị trí của thằng giả mạo min_idx hiện tại. 
            if (strcmp(students[j].name, students[min_idx].name) < 0) {
                min_idx = j; // Vừa phát hiện có thằng Tên Chữ Cái Nằm Lên Tít Phía Trước Đầu, cập nhật toạ độ J mới
            }
        }
        
        // Hết nguyên 1 dọc J từ đầu đén cuối bãi mới chốt lệnh Swap nếu min_idx khác với cái gốc I ban đầu nhét vào. Nhàn hạ quá.
        if (min_idx != i) {
            swap(&students[i], &students[min_idx]);
        }
    }
}

// ---------------------------------------------------------
// THUẬT TOÁN BÀI 3: KÈM 2 LỚP ĐIỀU KIỆN 
// ---------------------------------------------------------
// Điều kiện kép mệt quá nên vác Bubble Sort xài lại đỡ phải gán min index.
void sortByNameAscScoreDesc(Student students[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            
            // Xài cục name[100] rỗng tuếch để hứng 2 biến hạ chuẩn về Chữ In Thường
            char name1[100], name2[100];
            strToLower(students[j].name, name1); // Ví dụ đổi "QuAn" qua "quan"
            strToLower(students[j+1].name, name2); // Vừa có tên Lower thì quăng vô
            
            // Thực thi phép đụng độ 2 cái tên thông qua mã ASCII
            int cmp = strcmp(name1, name2);
            
            // LOGIC QUAN TRỌNG CHỖ NÀY NHA BÀ CON CHÚ Ý !!!
            // YÊU CẦU 1: Tên TĂNG DẦN. Nghĩa là bạn Trước kề bên Phải Có Họ Tên Đứng Trước hoặc bằng Bạn Sau.
            // Nếu cmp > 0 (Tức bạn Trước mang chữ Y còn bạn sau mang chữ A. Sai quá xá sai luật tăng dần!!! -> Swap ngay.)
            
            // YÊU CẦU 2 (Phụ): Lỡ cmp == 0 (tức ông J tên Long, thằng J+1 kế bên cũng tên Long nốt). 
            // Đề bắt Điểm GIẢM DẦN. Tức Long Trước Điểm phải Cao Hơn Cậu Long Thứ Hai Phía Sau.
            // Nếu Long 1 mà rớt điểm < Long 2 -> Lại nghịch luân lý, Mời hai nhóc đi Swap chỗ cho tôi ngay.
            if (cmp > 0 || (cmp == 0 && students[j].score < students[j+1].score)) {
                swap(&students[j], &students[j+1]); 
            }
        }
    }
}

// ---------------------------------------------------------
// BÀI 4: VÀ TRỌNG TÂM CỦA FUNCTION POINTER !!!!!!!
// ---------------------------------------------------------
/** 
 * Các hàm compare nhỏ lẻ phải tuân thủ Luật Chơi Tối Cao Sau:
 * "Hàm sẽ Trả về 1 (true) ---> TỨC LÀ BÁO HIỆU CÓ DẤU HIỆU LỆCH PHA VÀ YÊU CẦU ĐỔI CHỖ"
 * Hàm Trả về 0 (false) ---> TỨC LÀ OK THUẬN CHIỀU NGON LÀNH RỒI, KHÔNG CẦN SWAP.
 */
int compareAscName(Student a, Student b) {
    char name1[100], name2[100];
    // Tăng dần là "A < B". Nên nếu thực tế Lòi ra "A > B" do thằng strcmp trả số dương -> Báo Động cờ true 1 đi.
    return strcmp(strToLower(a.name, name1), strToLower(b.name, name2)) > 0;
}
int compareDescName(Student a, Student b) {
    char name1[100], name2[100];
    // Giam dần là "A > B". Nên lòi ra A < B là lỗi, trả cờ True.
    return strcmp(strToLower(a.name, name1), strToLower(b.name, name2)) < 0;
}
int compareAscScore(Student a, Student b) {
    // Điểm dở lên trên, điểm cao đày xuống, nếu A vô tình to xác hơn B -> Sai luật, Swap.
    return a.score > b.score;
}
int compareDescScore(Student a, Student b) {
    // Điểm cao xếp hàng trên cùng, lỡ lọt A < B là toi cơm, báo tín hiệu Swap lẹ...
    return a.score < b.score;
}

/**
 * !!! HÀM SẮP XẾP CHUNG CHẠ ĐẠI ĐỒNG TẤT CẢ GỘP MỘT !!!
 * - Parameter cái dòng rắc rối `int (*compare)(Student a, Student b)` có nghĩa là: 
 *   + Này C à, tớ không biết ruột gan bên trong mi sẽ định sort theo điểm, tuổi hay giới tính.
 *   + Tớ chỉ chừa chõ Tọa độ Pointer của một CÁI HÀM có tính chất Trả 1 nhận (a,b). Nào xài thì móc tớ ra chạy nha.
 * 
 * Nếu đem ra so sánh thì kiến thức con trỏ hàm cực kỳ đáng sợ nhưng cũng cực kỳ phê vì sau này nếu mướn người ta sort Thêm cột ID Số Hiệu đồ thì chỉ có tạo thêm 1 hàm chục dòng nhét cái vèo vào rồi ngẩn mặt lên trời. Chứ if/else như bài 4 chắc 20 cái lồng for nát luôn code. Cực ngầu!
 */
void sort(Student students[], int count, int (*compare)(Student a, Student b)) {
    // Bubble sort đi cày dốt vòng đời mỏi mòn nè
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            
            // Xúc tích chưa? 
            // Nếu Mày chĩa vào cái SoSánhNào...mà nó trả về True thì tau swap lẹ ko hỏi nhiều !!!. Khỏi phải if/strcmp đồ mệt não
            if (compare(students[j], students[j+1])) {
                swap(&students[j], &students[j+1]);
            }
        }
    }
}

/**
 * MENU HIỂN THỊ KIẾM ĐIỂM SỐ CHUYÊN CẦN QUÁ DỄ
 */
void menu(Student students[], int count) {
    int choice_col, choice_order; // Biến hớt số gõ bàn phím lên
    
    printf("\n*** MENU CHON CHE DO ***\nBan muon Sap xep theo cot thong tin nao?\n1. Name (Ten)\n2. Score (Diem so)\n=> Chon thu di man: ");
    if(scanf("%d", &choice_col) != 1) return; // Bảo vệ thằng giời đánh nào gõ vào chữ Chữ Cái rồi nó Error Crash Loop vòng lặp...
    
    printf("\nOk ban e! Theo chieu nao cho ngau?\n1. Tang dan (Thap toi Cao)\n2. Giam dan (Cao roi xuong ho)\n=> Kieu minh ma chon do: ");
    if(scanf("%d", &choice_order) != 1) return;
    
    // Setup một Pointer Hàm (với chữ `int (*)`) trỏ nó về Vùng Nhớ Rỗng (Cái hố đen NULL) để chờ Gán Hàm tương Thích vào
    int (*cmp)(Student, Student) = NULL;
    
    // Gắn cho đạn vào súng tùy vào gu của đại gia nhập Menu
    if (choice_col == 1) { // 1 là Tên!
        if (choice_order == 1) cmp = compareAscName;        // Nhét hàm tăng của Tên vào họng súng
        else cmp = compareDescName;                         // Nhét chiều giảm Tên
    } else if (choice_col == 2) { // 2 là cột Điểm số !!!
        if (choice_order == 1) cmp = compareAscScore;
        else cmp = compareDescScore;
    } else {
        printf("Nguoi ngoai hanh tinh cung khong chon cai Cot do dau! Bam nut run lai di cha.\n");
        return;
    }
    
    // Họng súng CMP đã có lõi hàm hoạt động chuẩn không phải NULL
    if (cmp) {
        // Nổ súng Sắp xếp !!!
        sort(students, count, cmp); 
        
        printf("\n--- DAY LA KET QUA HOAN HAO CUA MINH SAU KHI SORT MENU ---\n");
        printStudents(students, count);
        
        // Thầy bảo Nhớ ghi ra file cho chắc ăn thì xách mông đem đi save txt nè.
        saveStudents("students_sorted.txt", students, count);
        printf("\n==> Chuc mung! Danh sach tren da chinh thuc duoc xuat ban vao trong file students_sorted.txt\n");
    }
}
