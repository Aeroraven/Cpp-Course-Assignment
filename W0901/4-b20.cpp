#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int min(int a, int b= 2147483647, int c=2147483647, int d= 2147483647)
{
	int f = (a > b) ? b : a;
	int g = (c > d) ? d : c;
	return (f > g) ? g : f;
}
int main()
{
	int a, b, c, d, n = 15;
	int f = 0;
	while (1)
	{
		f = 0;
		cout << "请输入个数num及num个正整数：" << endl;
		cin >> n;
		if (cin.fail())
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		if (n > 4 || n < 2)
		{
			cout << "个数输入错误" << endl;
			return 0;
		}
		for (int i = 1; i <= n; i++)
		{
			if (i == 1)
			{
				a = 0;
				cin >> a;
				if (cin.fail() || a <= 0)
				{
					cin.clear();
					cin.ignore(65536, '\n');
					f = 1;
					break;
				}
			}
			if (i == 2)
			{
				b = 0;
				cin >> b;
				if (cin.fail() || b <= 0)
				{
					cin.clear();
					cin.ignore(65536, '\n');
					f = 1;
					break;
				}
			}
			if (i == 3)
			{
				c = 0;
				cin >> c;
				if (cin.fail() || c <= 0)
				{
					cin.clear();
					cin.ignore(65536, '\n');
					f = 1;
					break;
				}
			}
			if (i == 4)
			{
				d = 0;
				cin >> d;
				if (cin.fail() || d <= 0)
				{
					cin.clear();
					cin.ignore(65536, '\n');
					f = 1;
					break;
				}
			}
		}
		if (f == 0)
		{
			break;
		}
	}
	int ans = 0;
	switch (n) {
		case 2:
			ans = min(a, b);
			break;
		case 3:
			ans = min(a, b, c);
			break;
		case 4:
			ans = min(a, b, c, d);
			break;
		default:
			break;
	}
	cout << "min=" << ans << endl;
	return 0;
}