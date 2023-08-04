#include <iostream>
using namespace std;

int main()
{
    double a;
    int b;
    cout << "请输入找零值:" << endl;
    cin >> a;
    b = static_cast<int>(a * 100.0 + 0.5);
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
    cout << "共" << change_counts << "张找零，具体如下：" << endl;
    if (change_50 > 0)
    {
        cout << "50元 : " << change_50 << "张" << endl;
    }
    if (change_20 > 0)
    {
        cout << "20元 : " << change_20 << "张" << endl;
    }
    if (change_10 > 0)
    {
        cout << "10元 : " << change_10 << "张" << endl;
    }
    if (change_5 > 0)
    {
        cout << "5元  : " << change_5 << "张" << endl;
    }
    if (change_1 > 0)
    {
        cout << "1元  : " << change_1 << "张" << endl;
    }
    if (change_5jiao > 0)
    {
        cout << "5角  : " << change_5jiao << "张" << endl;
    }
    if (change_1jiao > 0)
    {
        cout << "1角  : " << change_1jiao << "张" << endl;
    }
    if (change_5fen > 0)
    {
        cout << "5分  : " << change_5fen << "张" << endl;
    }
    if (change_2fen > 0)
    {
        cout << "2分  : " << change_2fen << "张" << endl;
    }
    if (change_1fen > 0)
    {
        cout << "1分  : " << change_1fen << "张" << endl;
    }
    return 0;
}