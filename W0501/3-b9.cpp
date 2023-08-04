#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;

int main()
{
	int sum_of_factors = 0;
	for (int i = 2; i < 1001; i++)
	{
		sum_of_factors = 0;
		for (int j = 1; j < i; j++)
		{
			if ( i % j == 0 )
			{
				sum_of_factors += j;
			}
		}
		if (sum_of_factors == i)
		{
			cout << i;
			cout << ",its factors are";
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					if (j == 1)
					{
						cout << " " << j;
					}
					else
					{
						cout << "," << j;
					}
				}
			}
			cout << endl;
		}
	}

	return 0;
}