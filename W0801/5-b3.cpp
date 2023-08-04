#include <iostream>
using namespace std;

int main()
{
    const int ARRAY_SIZE = 13;
    int day_limit_map[ARRAY_SIZE] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
    int day_limit_cusum[ARRAY_SIZE] = { 0 };
    int year, month, day, day_limit = 0, day_before = 0;
    cout << "请输入，年，月，日" << endl;

    cin >> year >> month >> day;
    //先判断闰年
    if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
    {
        day_limit_map[2]++;
    }
    //前缀和
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        day_limit_cusum[i] = day_limit_cusum[i - 1] + day_limit_map[i];
    }

    //判断月份
    if (month > 0 && month <= 12)
    {
        
        day_limit = day_limit_map[month];
        day_before = day_limit_cusum[month - 1];
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
