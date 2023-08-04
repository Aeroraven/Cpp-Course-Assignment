#include <iostream>
using namespace std;

int main()
{
    int year, month, day, day_limit = 0, day_before = 0;
    int leap_year = 0;
    cout << "请输入，年，月，日" << endl;

    cin >> year >> month >> day;
    //先判断闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
    {
        leap_year = 1;
    }
    //判断月份
    if (month > 0 && month <= 12)
    {
        switch (month)
        {
            case 1:
                day_limit = 31;
                day_before = 0;
                break;
            case 2:
                day_limit = 28 + leap_year;
                day_before = 31;
                break;
            case 3:
                day_limit = 31;
                day_before = 59 + leap_year;
                break;
            case 4:
                day_limit = 30;
                day_before = 90 + leap_year;
                break;
            case 5:
                day_limit = 31;
                day_before = 120 + leap_year;
                break;
            case 6:
                day_limit = 30;
                day_before = 151 + leap_year;
                break;
            case 7:
                day_limit = 31;
                day_before = 181 + leap_year;
                break;
            case 8:
                day_limit = 31;
                day_before = 212 + leap_year;
                break;
            case 9:
                day_limit = 30;
                day_before = 243 + leap_year;
                break;
            case 10:
                day_limit = 31;
                day_before = 273 + leap_year;
                break;
            case 11:
                day_limit = 30;
                day_before = 304 + leap_year;
                break;
            case 12:
                day_limit = 31;
                day_before = 334 + leap_year;
                break;

        }
        if (day > day_limit || day <= 0)
        {
            cout << "输入错误-日与月的关系非法";
        }
        else
        {
            cout << year << "-" << month << "-" << day << "是";
            cout << year << "年的第" << day_before + day << "天";
        }
    }
    else
    {
        cout << "输入错误-月份不正确";
    }
    cout << endl;

    return 0;
}
