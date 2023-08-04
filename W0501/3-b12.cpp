#include <iostream>
using namespace std;

int main()
{
	int x;

	while (1)
	{
		cout << "请输入x的值[0-100] : ";
		cin >> x;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(2147483647, '\n');
			continue;
		}
		if (x >= 0 && x <= 100)
			break;
	}
	cout << "x=" << x << endl;
	return 0;
}