#include <stdio.h>
#include <string.h>

// Ham de quy kiem tra Palindrome
// s: chuoi can kiem tra
// start: vi tri dau, end: vi tri cuoi
int isPalindrome(char s[], int start, int end) 
{
    // 1. Diem dung: Neu chi con 0 hoac 1 ky tu
    if (start >= end) // chi co 1 => doi xung
	{
        return 1;
    }

    // 2. Kiem tra ky tu dau va cuoi co giong nhau khong
    if (s[start] != s[end]) 
	{
        return 0; // Khong doi xung
    }

    // 3. De quy: Kiem tra tiep phan o giua
    return isPalindrome(s, start + 1, end - 1);
}

int main() 
{
    char str[100];
    printf("Nhap vao mot tu: ");
    scanf("%s", str);

    int n = strlen(str); // Lay do dai chuoi

    // Goi ham: start = 0, end = n - 1
    if (isPalindrome(str, 0, n - 1)) 
	{
        printf("%s la tu doi xung (Palindrome).\n", str);
    } else {
        printf("%s KHONG phai la tu doi xung.\n", str);
    }

    return 0;
}
