#include <iostream>
#include <string>
#include <cmath>
//可按需增加需要的头文件
using namespace std;

const char chistr[] = "零壹贰叁肆伍陆柒捌玖"; /* 所有输出大写 "零" ~ "玖" 的地方，只允许从这个数组中取值 */
string result;  /* 除result外，不再允许定义任何形式的全局变量 */

/* --允许添加需要的函数 --*/


void daxie(int num, int flag_of_zero)
{
    char tmp[10];
    tmp[0] = chistr[num * 2];
    tmp[1] = chistr[num * 2 + 1];
    tmp[2] = '\0';
    result = result + tmp;
}

/* 可根据需要自定义其它函数(也可以不定义) */
int convert_main()
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
    while (1)
    {
        cout << "请输入[0-100亿)之间的数字: " << endl;
        cin >> a;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(65536, '\n');
            continue;
        }
        if (a < 0.0 || a>1e10)
        {
            continue;
        }
        break;
    }
    
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

    cout << "大写结果是：" << endl;
    //亿位
    if (d10 != 0 || d9 != 0)
    {
        tag1 = 1;
        if (d10 > 0)
        {
            daxie(d10, 0);
            result = result+ "拾";
        }
        if (d9 > 0)
        {
            daxie(d9, 0);
        }
        result = result+ "亿";
    }
    //万位
    if (d5 != 0 || d6 != 0 || d7 != 0 || d8 != 0)
    {
        tag2 = 1;
        if (d8 > 0)
        {
            daxie(d8, 0);
            result = result+ "仟";
        }
        else if ((d7 > 0 || d6 > 0 || d5 > 0) && tag1 == 1)
        {
            daxie(0, 1);
        }
        if (d7 > 0)
        {
            daxie(d7, 0);
            result = result+ "佰";
        }
        else if (d8 > 0 && (d6 > 0 || d5 > 0))
        {
            daxie(0, 1);
        }

        if (d6 > 0)
        {
            daxie(d6, 0);
            result = result+ "拾";
        }
        else if (d7 > 0 && d5 > 0)
        {
            daxie(0, 1);
        }
        if (d5 > 0)
        {
            daxie(d5, 0);
        }
        result = result+ "万";
    }

    //个位
    if (d1 != 0 || d2 != 0 || d3 != 0 || d4 != 0)
    {
        tag3 = 1;
        if (d4 > 0)
        {
            daxie(d4, 0);
            result = result+ "仟";
        }
        else if ((d3 > 0 || d2 > 0 || d1 > 0) && (tag2 == 1 || tag1 == 1))
        {
            daxie(0, 1);
        }
        if (d3 > 0)
        {
            daxie(d3, 0);
            result = result+ "佰";
        }
        else if (d4 > 0 && (d2 > 0 || d1 > 0))
        {
            daxie(0, 1);
        }

        if (d2 > 0)
        {
            daxie(d2, 0);
            result = result+ "拾";
        }
        else if (d3 > 0 && d1 > 0)
        {
            daxie(0, 1);
        }
        if (d1 > 0)
        {
            daxie(d1, 0);
        }

    }
    if (tag1 == 0 && tag2 == 0 && tag3 == 0 && d_dec1 == 0 && d_dec2 == 0)
    {
        daxie(0, 1);
        result = result+ "圆";
    }
    if (tag1 != 0 || tag2 != 0 || tag3 != 0)
    {
        result = result+ "圆";
        tag4 = 1;
    }
    //小数
    if (d_dec1 == 0 && d_dec2 == 0)
    {
        result = result+ "整";
    }
    else
    {
        if (d_dec1 != 0)
        {
            daxie(d_dec1, 0);
            result = result+ "角";
            if (d_dec2 == 0)
            {
                result = result+ "整";
            }
        }
        else if (tag4 == 1 && d_dec2 != 0)
        {
            daxie(0, 1);
        }
        if (d_dec2 != 0)
        {
            daxie(d_dec2, 0);
            result = result+ "分";
        }
    }

    return 0;
}


/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int main()
{
    /* --允许添加需要的内容 --*/

    convert_main();
    cout << result << endl;  /* 转换得到的大写结果，只允许用本语句输出，之前不允许任何形式的部分输出 */
    return 0;
}
