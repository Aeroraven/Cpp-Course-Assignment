#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	//处理输入
	int year = -1, month = -1, week = -1;
	while (1)
	{
		cout << "请输入年份(2000-2030)和月份(1-12) : ";
		cin >> year >> month;
        
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
        if (year > 2030 || year < 2000 || month < 1 || month>12)
        {
            cout << "输入非法，请重新输入" << endl;
            continue;
        }
		break;
	}
	while (1)
	{
		cout << "请输入" << year << "年" << month << "月1日的星期(0-6表示星期日-星期六) : " ;
		cin >> week;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			cout << "输入非法，请重新输入" << endl;
			continue;
		}
        if (week < 0 || week>6)
        {
            cout << "输入非法，请重新输入" << endl;
            continue;
        }
		break;
	}
	//打印月历
    cout << endl;
	cout << year << "年" << month << "月的月历为:" << endl;
	cout << "星期日  星期一  星期二  星期三  星期四  星期五  星期六"<<endl;
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
	return 0;
}