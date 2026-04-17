# Project Data Structures & Algorithms

This documentation outlines the exercises and solutions implemented for the Data Structures and Algorithms coursework.

## Developer: Nguyễn Thái Bảo

### Folder Structure
- `src/Nguyễn Thái Bảo/Week4`: Contains the C source code for Lab 05 (Sorting algorithms Part I).
- `src/Nguyễn Thái Bảo/Week5`: Contains the replicated content for Week 5, continuing the study of Sorting and function pointers.
- `documents/`: Centralized documentation for the project.
- `storage/`: Holds technical notes and algorithmic analyses.

### Exercises Completed
- **Lab 05 (Sorting Part 1)**
  1. Bubble Sort: Sorting a list of students by score in descending order.
  2. Selection Sort: Sorting a list of students by name in ascending order.
  3. Hybrid Bubble Sort: Sorting a list of students by name (case-insensitive) ascending, and if identical, by score descending.
  4. Advanced Sorting: Using function pointers to abstract the sorting mechanism, allowing users to dynamically choose a column (Name or Score) and the sort direction (Ascending or Descending).

### Build Instruction
Navigate to the week folder and compile the C file using GCC:
```bash
cd "src/Nguyễn Thái Bảo/Week4"
gcc main.c -o sort_app
./sort_app
```
