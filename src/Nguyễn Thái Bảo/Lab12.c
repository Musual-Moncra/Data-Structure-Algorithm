#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

// --- Helper Functions ---
void flushStdin() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Convert string to lowercase for case-insensitive search
void toLower(char *s) {
    for (int i = 0; s[i]; i++) s[i] = tolower(s[i]);
}

// Trim leading and trailing spaces
void trim(char *s) {
    int n = strlen(s);
    if (n == 0) return;
    int start = 0;
    while (isspace(s[start])) start++;
    if (start == n) {
        s[0] = '\0';
        return;
    }
    int end = n - 1;
    while (end > start && isspace(s[end])) end--;
    int i;
    for (i = 0; start <= end; i++, start++) {
        s[i] = s[start];
    }
    s[i] = '\0';
}

// Get the last word (name) from a full name
char* getLastName(char *fullName) {
    char *last = strrchr(fullName, ' ');
    if (last == NULL) return fullName;
    return last + 1;
}

// ======================== BÀI TẬP 1: STUDENT MANAGEMENT ========================
struct Student {
    char FullName[30];
    int Age;
    double Grade;
};

struct Student students[100];
int studentCount = 0;

void AddStudent() {
    if (studentCount >= 100) {
        printf("Danh sach da day!\n");
        return;
    }
    printf("Enter student name: ");
    fgets(students[studentCount].FullName, 30, stdin);
    students[studentCount].FullName[strcspn(students[studentCount].FullName, "\n")] = 0;
    
    printf("Enter age: ");
    scanf("%d", &students[studentCount].Age);
    printf("Enter grade: ");
    scanf("%lf", &students[studentCount].Grade);
    flushStdin();
    studentCount++;
}

void PrintStudent() {
    printf("%-20s %-10s %-10s\n", "FullName", "Age", "Grade");
    for (int i = 0; i < studentCount; i++) {
        printf("%-20s %-10d %-10.1lf\n", students[i].FullName, students[i].Age, students[i].Grade);
    }
}

