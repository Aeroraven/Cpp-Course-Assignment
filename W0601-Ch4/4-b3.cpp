#include <iostream>
#include <iomanip>
using namespace std;

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
    while (1)
    {
        cout << "请输入年[1900-2100]、月" << endl;
        cin >> year >> month;

        if (cin.fail())
        {
            cin.clear();
            cin.sync();
            cin.ignore(2147483647, '\n');
            cout << "输入非法，请重新输入" << endl;
            continue;
        }
        if (year > 2100 || year < 1900)
        {
            cin.clear();
            cin.sync();
            cin.ignore(2147483647, '\n');
            cout << "年份不正确，请重新输入" << endl;
            continue;
        }
        if (month < 1 || month>12)
        {
            cin.clear();
            cin.sync();
            cin.ignore(2147483647, '\n');
            cout << "月份不正确，请重新输入" << endl;
            continue;
        }
        break;
    }
    week = zeller(year, month, 1);
    //打印月历
    cout << endl;
    cout << year << "年" << month << "月" << endl;
    cout << "======================================================" << endl;
    cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六" << endl;
    cout << "======================================================" << endl;
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
        cout << setw(4);
        if (i <= 0)
        {
            cout << " ";
        }
        else
        {
            cout << i;
        }
        cout << "    ";
        //按照Demo输出规则，在星期六输出结束后换行，而非在星期天输出之前换行
        if (j == 6)
        {
            cout << endl;
        }
    }
    //行末换行
    cout << endl;
    cout << endl; //Demo有额外换行
    return 0;
}