#include <iostream>
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
	w = y2 + y2 / 4 + c / 4 - 2*c + 13 * (m + 1) / 5 + d - 1;
	w %= 7;
	w += 7;
	return w % 7;
}

int main()
{
	int y = 0, m = 0, d = 0;
	int leap_flag = 0;
	int day_limit = 0;
	while (1)
	{
		cout << "请输入年[1900-2100]、月、日：" << endl;
		cin >> y >> m >> d;
		if (cin.fail())
		{
			cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		if (y < 1900 || y>2100)
		{
			cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		if ((y % 100 != 0 && y % 4 == 0) || (y % 100 == 0 && y % 400 == 0))
		{
			leap_flag = 1;
		}
		else
		{
			leap_flag = 0;
		}
		if (m < 1 || m>12)
		{
			cout << "月份不正确，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		switch (m)
		{
			case 1:
				day_limit = 31;
				break;
			case 2:
				day_limit = 28 + leap_flag;
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
		if (d > day_limit || d <= 0)
		{
			cout << "日不正确，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		break;
	}
	int w = zeller(y, m, d);
	cout << "星期";
	switch (w)
	{
		case 1:
			cout << "一";
			break;
		case 2:
			cout << "二";
			break;
		case 3:
			cout << "三";
			break;
		case 4:
			cout << "四";
			break;
		case 5:
			cout << "五";
			break;
		case 6:
			cout << "六";
			break;
		case 0:
			cout << "日";
			break;
	}
	cout << endl;
	return 0;
}