#include <iostream>
#include <cmath>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int product = i * j;
			cout << j << "x" << i << "=" << product;
			cout << "  ";
			if (product < 10)
			{
				cout << " ";
			}
		}
		cout << endl;
	}
	//demo有额外换行
	cout << endl;
	
	return 0;
}