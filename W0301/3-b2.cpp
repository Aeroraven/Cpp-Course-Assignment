#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double pi = 3.14159;
    double radius, height;
    cout << "请输入半径和高度" << endl;
    cin >> radius >> height;
    cout << setiosflags(ios::fixed);
    cout << "圆周长     : " << setprecision(2) << (pi * radius * 2.0) << endl;
    cout << "圆面积     : " << setprecision(2) << (pi * radius * radius) << endl;
    cout << "圆球表面积 : " << setprecision(2) << (pi * radius * radius * 4.0) << endl;
    cout << "圆球体积   : " << setprecision(2) << (pi * radius * radius * radius * 4.0 / 3.0) << endl;
    cout << "圆柱体积   : " << setprecision(2) << (pi * radius * radius * height) << endl;

    return 0;
}
