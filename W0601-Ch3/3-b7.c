#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


int main()
{
    double a;
    double b;
    //小数数位
    int d_dec1, d_dec2;
    //整数数位
    int d1, d2, d3, d4;
    int d5, d6, d7, d8;
    int d9, d10;
    //标记
    int tag1 = 0, tag2 = 0, tag3 = 0;
    int tag4 = 0;
    printf("请输入[0-100亿)之间的数字: \n");
    int scanfrtn = scanf("%lf,", &a);
    scanfrtn++; //处理W4级别的4198
    b = fmod(a, 1);
    d_dec2 = (int)(b * 100.0 + 0.5) % 10;
    d_dec1 = (int)(round(1e1 * fmod(b * 1e+1, 1e+1)) / 1e1);
    d1 = (int)((fmod(a, 1e+1) - fmod(a, 1e+0)) / 1e+0);
    d2 = (int)((fmod(a, 1e+2) - fmod(a, 1e+1)) / 1e+1);
    d3 = (int)((fmod(a, 1e+3) - fmod(a, 1e+2)) / 1e+2);
    d4 = (int)((fmod(a, 1e+4) - fmod(a, 1e+3)) / 1e+3);
    d5 = (int)((fmod(a, 1e+5) - fmod(a, 1e+4)) / 1e+4);
    d6 = (int)((fmod(a, 1e+6) - fmod(a, 1e+5)) / 1e+5);
    d7 = (int)((fmod(a, 1e+7) - fmod(a, 1e+6)) / 1e+6);
    d8 = (int)((fmod(a, 1e+8) - fmod(a, 1e+7)) / 1e+7);
    d9 = (int)((fmod(a, 1e+9) - fmod(a, 1e+8)) / 1e+8);
    d10 = (int)((fmod(a, 1e+10) - fmod(a, 1e+9)) / 1e+9);

    printf("大写结果是：\n");
    //亿位
    if (d10 != 0 || d9 != 0)
    {
        tag1 = 1;
        if (d10 > 0)
        {
            switch (d10)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("拾");
            
        }
        if (d9 > 0)
        {
            switch (d9)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
        }
        printf("亿");
        
    }
    //万位
    if (d5 != 0 || d6 != 0 || d7 != 0 || d8 != 0)
    {
        tag2 = 1;
        if (d8 > 0)
        {
            switch (d8)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("仟");
            
        }
        else if ((d7 > 0 || d6 > 0 || d5 > 0) && tag1 == 1)
        {
            printf("零");
        }
        if (d7 > 0)
        {
            switch (d7)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("佰");
            
        }
        else if (d8 > 0 && (d6 > 0 || d5 > 0))
        {
            printf("零");
        }

        if (d6 > 0)
        {
            switch (d6)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("拾");
            
        }
        else if (d7 > 0 && d5 > 0)
        {
            printf("零");
        }
        if (d5 > 0)
        {
            switch (d5)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
        }
        printf("万");
        
    }

    //个位
    if (d1 != 0 || d2 != 0 || d3 != 0 || d4 != 0)
    {
        tag3 = 1;
        if (d4 > 0)
        {
            switch (d4)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("仟");
            
        }
        else if ((d3 > 0 || d2 > 0 || d1 > 0) && (tag2 == 1 || tag1 == 1))
        {
            printf("零");
        }
        if (d3 > 0)
        {
            switch (d3)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("佰");

        }
        else if (d4 > 0 && (d2 > 0 || d1 > 0))
        {
            printf("零");
        }

        if (d2 > 0)
        {
            switch (d2)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("拾");

        }
        else if (d3 > 0 && d1 > 0)
        {
            printf("零");
        }
        if (d1 > 0)
        {
            switch (d1)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
        }

    }
    if (tag1 == 0 && tag2 == 0 && tag3 == 0 && d_dec1 == 0 && d_dec2 == 0)
    {
        printf("零圆");
        
    }
    if (tag1 != 0 || tag2 != 0 || tag3 != 0)
    {
        printf("圆");
        tag4 = 1;
    }
    //小数
    if (d_dec1 == 0 && d_dec2 == 0)
    {
        printf("整");
    }
    else
    {
        if (d_dec1 != 0)
        {
            switch (d_dec1)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("角");
            if (d_dec2 == 0)
            {
                printf("整");
            }
        }
        else if (tag4 == 1 && d_dec2 != 0)
        {
            printf("零");
        }
        if (d_dec2 != 0)
        {
            switch (d_dec2)
            {
                case 1:
                    printf("壹");
                    break;
                case 2:
                    printf("贰");
                    break;
                case 3:
                    printf("叁");
                    break;
                case 4:
                    printf("肆");
                    break;
                case 5:
                    printf("伍");
                    break;
                case 6:
                    printf("陆");
                    break;
                case 7:
                    printf("柒");
                    break;
                case 8:
                    printf("捌");
                    break;
                case 9:
                    printf("玖");
                    break;
            }
            printf("分");
        }
    }
    //行末换行
    printf("\n");
    return 0;
}
