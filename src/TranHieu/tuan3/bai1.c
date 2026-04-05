/*Cài đặt các thuật toán tham lam (bài toán đổi tiền), thuật toán chia để trị (bài toán tìm đồng
xu giả).*/

#include <stdio.h>

void changeMoney(int money, int note[])
{
    int quantity = 0;
    int i = 0;
    while (money > 0)
    {
        quantity = money/note[i];
        if (quantity > 0)
        {
            printf("So to tien %d: %d", note[i], quantity);
            money %= note[i];
        }
        i++;
    }   
}   

int main() 
{
    int money;
    printf("Bai toan doi tien\n");
    printf("nhap so tien can doi: ");
    scanf("%d", &money);
    int note[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    int n = sizeof(note)/sizeof(note[0]);
    changeMoney(money, note);
    return 0;

}
