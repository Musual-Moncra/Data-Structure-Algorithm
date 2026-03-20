#include <stdio.h>
#include <string.h>
#include <ctype.h>

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Bài tập 1: Nhập họ tên của một người rồi in ra màn hình
void bài1() {
    char hovaten[100];
    printf("Nhap ho va ten: ");
    fgets(hovaten, sizeof(hovaten), stdin);
    // Remove newline character if present
    hovaten[strcspn(hovaten, "\n")] = 0;
    printf("Ho va ten vua nhap: %s\n", hovaten);
}

// Bài tập 2: Nhập vào một chuỗi, rồi in các ký tự của chuỗi ra màn hình (mỗi ký tự là 1 hàng)
void bài2() {
    char s[100];
    printf("Nhap vao mot chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    
    printf("Cac ky tu trong chuoi:\n");
    for (int i = 0; s[i] != '\0'; i++) {
        printf("%c\n", s[i]);
    }
}

// Bài tập 3: Nhập một chuỗi, hãy cho biết số ký tự chữ, số ký tự số, số khoảng trắng, số ký tự khác.
void bài3() {
    char s[100];
    int letter = 0, digit = 0, space = 0, others = 0;
    printf("Nhap vao mot chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if (isalpha(s[i])) letter++;
        else if (isdigit(s[i])) digit++;
        else if (isspace(s[i])) space++;
        else others++;
    }
    
    printf("So ky tu chu: %d\n", letter);
    printf("So ky tu so: %d\n", digit);
    printf("So khoang trang: %d\n", space);
    printf("So ky tu khac: %d\n", others);
}

// Bài tập 4: Nhập vào một chuỗi, hãy in ngược chuỗi đã nhập
void bài4() {
    char s[100];
    printf("Nhap vao mot chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;
    
    int len = strlen(s);
    printf("Chuoi nguoc: ");
    for (int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// Bài tập 5: Nhập họ tên sinh viên rồi in ra tên viết tắt. VD: Nguyen Thi Binh An -> NTBA
void bài5() {
    char name[100];
    printf("Nhap ho ten sinh vien: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("Ten viet tat: ");
    if (strlen(name) > 0 && !isspace(name[0])) {
        printf("%c", toupper(name[0]));
    }
    
    for (int i = 0; i < strlen(name) - 1; i++) {
        if (isspace(name[i]) && !isspace(name[i+1])) {
            printf("%c", toupper(name[i+1]));
        }
    }
    printf("\n");
}

// Bài tập 6: Nhập họ tên giáo viên rồi in ra email. VD: Tran Van Thanh -> thanh.tranvan@hoasen.edu.vn
void bài6() {
    char name[100];
    char nameCopy[100];
    printf("Ho ten giao vien: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    // Convert to lowercase
    for (int i = 0; name[i]; i++) name[i] = tolower(name[i]);
    
    strcpy(nameCopy, name);
    char words[10][20];
    int count = 0;
    char *token = strtok(nameCopy, " ");
    while (token != NULL) {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }
    
    if (count == 0) return;
    
    printf("Email: %s.", words[count - 1]); // Last name (Tên) first
    for (int i = 0; i < count - 1; i++) {
        printf("%s", words[i]); // Append everything else
    }
    printf("@hoasen.edu.vn\n");
}

// Bài tập 7: Nhập họ tên, mã SV. In ra email sinh viên.
void bài7() {
    char name[100];
    char id[20];
    printf("Ho ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("Ma SV: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;
    
    for (int i = 0; name[i]; i++) name[i] = tolower(name[i]);
    
    char words[10][20];
    int count = 0;
    char *token = strtok(name, " ");
    while (token != NULL) {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }
    
    if (count == 0) return;
    
    printf("Email: %s.", words[count - 1]); // Tên
    for (int i = 0; i < count - 1; i++) {
        printf("%c", words[i][0]); // Ký tự đầu của họ và lót
    }
    
    // Lấy 4 số cuối MSSV
    int idLen = strlen(id);
    if (idLen >= 4) {
        printf("%s", id + idLen - 4);
    } else {
        printf("%s", id);
    }
    printf("@sinhvien.hoasen.edu.vn\n");
}

int main() {
    int choice;
    do {
        printf("\n========== MENU LAB 11 (CHUOI KY TU) ==========\n");
        printf("1. Bai tap 1: Nhap/Xuat ho ten\n");
        printf("2. Bai tap 2: In tung ky tu tren 1 hang\n");
        printf("3. Bai tap 3: Dem ky tu letters, digits, spaces...\n");
        printf("4. Bai tap 4: In nguoc chuoi\n");
        printf("5. Bai tap 5: Ten viet tat (VD: NTBA)\n");
        printf("6. Bai tap 6: Email giao vien\n");
        printf("7. Bai tap 7: Email sinh vien\n");
        printf("0. Thoat\n");
        printf("-----------------------------------------------\n");
        printf("Chon chuc nang: ");
        if (scanf("%d", &choice) != 1) {
            flushStdin();
            continue;
        }
        flushStdin();
        
        switch (choice) {
            case 1: bài1(); break;
            case 2: bài2(); break;
            case 3: bài3(); break;
            case 4: bài4(); break;
            case 5: bài5(); break;
            case 6: bài6(); break;
            case 7: bài7(); break;
            case 0: printf("Ket thuc Lab 11.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    
    return 0;
}
