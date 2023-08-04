#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x;
	int scanf_return;
	int c;
	while (1)
	{
		printf("请输入x的值[0-100] : ");
		scanf_return = scanf("%d", &x); //读入x的方式必须是scanf且格式符为%d，不准用非scanf
		if (scanf_return == 0)
		{
			while ((c = getchar()) != '\n' && c != -1)
				;
		}
		if (x >= 0 && x <= 100)
			break;
	}

	printf("x=%d\n", x);

	return 0;
}