#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int zeller(int y, int m, int d)
{
    if (m <= 2)
    {
        y--;
        m += 12;
    }
    int c = y / 100;
    int y2 = y % 100;
    int w;
    w = y2 + y2 / 4 + c / 4 - 2 * c + 13 * (m + 1) / 5 + d - 1;
    w %= 7;
    w += 7;
    return w % 7;
}


int main()
{
    //处理输入
    int year = -1, month = -1, week = -1;
    int c;
    while (1)
    {
        printf("请输入年[1900-2100]、月\n");

        if (scanf("%d%d", &year, &month)!=2)
        {
            while ((c = getchar()) != '\n' && c != -1)
                ;
            printf("输入非法，请重新输入\n");
            continue;
        }

        if (year > 2100 || year < 1900)
        {
            printf("年份不正确，请重新输入\n");
            while ((c = getchar()) != '\n' && c != -1)
                ;
            continue;
        }
        if (month < 1 || month>12)
        {
            printf("月份不正确，请重新输入\n");
            while ((c = getchar()) != '\n' && c != -1)
                ;
            continue;
        }
        break;
    }
    week = zeller(year, month, 1);
    //打印月历
    printf("\n");
    printf("%d年%d月\n", year, month);
    printf("======================================================\n");
    printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
    printf("======================================================\n");
    int day_limit = 28, leap_year = 0;
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
    {
        leap_year = 1;
    }

    switch (month)
    {
        case 1:
            day_limit = 31;
            break;
        case 2:
            day_limit = 28 + leap_year;
            break;
        case 3:
            day_limit = 31;
            break;
        case 4:
            day_limit = 30;
            break;
        case 5:
            day_limit = 31;
            break;
        case 6:
            day_limit = 30;
            break;
        case 7:
            day_limit = 31;
            break;
        case 8:
            day_limit = 31;
            break;
        case 9:
            day_limit = 30;
            break;
        case 10:
            day_limit = 31;
            break;
        case 11:
            day_limit = 30;
            break;
        case 12:
            day_limit = 31;
            break;

    }
    for (int i = 1 - week, j = 0; i <= day_limit; i++, j++, j %= 7)
    {
        if (i <= 0)
        {
            printf("    ");
        }
        else
        {
            if (i < 10)
            {
                printf("   %d", i);
            }
            else
            {
                printf("  %d", i);
            }
        }
        printf("    ");
        //按照Demo输出规则，在星期六输出结束后换行，而非在星期天输出之前换行
        if (j == 6)
        {
            printf("\n");
        }
    }
    //行末换行
    printf("\n");
    printf("\n"); //Demo有额外换行
    return 0;
}