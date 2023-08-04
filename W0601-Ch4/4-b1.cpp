#include <iostream>
#include <cmath>
using namespace std;

/***************************************************************************
  函数名称：
  功    能：输出大写的0~9
  输入参数：
  返 回 值：
  说    明：除本函数外，不允许任何函数中输出“零”-“玖”!!!!!!
***************************************************************************/
void daxie(int num, int flag_of_zero)
{
    /* 不允许对本函数做任何修改 */
    switch (num) {
        case 0:
            if (flag_of_zero)	//此标记什么意思请自行思考
                cout << "零";
            break;
        case 1:
            cout << "壹";
            break;
        case 2:
            cout << "贰";
            break;
        case 3:
            cout << "叁";
            break;
        case 4:
            cout << "肆";
            break;
        case 5:
            cout << "伍";
            break;
        case 6:
            cout << "陆";
            break;
        case 7:
            cout << "柒";
            break;
        case 8:
            cout << "捌";
            break;
        case 9:
            cout << "玖";
            break;
        default:
            cout << "error";
            break;
    }
}

/* 可根据需要自定义其它函数(也可以不定义) */
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
    cout << "请输入[0-100亿)之间的数字: " << endl;
    cin >> a;
    b = fmod(a, 1);
    d_dec2 = static_cast<int>(b * 100.0 + 0.5) % 10;
    d_dec1 = static_cast<int>(round(1e1 * fmod(b * 1e+1, 1e+1)) / 1e1);
    d1 = static_cast<int>((fmod(a, 1e+1) - fmod(a, 1e+0)) / 1e+0);
    d2 = static_cast<int>((fmod(a, 1e+2) - fmod(a, 1e+1)) / 1e+1);
    d3 = static_cast<int>((fmod(a, 1e+3) - fmod(a, 1e+2)) / 1e+2);
    d4 = static_cast<int>((fmod(a, 1e+4) - fmod(a, 1e+3)) / 1e+3);
    d5 = static_cast<int>((fmod(a, 1e+5) - fmod(a, 1e+4)) / 1e+4);
    d6 = static_cast<int>((fmod(a, 1e+6) - fmod(a, 1e+5)) / 1e+5);
    d7 = static_cast<int>((fmod(a, 1e+7) - fmod(a, 1e+6)) / 1e+6);
    d8 = static_cast<int>((fmod(a, 1e+8) - fmod(a, 1e+7)) / 1e+7);
    d9 = static_cast<int>((fmod(a, 1e+9) - fmod(a, 1e+8)) / 1e+8);
    d10 = static_cast<int>((fmod(a, 1e+10) - fmod(a, 1e+9)) / 1e+9);

    cout << "大写结果是：" << endl;
    //亿位
    if (d10 != 0 || d9 != 0)
    {
        tag1 = 1;
        if (d10 > 0)
        {
            daxie(d10, 0);
            cout << "拾";
        }
        if (d9 > 0)
        {
            daxie(d9, 0);
        }
        cout << "亿";
    }
    //万位
    if (d5 != 0 || d6 != 0 || d7 != 0 || d8 != 0)
    {
        tag2 = 1;
        if (d8 > 0)
        {
            daxie(d8, 0);
            cout << "仟";
        }
        else if ((d7 > 0 || d6 > 0 || d5 > 0) && tag1 == 1)
        {
            daxie(0, 1);
        }
        if (d7 > 0)
        {
            daxie(d7, 0);
            cout << "佰";
        }
        else if (d8 > 0 && (d6 > 0 || d5 > 0))
        {
            daxie(0, 1);
        }

        if (d6 > 0)
        {
            daxie(d6, 0);
            cout << "拾";
        }
        else if (d7 > 0 && d5 > 0)
        {
            daxie(0, 1);
        }
        if (d5 > 0)
        {
            daxie(d5, 0);
        }
        cout << "万";
    }

    //个位
    if (d1 != 0 || d2 != 0 || d3 != 0 || d4 != 0)
    {
        tag3 = 1;
        if (d4 > 0)
        {
            daxie(d4, 0);
            cout << "仟";
        }
        else if ((d3 > 0 || d2 > 0 || d1 > 0) && (tag2 == 1 || tag1 == 1))
        {
            daxie(0, 1);
        }
        if (d3 > 0)
        {
            daxie(d3, 0);
            cout << "佰";
        }
        else if (d4 > 0 && (d2 > 0 || d1 > 0))
        {
            daxie(0, 1);
        }

        if (d2 > 0)
        {
            daxie(d2, 0);
            cout << "拾";
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
        cout << "圆";
    }
    if (tag1 != 0 || tag2 != 0 || tag3 != 0)
    {
        cout << "圆";
        tag4 = 1;
    }
    //小数
    if (d_dec1 == 0 && d_dec2 == 0)
    {
        cout << "整";
    }
    else
    {
        if (d_dec1 != 0)
        {
            daxie(d_dec1, 0);
            cout << "角";
            if (d_dec2 == 0)
            {
                cout << "整";
            }
        }
        else if (tag4 == 1 && d_dec2 != 0)
        {
            daxie(0, 1);
        }
        if (d_dec2 != 0)
        {
            daxie(d_dec2, 0);
            cout << "分";
        }
    }
    //行末换行
    cout << endl;
    return 0;
}
