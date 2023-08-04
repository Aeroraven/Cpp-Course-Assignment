#include <iostream>
using namespace  std;

int main()
{
	const int LIGHT_CNT = 100;

	int light[LIGHT_CNT];
	for (int i = 0; i < LIGHT_CNT; i++)
	{
		light[i] = 0;
	}
	for (int i = 0; i < LIGHT_CNT; i++)
	{
		for (int j = i; j < LIGHT_CNT; j += (i + 1))
		{
			light[j] = 1 - light[j];
		}
	}
	int first_print = true;
	for (int i = 0; i < LIGHT_CNT; i++)
	{
		if (light[i] == 1)
		{
			if (first_print)
			{
				first_print = false;
			}
			else
			{
				cout << " ";
			}
			cout << (i + 1);
		}
	}
	cout << endl;
	return 0;
}