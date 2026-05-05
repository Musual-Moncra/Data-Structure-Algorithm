#include <stdio.h>
#include <string.h>

/* ==============================================================================
   BÍ KÍP BỎ TÚI (CHEAT SHEET) CHO THƯ VIỆN CHUỖI <string.h> Ở C
   ==============================================================================
   Khác với ngôn ngữ Java (String là một siêu Object khổng lồ có sẵn đủ trò), 
   ở C, chuỗi thực chất chỉ là "một mảng gom nhiều chữ cái char lại" và chốt đuôi
   bằng ký tự tàng hình '\0'. Do đó, ta BẮT BUỘC phải xài các tuyệt kỹ trong <string.h>!
================================================================================= */

int main() {
    char str1[50] = "Sy Chi Khoi";
    char str2[50] = "Nguyen Thai Bao";
    char buffer[100]; // Mảng nhớ tạm (đủ rộng rải để chứa kết quả test)

    printf("\n=== 1. DO CHIEU DAI CHUOI (strlen) ===\n");
    // strlen đo lường độ dài chuỗi, nó KHÔNG thèm đếm ký tự chốt đuôi '\0'.
    int len = strlen(str1);
    printf("-> Chieu dai cua '%s' la: %d ky tu.\n", str1, len);


    printf("\n=== 2. SAO CHEP CHUOI (strcpy) ===\n");
    // Bạn KHÔNG TỰ DƯNG gán buffer = str1 như đang gán biến int a = b được! Máy sẽ báo lỗi.
    // Phải sai bảo thằng strcpy() chuyển hàng sang.
    strcpy(buffer, str1);
    printf("-> Chuoi 'buffer' moi bi copy tu str1: %s\n", buffer);


    printf("\n=== 3. NOI CHUOI GHEP DONG (strcat) ===\n");
    // strcat sà vào và nối đoạn text thứ 2 dính ngay sau mông đoạn thứ 1
    strcat(buffer, " va ");
    strcat(buffer, str2);
    printf("-> Chuoi 'buffer' sau khi noi lien hoan 2 hiep: %s\n", buffer);


    printf("\n=== 4. SO SANH CÂN ĐO (strcmp va stricmp) ===\n");
    // Hễ cả hai bên giống hệt nhau, hàm sẽ trả về số 0.
    // - strcmp: Phân biệt gắt gao khoản Chữ HOA / chữ thường.
    // - stricmp: Máy tự làm ngơ chuyện Hoa/Thường.
    char pass1[] = "APPLE";
    char pass2[] = "apple";
    
    if (strcmp(pass1, pass2) == 0) {
        printf("-> strcmp: 2 chuoi nay GIONG NHAU.\n");
    } else {
        printf("-> strcmp: 2 chuoi KHAC NHAU (Vi no soi moi phan biet hoa/thuong nha).\n");
    }

    if (stricmp(pass1, pass2) == 0) {
        printf("-> stricmp: 2 chuoi nay GIONG NHAU (stricmp da bo qua viec in hoa).\n");
    }


    printf("\n=== 5. HOAN DOI FORM CHU (strupr / strlwr) ===\n");
    // Đang xài Windows C compiler nên tụi này chạy trơn tru cực mượt.
    // Thường hay xài trò này giống Câu 3: Đưa chung hai tên về IN HOA hết rồi mới đem so sánh cho chắc.
    char testUpper[] = "hello thay giang";
    strupr(testUpper);
    printf("-> Ep nguyen cum qua IN HOA bang strupr: %s\n", testUpper);//Ép nguyên cụm qua IN HOA bằng strupr


    printf("\n=== 6. DO TIM CHUOI CON (strstr) - CHUYEN CHO DAN SEARCH! ===\n");
    // Công thức: strstr(chuỗi_mẹ, chuỗi_con_can_tim)
    // Nếu mò trúng, nó sẽ ói ra một Cây Trỏ (Pointer) cắm thẳng xuống vị trí chữ bắt đầu. 
    // Không ra thì trả về vạch số Không (NULL).
    char haystack[] = "Hom nay la buoi thuc hanh mon cau truc du lieu.";
    char needle[] = "cau truc"; // Dữ liệu mình muốn Search
    
    char *vitricamco = strstr(haystack, needle);
    
    if (vitricamco != NULL) {
        // Mẹo toán học: Trừ vị trí cắm cờ cho mốc số 0 (haystack) sẽ lòi ra số index !
        int index = vitricamco - haystack;
        printf("-> [BINGO] Phat hien chu '%s' nam o vi tri index thu: %d\n", needle, index);
        // %s mà ráp thẳng vô con trỏ nó sẽ in phần còn thừa lại tính từ đuôi cắm cờ:
        printf("-> Doan chuoi tinh tu vi tri cam co tro di do la: '%s'\n", vitricamco);
    } else {
        printf("-> Khong tim thay dau het!\n");
    }

    return 0;
}
