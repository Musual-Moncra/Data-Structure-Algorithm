/*
Bài tập tuần 5
Bài tập 1: Dùng Selection sort để sắp xếp danh sách sinh viên theo tăng dần của cột Name.
Input: file students.txt
Output: danh sách sinh viên đã được sắp xếp theo Name tăng dần
Yêu cầu: sinh viên hoàn thành code tại vị trí có comment "YOUR CODE HERE..." trong hàm sort_by_name()
*/
#include <stdio.h>
#include <string.h>

// Define a Student struct
typedef struct Student {
    int sid;
    char name[30];
    float gpa;
} Student;

// print array of students
void print_students(Student s[], int n) {
    printf("ID\t Name\t Score\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t %s\t %.2f\n", s[i].sid, s[i].name, s[i].gpa);
    }
}

// Dùng để đếm số lượng dòng trong file students.txt
// tương ứng với số sinh viên
int count_lines(char *filename) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Can not open file %s\n", filename);
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

// function to read data student from txt file
void load_students(char *filename, Student students[]) {
    FILE *f = fopen(filename, "r");
    if (f == NULL) {
        printf("Can not open file students.txt\n");
        return;
    }

    int i = 0;
    while (!feof(f)) {
        fscanf(f, "%d %s %f", &students[i].sid, students[i].name,
               &students[i].gpa);
        i++;
    }
    fclose(f);
}

// sort students by increasing name (Selection sort)
void sort_by_name(Student s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        // Tìm vị trí của tên có thứ tự từ điển nhỏ nhất trong phần chưa sắp xếp
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            // strcmp trả về giá trị âm nếu chuỗi 1 nhỏ hơn (đứng trước) chuỗi 2
            if (strcmp(s[j].name, s[min_idx].name) < 0) {
                min_idx = j;
            }
        }
        
        // Đổi chỗ sinh viên có tên đứng trước lên vị trí hiện tại i
        if (min_idx != i) {
            Student temp = s[i];
            s[i] = s[min_idx];
            s[min_idx] = temp;
        }
    }
}

int main() {
    char *filename = "students.txt";
    int n = count_lines(filename);
    Student students[n];
    printf("Input:\n");
    load_students(filename, students);
    print_students(students, n);
    // gọi hàm sắp xếp
    sort_by_name(students, n);
    printf("Sorted Output:\n");
    print_students(students, n);
}
