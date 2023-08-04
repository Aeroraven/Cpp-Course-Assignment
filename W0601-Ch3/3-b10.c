#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int main()
{
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			int product = i * j;
			printf("%dx%d=%d", j, i, product);
			printf("  ");
			if (product < 10)
			{
				printf(" ");
			}
		}
		printf("\n");
	}
	//demo有额外换行
	printf("\n");

	return 0;
}