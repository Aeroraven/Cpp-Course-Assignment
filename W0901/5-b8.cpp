#include<iostream>
#include<cmath>
using namespace std;

double vector_product(double x1, double y1, double x2, double y2)
{
	return x1 * y2 - x2 * y1;
}

int main()
{
	const double EPS = 1e-9;
	const int ARRAY_SIZE = 30;
	int n;
	double x[ARRAY_SIZE], y[ARRAY_SIZE];
	double prod[ARRAY_SIZE];
	x[1] = 0;
	y[1] = 0;
	while (1)
	{
		n = -1;
		cout << "请输入多边形的顶点数量(4-7)" << endl;
		cin >> n;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(65536, '\n');
			continue;
		}
		if (n > 7 || n < 4)
		{
			continue;
		}
		break;
	}
	double test = 2498230480;

	cout << "请按顺时针/逆时针方向输入" << n << "个顶点的x,y坐标：" << endl;
	for (int i = 1; i <= n; i++)
	{
		while (1)
		{
			cout << "请输入第" << i << "个顶点的坐标：" << endl;
			cin >> x[i] >> y[i];
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(65536, '\n');
				continue;
			}
			break;
		}
	}
	int valid_flag = true;
	//判断共线
	/*
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 1; k <= n; k++)
			{
				if (i == k || j == k || i == j)
				{
					continue;
				}
				double slope1, slope2;
				slope1 = (y[k] - y[i]) / (x[k] - x[i]);
				slope2 = (y[j] - y[i]) / (x[j] - x[i]);
				if (fabs(slope2 - slope1) <= EPS)
				{
					valid_flag = false;
				}
			}
		}
	}*/

	//凹凸性判断
	int seq_order = true, rev_order = true;
	for (int i = 1; i < n-1; i++)
	{
		prod[i] = vector_product(x[i+1]-x[i], y[i+1]-y[i], x[i + 2] - x[i], y[i + 2] - y[i]);
	}
	if (n - 1 > 0)
	{
		prod[n - 1] = vector_product(x[n] - x[n - 1], y[n] - y[n - 1], x[1] - x[n - 1], y[1] - y[n - 1]);

	}
	prod[n] = vector_product(x[1] - x[n], y[1] - y[n], x[2] - x[n], y[2] - y[n]);

	for (int i = 1; i <= n; i++)
	{
		if (prod[i] < 0.0)
		{
			seq_order = false;
		}
		if (prod[i] > 0.0)
		{
			rev_order = false;
		}
		if (fabs(prod[i]) <= EPS)
		{
			valid_flag = false;
		}
	}
	if (seq_order == false && rev_order == false)
	{
		valid_flag = false;
	}

	if (valid_flag)
	{
		double ans = 0;
		for (int i = 1; i < n; i++)
		{
			ans += vector_product(x[i], y[i], x[i + 1], y[i + 1]);
		}
		ans += vector_product(x[n], y[n], x[1], y[1]);
		ans = fabs(ans) * 0.5;
		cout << "凸" << n << "边形的面积=" << ans << endl;
	}
	else
	{
		cout << "不是凸" << n << "边形" << endl;
	}
	return 0;
}
