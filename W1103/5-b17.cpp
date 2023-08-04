#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main()
{
	int upper = 0, lower = 0, number = 0, other = 0, len = 0;
	srand(static_cast<unsigned int>(time(0)));
	cout << "请输入密码长度(12-16)，大写字母个数(≥2)，小写字母个数(≥2)，数字个数(≥2)，其它符号个数(≥2)" << endl;
	while (1)
	{
		cin >> len >> upper >> lower >> number >> other;
		if (cin.fail())
		{
			cout << "输入含有非法字符." << endl;
			return 0;
		}
		if (len < 12 || len>16)
		{
			cout << "密码长度[" << len << "]不正确" << endl;
			return 0;
		}
		if (upper < 2)
		{
			cout << "大写字母个数[" << upper << "]不正确" << endl;
			return 0;
		}
		if (lower < 2)
		{
			cout << "小写字母个数[" << lower << "]不正确" << endl;
			return 0;
		}
		if (number < 2)
		{
			cout << "数字个数[" << number << "]不正确" << endl;
			return 0;
		}
		if (other < 2)
		{
			cout << "其它符号个数[" << other << "]不正确" << endl;
			return 0;
		}
		if (upper + lower + number + other > len)
		{
			cout << "所有字符类型之和[" << upper << "+" << lower << "+" << number << "+" << other << "]大于总密码长度[" << len << "]" << endl;
			return 0;
		}
		break;
	}
	cout << len << " " << upper << " " << lower << " " << number << " " << other << endl;
	char password[10][17];
	for (int T = 0; T < 10; T++)
	{
		int types[4];

		types[0] = upper;
		types[1] = lower;
		types[2] = number;
		types[3] = other;
		int uncategorized = len - (upper + lower + number + other);
		while (uncategorized--)
		{
			types[rand() % 4]++;
		}
		for (int i = 0; i < len; i++)
		{
			while (1)
			{
				int cur_type = rand() % 4;
				if (types[cur_type] != 0)
				{
					types[cur_type]--;
					switch (cur_type)
					{
						case 0:
							password[T][i] = rand() % 26 + 'A';
							break;
						case 1:
							password[T][i] = rand() % 26 + 'a';
							break;
						case 2:
							password[T][i] = rand() % 10 + '0';
							break;
						case 3:
							while (1)
							{
								password[T][i] = rand() % (126 - 33 + 1) + 33;
								if (password[T][i] >= 'a' && password[T][i] <= 'z')
								{
									continue;
								}
								else if (password[T][i] >= 'A' && password[T][i] <= 'Z')
								{
									continue;
								}
								else if (password[T][i] >= '0' && password[T][i] <= '9')
								{
									continue;
								}
								break;
							}
							break;
						default:
							break;
					}
					break;
				}
				continue;
			}
		}
		password[T][len] = '\0';
		cout << password[T] << endl;
	}
	return 0;
}