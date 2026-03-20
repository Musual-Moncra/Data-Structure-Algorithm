#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// BÀI 1
void taoMangNgauNhien(int *a, int n) {
    for (int i = 0; i < n; i++) {
        *(a + i) = rand() % 100;
    }
}

void inMang(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int isChinhPhuong(int n) {
    if (n < 0) return 0;
    int sq = sqrt(n);
    return (sq * sq == n);
}

void timSoChinhPhuong(int *a, int n) {
    printf("Cac so chinh phuong: ");
    for(int i = 0; i < n; i++) {
        if(isChinhPhuong(*(a + i))) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}

int isNguyenTo(int n) {
    if(n < 2) return 0;
    for(int i = 2; i <= sqrt(n); i++){
        if(n % i == 0) return 0;
    }
    return 1;
}

void timSoNguyenTo(int *a, int n) {
    printf("Cac so nguyen to: ");
    for(int i = 0; i < n; i++) {
        if(isNguyenTo(*(a + i))) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}

int isHoanThien(int n) {
    if(n <= 1) return 0;
    int sum = 1;
    for(int i = 2; i <= n / 2; i++) {
        if(n % i == 0) sum += i;
    }
    return sum == n;
}

void timSoHoanThien(int *a, int n) {
    printf("Cac so hoan thien: ");
    for(int i = 0; i < n; i++) {
        if(isHoanThien(*(a + i))) {
            printf("%d ", *(a + i));
        }
    }
    printf("\n");
}

// BÀI 2
void bai2() {
    char s[100];
    printf("Nhap chuoi: ");
    fgets(s, sizeof(s), stdin);
    s[strcspn(s, "\n")] = 0;

    char *p = s;
    int len = 0, letters = 0, digits = 0, spaces = 0, others = 0;
    
    while(*p != '\0') {
        len++;
        if(isalpha(*p)) letters++;
        else if(isdigit(*p)) digits++;
        else if(isspace(*p)) spaces++;
        else others++;
        p++;
    }
    printf("- Do dai chuoi: %d\n", len);
    printf("- So ky tu chu: %d\n", letters);
    printf("- So ky tu so: %d\n", digits);
    printf("- So ky tu khoang trang: %d\n", spaces);
    printf("- So ky tu khac: %d\n", others);

    printf("- Chuoi dao nguoc: ");
    for(int i = len - 1; i >= 0; i--) {
        printf("%c", s[i]);
    }
    printf("\n");
}

// BÀI 3
void bai3() {
    char name[100];
    printf("Ho ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    for(int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }
    
    char words[10][50];
    int count = 0;
    char *token = strtok(name, " ");
    while(token != NULL) {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }
    
    if (count == 0) return;

    printf("Email: %s.", words[count - 1]);
    for(int i = 0; i < count - 1; i++) {
        printf("%s", words[i]);
    }
    printf("@hoasen.edu.vn\n");
}

// BÀI 4
void bai4() {
    char name[100];
    char id[20];
    printf("Ho ten: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;
    
    printf("Ma SV: ");
    fgets(id, sizeof(id), stdin);
    id[strcspn(id, "\n")] = 0;

    for(int i = 0; name[i]; i++) {
        name[i] = tolower(name[i]);
    }

    char words[10][50];
    int count = 0;
    char *token = strtok(name, " ");
    while(token != NULL) {
        strcpy(words[count++], token);
        token = strtok(NULL, " ");
    }
    
    if (count == 0) return;

    printf("Email: %s.", words[count - 1]);
    for(int i = 0; i < count - 1; i++) {
        printf("%c", words[i][0]);
    }
    
    int idLen = strlen(id);
    if(idLen >= 4) {
        printf("%s", id + idLen - 4);
    } else {
        printf("%s", id);
    }
    printf("@sinhvien.hoasen.edu.vn\n");
}

// BÀI 5
typedef struct {
    char name[50];
} Student;

void nhapDSSV(Student *sv, int n) {
    for(int i = 0; i < n; i++) {
        printf("Nhap ten sinh vien %d: ", i + 1);
        fgets((sv + i)->name, sizeof((sv + i)->name), stdin);
        (sv + i)->name[strcspn((sv + i)->name, "\n")] = 0;
    }
}

void inDSSV(Student *sv, int n) {
    for(int i = 0; i < n; i++) {
        printf("%d. %s\n", i + 1, (sv + i)->name);
    }
}

void timSV(Student *sv, int n, char *searchName) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(strcmp((sv + i)->name, searchName) == 0) {
            printf("Tim thay tai vi tri %d\n", i + 1);
            found = 1;
        }
    }
    if(!found) printf("Khong tim thay sinh vien.\n");
}

void sapXepSV(Student *sv, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(strcmp((sv + i)->name, (sv + j)->name) > 0) {
                Student temp;
                strcpy(temp.name, (sv + i)->name);
                strcpy((sv + i)->name, (sv + j)->name);
                strcpy((sv + j)->name, temp.name);
            }
        }
    }
}

void bai5() {
    Student ds[100];
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    flushStdin();

    if (n > 100) n = 100;
    if (n <= 0) {
        printf("So luong khong hop le.\n");
        return;
    }

    nhapDSSV(ds, n);
    
    printf("\n--- Danh sach sinh vien ---\n");
    inDSSV(ds, n);
    
    char search[50];
    printf("\nNhap ten sinh vien can tim: ");
    fgets(search, sizeof(search), stdin);
    search[strcspn(search, "\n")] = 0;
    timSV(ds, n, search);

    printf("\n--- Danh sach sinh vien sau khi sap xep ---\n");
    sapXepSV(ds, n);
    inDSSV(ds, n);
}

int main() {
    srand(time(NULL));
    int choice;
    do {
        printf("\n========== MENU BÀI TẬP LAB 10 ==========\n");
        printf("1. Bai tap 1: Mang so nguyen & Con tro\n");
        printf("2. Bai tap 2: Nhap va xu ly chuoi\n");
        printf("3. Bai tap 3: Email giao vien\n");
        printf("4. Bai tap 4: Email sinh vien\n");
        printf("5. Bai tap 5: Quan ly DSSV bang con tro\n");
        printf("0. Thoat\n");
        printf("-----------------------------------------\n");
        printf("Chon chuc nang: ");
        if (scanf("%d", &choice) != 1) {
            flushStdin();
            continue;
        }
        flushStdin();

        switch(choice) {
            case 1: {
                int n;
                printf("Nhap N (so phan tu cua mang): ");
                scanf("%d", &n);
                flushStdin();
                if (n <= 0) {
                    printf("N phai lon hon 0!\n");
                    break;
                }
                int *a = (int *)malloc(n * sizeof(int));
                taoMangNgauNhien(a, n);
                printf("Mang duoc tao: ");
                inMang(a, n);
                timSoChinhPhuong(a, n);
                timSoNguyenTo(a, n);
                timSoHoanThien(a, n);
                free(a);
                break;
            }
            case 2: bai2(); break;
            case 3: bai3(); break;
            case 4: bai4(); break;
            case 5: bai5(); break;
            case 0: printf("Thoat chuong trinh.\n"); break;
            default: printf("Lua chon khong hop le. Vui long chon lai!\n");
        }
    } while(choice != 0);

    return 0;
}
