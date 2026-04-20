#include <stdio.h>

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

int main() {
    char *filename = "students.txt";
    int n = count_lines(filename);
    Student students[n];
    printf("Input:\n");
    load_students(filename, students);
    print_students(students, n);
}