void SortStudentByGrade() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = i + 1; j < studentCount; j++) {
            if (students[i].Grade > students[j].Grade) {
                struct Student temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
    printf("Da xep theo diem trung binh tang dan.\n");
    PrintStudent();
}

void FindStudentByName() {
    char searchName[30];
    printf("Enter student name to find: ");
    fgets(searchName, 30, stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    
    int found = 0;
    for (int i = 0; i < studentCount; i++) {
        if (strcmp(searchName, students[i].FullName) == 0) {
            printf("Found at position: %d\n", i + 1);
            found = 1;
        }
    }
    if (!found) printf("Not found!!!\n");
}

void menuStudent() {
    int choice;
    do {
        printf("\n==== STUDENT MANAGEMENT ===\n");
        printf("1. Add student\n");
        printf("2. Print student list\n");
        printf("3. Sort by grade\n");
        printf("4. Find student name\n");
        printf("0. Back to Main Menu\n");
        printf("===========================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { flushStdin(); continue; }
        flushStdin();
        switch (choice) {
            case 1: AddStudent(); break;
            case 2: PrintStudent(); break;
            case 3: SortStudentByGrade(); break;
            case 4: FindStudentByName(); break;
            case 0: break;
            default: printf("Invalid choice!!!\n");
        }
    } while (choice != 0);
}

// ======================== BÀI TẬP 2: EMPLOYEE MANAGEMENT ========================
struct Employee {
    char FullName[50];
    char Position[30];
    double Salary;
};

struct Employee employees[100];
int employeeCount = 0;

void AddEmployee() {
    if (employeeCount >= 100) {
        printf("Danh sach da day!\n");
        return;
    }
    printf("Nhap ho ten nhan vien: ");
    fgets(employees[employeeCount].FullName, 50, stdin);
    employees[employeeCount].FullName[strcspn(employees[employeeCount].FullName, "\n")] = 0;
    
    printf("Nhap chuc vu: ");
    fgets(employees[employeeCount].Position, 30, stdin);
    employees[employeeCount].Position[strcspn(employees[employeeCount].Position, "\n")] = 0;
    
    printf("Nhap luong: ");
    scanf("%lf", &employees[employeeCount].Salary);
    flushStdin();
    employeeCount++;
}

void PrintEmployee() {
    printf("%-20s %-15s %-10s\n", "Ho ten", "Chuc vu", "Luong");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-20s %-15s %-10.0lf\n", employees[i].FullName, employees[i].Position, employees[i].Salary);
    }
}

void StatisticsSalary() {
    char positions[100][30];
    int posCount = 0;
    
    for (int i = 0; i < employeeCount; i++) {
        int found = 0;
        for (int j = 0; j < posCount; j++) {
            if (strcmp(employees[i].Position, positions[j]) == 0) {
                found = 1; break;
            }
        }
        if (!found) {
            strcpy(positions[posCount++], employees[i].Position);
        }
    }
    
    printf("\nThong ke luong theo chuc vu:\n");
    for (int i = 0; i < posCount; i++) {
        double total = 0;
        int count = 0;
        for (int j = 0; j < employeeCount; j++) {
            if (strcmp(employees[j].Position, positions[i]) == 0) {
                total += employees[j].Salary;
                count++;
            }
        }
        printf("- %-15s: Tong luong %.0lf (TB: %.0lf)\n", positions[i], total, total / count);
    }
}

void FindEmployeeByName() {
    char search[50];
    printf("Nhap ten nhan vien can tim (chi phan ten): ");
    fgets(search, 50, stdin);
    search[strcspn(search, "\n")] = 0;
    
    trim(search);
    toLower(search);
    
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        char nameOnly[50];
        strcpy(nameOnly, getLastName(employees[i].FullName));
        toLower(nameOnly);
        
        if (strcmp(search, nameOnly) == 0) {
            printf("Tim thay tai vi tri %d: %s [%s]\n", i + 1, employees[i].FullName, employees[i].Position);
            found = 1;
        }
    }
    if (!found) printf("Khong tim thay nhan vien co ten '%s'\n", search);
}

void SortEmployeeByName() {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = i + 1; j < employeeCount; j++) {
            char name1[50], name2[50];
            strcpy(name1, getLastName(employees[i].FullName));
            strcpy(name2, getLastName(employees[j].FullName));
            
            if (strcmp(name1, name2) > 0) {
                struct Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
    printf("Da sap xep danh sach theo ten tang dan.\n");
    PrintEmployee();
}

void menuEmployee() {
    int choice;
    do {
        printf("\n==== EMPLOYEE MANAGEMENT ===\n");
        printf("1. Add employee\n");
        printf("2. Print employee list\n");
        printf("3. Statistics salary by position\n");
        printf("4. Find employee by name\n");
        printf("5. Sort by name\n");
        printf("0. Back to Main Menu\n");
        printf("============================\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) { flushStdin(); continue; }
        flushStdin();
        switch (choice) {
            case 1: AddEmployee(); break;
            case 2: PrintEmployee(); break;
            case 3: StatisticsSalary(); break;
            case 4: FindEmployeeByName(); break;
            case 5: SortEmployeeByName(); break;
            case 0: break;
            default: printf("Invalid choice!!!\n");
        }
    } while (choice != 0);
}

int main() {
    int choice;
    do {
        printf("\n========== LAB 12: CONSTRUCT (STRUCT) ==========\n");
        printf("1. Bai tap 1: Quan ly Sinh Vien\n");
        printf("2. Bai tap 2: Quan ly Nhan Vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("------------------------------------------------\n");
        printf("Chon chuc nang: ");
        if (scanf("%d", &choice) != 1) { flushStdin(); continue; }
        flushStdin();
        switch (choice) {
            case 1: menuStudent(); break;
            case 2: menuEmployee(); break;
            case 0: printf("Thoat Lab 12.\n"); break;
            default: printf("Lua chon khong hop le!\n");
        }
    } while (choice != 0);
    return 0;
}
