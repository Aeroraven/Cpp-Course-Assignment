#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    const float pi = 3.14159f;
    int a, b, angle;
    float s;
    cout << setiosflags(ios::fixed);
    cout << "请输入三角形的两边及其夹角(角度) :" << endl;
    cin >> a >> b >> angle;
    s = 1.0f * a * b / 2 * (float)sin(angle * pi / 180);
    cout << "三角形面积为 : " << setprecision(3) << s << endl;
    return 0;
    
}