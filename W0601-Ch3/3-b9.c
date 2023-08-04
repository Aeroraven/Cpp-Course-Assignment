#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int sum_of_factors = 0;
	for (int i = 2; i < 1001; i++)
	{
		sum_of_factors = 0;
		for (int j = 1; j < i; j++)
		{
			if (i % j == 0)
			{
				sum_of_factors += j;
			}
		}
		if (sum_of_factors == i)
		{
			printf("%d,its factors are", i);
			
			for (int j = 1; j < i; j++)
			{
				if (i % j == 0)
				{
					if (j == 1)
					{
						printf(" %d", j);
						
					}
					else
					{
						printf(",%d", j);
					}
				}
			}
			printf("\n");
		}
	}

	return 0;
}