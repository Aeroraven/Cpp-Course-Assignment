#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double a;
    cout << "请输入[0-100亿)之间的数字: " << endl;
    cin >> a;
    cout << setprecision(ios::fixed);
    cout << "十亿位 : " << static_cast<int>((fmod(a, 1e+10) - fmod(a, 1e+9)) / 1e+9) << endl;
    cout << "亿位   : " << static_cast<int>((fmod(a, 1e+9) - fmod(a, 1e+8)) / 1e+8) << endl;
    cout << "千万位 : " << static_cast<int>((fmod(a, 1e+8) - fmod(a, 1e+7)) / 1e+7) << endl;
    cout << "百万位 : " << static_cast<int>((fmod(a, 1e+7) - fmod(a, 1e+6)) / 1e+6) << endl;
    cout << "十万位 : " << static_cast<int>((fmod(a, 1e+6) - fmod(a, 1e+5)) / 1e+5) << endl;
    cout << "万位   : " << static_cast<int>((fmod(a, 1e+5) - fmod(a, 1e+4)) / 1e+4) << endl;
    cout << "千位   : " << static_cast<int>((fmod(a, 1e+4) - fmod(a, 1e+3)) / 1e+3) << endl;
    cout << "百位   : " << static_cast<int>((fmod(a, 1e+3) - fmod(a, 1e+2)) / 1e+2) << endl;
    cout << "十位   : " << static_cast<int>((fmod(a, 1e+2) - fmod(a, 1e+1)) / 1e+1) << endl;
    cout << "圆     : " << static_cast<int>((fmod(a, 1e+1) - fmod(a, 1e+0)) / 1e+0) << endl;
    //由于要求不许对数整体扩大，为了获取小数部分数位，先获取小数部分数值，存于变量b中
    double b = fmod(a, 1.0);
    //由于精度误差,输入的a和实际存储的a值不同，故特别处理小数后两位的问题
    cout << "角     : " << static_cast<int>(round(1e1 * fmod(b * 1e+1, 1e+1)) / 1e1) << endl;
    cout << "分     : " << static_cast<int>(round((fmod(b * 1e+2, 1e+1)))) % 10 << endl;

    return 0;
}