#include <iostream>
#include <cmath>
using namespace std;

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
            switch (d10)
            {
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
            }
            cout << "拾";
        }
        if (d9 > 0)
        {
            switch (d9)
            {
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
            }
        }
        cout << "亿";
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
            }
            cout << "仟";
        }
        else if ((d7 > 0 || d6 > 0 || d5 > 0) && tag1 == 1)
        {
            cout << "零";
        }
        if (d7 > 0)
        {
            switch (d7)
            {
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
            }
            cout << "佰";
        }
        else if (d8 > 0 && (d6 > 0 || d5 > 0))
        {
            cout << "零";
        }

        if (d6 > 0)
        {
            switch (d6)
            {
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
            }
            cout << "拾";
        }
        else if (d7 > 0 && d5 > 0)
        {
            cout << "零";
        }
        if (d5 > 0)
        {
            switch (d5)
            {
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
            }
        }
        cout << "万";
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
            }
            cout << "仟";
        }
        else if ((d3 > 0 || d2 > 0 || d1 > 0) && (tag2 == 1 || tag1 == 1))
        {
            cout << "零";
        }
        if (d3 > 0)
        {
            switch (d3)
            {
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
            }
            cout << "佰";
        }
        else if (d4 > 0 && (d2 > 0 || d1 > 0))
        {
            cout << "零";
        }

        if (d2 > 0)
        {
            switch (d2)
            {
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
            }
            cout << "拾";
        }
        else if (d3 > 0 && d1 > 0)
        {
            cout << "零";
        }
        if (d1 > 0)
        {
            switch (d1)
            {
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
            }
        }

    }
    if (tag1 == 0 && tag2 == 0 && tag3 == 0 && d_dec1 == 0 && d_dec2 == 0)
    {
        cout << "零圆";
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
            switch (d_dec1)
            {
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
            }
            cout << "角";
            if (d_dec2 == 0)
            {
                cout << "整";
            }
        }
        else if (tag4 == 1 && d_dec2 != 0)
        {
            cout << "零";
        }
        if (d_dec2 != 0)
        {
            switch (d_dec2)
            {
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
            }
            cout << "分";
        }
    }
    //行末换行
    cout << endl;
    return 0;
}
