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
	int day_limit_map[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	
	int y;
	while (1) {
		cout << "请输入年份[1900-2100]" << endl;
		cin >> y;
		if (cin.fail())
		{
			//cout << "输入错误，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		if (y < 1900 || y>2100)
		{
			//cout << "年份不正确，请重新输入" << endl;
			cin.clear();
			cin.sync();
			cin.ignore(2147483647, '\n');
			continue;
		}
		break;
	}
	if ((y % 4 == 0 && y % 100 != 0) || (y % 100 == 0 && y % 400 == 0))
	{
		day_limit_map[2]++;
	}
	cout << y << "年的日历:" << endl << endl;
	int days[13];
	for (int i = 1; i <= 12; i++)
	{
		days[i] = zeller(y, i, 1);
	}

	for (int i = 0; i < 4; i++)
	{
		cout << resetiosflags(ios::left);
		cout << setiosflags(ios::right);
		cout << setw(13) << (i * 3 + 1) << "月";
		cout << setw(30) << (i * 3 + 2) << "月";
		cout << setw(30) << (i * 3 + 3) << "月" << endl;

		for (int j = 0; j < 3; j++)
		{
			cout << "Sun Mon Tue Wed Thu Fri Sat";
			if (j != 2)
			{
				cout << "     ";
			}
		}
		cout << endl;
		
		int month_base = i * 3 + 1;
		int month_start[4];
		int has_output = false;
		month_start[1] = -days[month_base] + 1;
		month_start[2] = -days[month_base + 1] + 1;
		month_start[3] = -days[month_base + 2] + 1;
		int terminate_output_1 = 0;
		int terminate_output_2 = 0;
		int terminate_output_3 = 0;
		//cout << month_start[1] << "," << month_start[2] << "," << month_start[3] << "###" << endl;
		while (1)
		{
			if (terminate_output_1 & terminate_output_2 & terminate_output_3)
			{
				cout << endl;
				break;
			}
			has_output = 0;
			for (int j = 1; j <= 3; j++)
			{
				int month = i * 3 + j;
				int month2 = month % 3 + (month % 3 == 0) * 3;
				for (int k = 1; k <= 7; k++)
				{
					if (month_start[month2] <= 0 || month_start[month2] > day_limit_map[month])
					{
						month_start[month2]++;
						if (month_start[month2] > day_limit_map[month])
						{
							if (j == 1)
							{
								terminate_output_1 = 1;

							}
							if (j == 2)
							{
								terminate_output_2 = 1;

							}
							if (j == 3)
							{
								terminate_output_3 = 1;

							}
						}
						cout << "    ";
					}
					else
					{
						cout << resetiosflags(ios::right);
						cout << setiosflags(ios::left);
						cout << setw(4) << month_start[month2]++;
						has_output = true;
						if (month_start[month2] > day_limit_map[month])
						{
							if (j == 1)
							{
								terminate_output_1 = 1;

							}
							if (j == 2)
							{
								terminate_output_2 = 1;

							}
							if (j == 3)
							{
								terminate_output_3 = 1;

							}
						}
					}
				}
				if (j != 3)
				{
					cout << "    ";
				}
				
			}
			cout << endl;
			if (!has_output)
			{
				break;
			}
		}
		
	}
	cout << endl;
	return 0;
}