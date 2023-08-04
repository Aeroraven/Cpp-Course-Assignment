#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
    double a;
    int b;
    printf("请输入找零值:\n");
    int scanfrtn = scanf("%lf,", &a);
    scanfrtn++; //处理W4级别的C4198
    b = (int)(a * 100.0 + 0.5);
    int change_50 = 0, change_20 = 0, change_10 = 0, change_5 = 0, change_1 = 0;
    int change_5jiao = 0, change_1jiao = 0, change_5fen = 0, change_2fen = 0, change_1fen = 0;
    int change_counts = 0;
    if (b >= 5000)
    {
        change_50 = b / 5000;
        b %= 5000;
        change_counts += change_50;
    }
    if (b >= 2000)
    {
        change_20 = b / 2000;
        b %= 2000;
        change_counts += change_20;
    }
    if (b >= 1000)
    {
        change_10 = b / 1000;
        b %= 1000;
        change_counts += change_10;
    }
    if (b >= 500)
    {
        change_5 = b / 500;
        b %= 500;
        change_counts += change_5;
    }
    if (b >= 100)
    {
        change_1 = b / 100;
        b %= 100;
        change_counts += change_1;
    }
    if (b >= 50)
    {
        change_5jiao = b / 50;
        b %= 50;
        change_counts += change_5jiao;
    }
    if (b >= 10)
    {
        change_1jiao = b / 10;
        b %= 10;
        change_counts += change_1jiao;
    }
    if (b >= 5)
    {
        change_5fen = b / 5;
        b %= 5;
        change_counts += change_5fen;
    }
    if (b >= 2)
    {
        change_2fen = b / 2;
        b %= 2;
        change_counts += change_2fen;
    }
    if (b >= 1)
    {
        change_1fen = b;
        change_counts += change_1fen;
    }
    printf("共%d张找零，具体如下：\n", change_counts);
    if (change_50 > 0)
    {
        printf("50元 : %d张\n", change_50);
    }
    if (change_20 > 0)
    {
        printf("20元 : %d张\n", change_20);
    }
    if (change_10 > 0)
    {
        printf("10元 : %d张\n", change_10);
    }
    if (change_5 > 0)
    {
        printf("5元  : %d张\n", change_5);
    }
    if (change_1 > 0)
    {
        printf("1元  : %d张\n", change_1);
    }
    if (change_5jiao > 0)
    {
        printf("5角  : %d张\n", change_5jiao);
    }
    if (change_1jiao > 0)
    {
        printf("1角  : %d张\n", change_1jiao);
    }
    if (change_5fen > 0)
    {
        printf("5分  : %d张\n", change_5fen);
    }
    if (change_2fen > 0)
    {
        printf("2分  : %d张\n", change_2fen);
    }
    if (change_1fen > 0)
    {
        printf("1分  : %d张\n", change_1fen);
    }
    return 0;
}