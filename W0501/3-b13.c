#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	//处理输入
	int year = -1, month = -1, week = -1, scanf_return = 0, c;
	while (1)
	{
		printf("请输入年份(2000-2030)和月份(1-12) : ");
		scanf_return = scanf("%d%d", &year, &month);
		if (scanf_return != 2 )
		{
			while ((c = getchar()) != '\n' && c != -1)
				;
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (year > 2030 || year < 2000 || month < 1 || month>12)
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		break;
	}
	while (1)
	{
		printf("请输入%d年%d月1日的星期(0-6表示星期日-星期六) : ", year, month);
		scanf_return = scanf("%d", &week);
		if (scanf_return != 1 )
		{
			while ((c = getchar()) != '\n' && c != -1)
				;
			printf("输入非法，请重新输入\n");
			continue;
		}
		if (week < 0 || week>6)
		{
			printf("输入非法，请重新输入\n");
			continue;
		}
		break;
	}
	//打印月历
	printf("\n%d年%d月的月历为:\n", year, month);
	printf("星期日  星期一  星期二  星期三  星期四  星期五  星期六\n");
	int day_limit = 28, leap_year = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 100 == 0 && year % 400 == 0))
	{
		leap_year = 1;
	}

	switch (month)
	{
		case 1:
			day_limit = 31;
			break;
		case 2:
			day_limit = 28 + leap_year;
			break;
		case 3:
			day_limit = 31;
			break;
		case 4:
			day_limit = 30;
			break;
		case 5:
			day_limit = 31;
			break;
		case 6:
			day_limit = 30;
			break;
		case 7:
			day_limit = 31;
			break;
		case 8:
			day_limit = 31;
			break;
		case 9:
			day_limit = 30;
			break;
		case 10:
			day_limit = 31;
			break;
		case 11:
			day_limit = 30;
			break;
		case 12:
			day_limit = 31;
			break;

	}
	for (int i = 1 - week, j = 0; i <= day_limit; i++, j++, j %= 7)
	{
		printf("  ");
		if (i <= 0)
		{
			printf("  ");
		}
		else if (i < 10)
		{
			printf(" ");
			printf("%d", i);
		}
		else
		{
			printf("%d", i);
		}
		
		printf("    ");
		//按照Demo输出规则，在星期六输出结束后换行，而非在星期天输出之前换行
		if (j == 6)
		{
			printf("\n");
		}
	}
	//行末换行
	printf("\n");
	return 0;
}