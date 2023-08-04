#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */
#define STACK_SIZE 10
#define COL_COUNT 3

int move_counter = 0;
int stack_top[COL_COUNT] = { 0,0,0 };
int stack_body[COL_COUNT][STACK_SIZE];

void result_print(int is_first, int lvl, char src, char dst)
{
	if (is_first)
	{
		printf("初始:               ");
	}
	else
	{
		printf("第%4d 步(%2d): %c-->%c", move_counter, lvl, src, dst);
	}
	printf(" A:");
	for (int i = 0; i <stack_top[0]; i++)
	{
		printf("%2d", stack_body[0][i]);
	}
	for (int i = stack_top[0]; i < 10; i++)
	{
		printf("  ");
	}
	printf(" B:");
	for (int i = 0; i < stack_top[1]; i++)
	{
		printf("%2d", stack_body[1][i]);
	}
	for (int i = stack_top[1]; i < 10; i++)
	{
		printf("  ");
	}
	printf(" C:");
	for (int i = 0; i < stack_top[2]; i++)
	{
		printf("%2d", stack_body[2][i]);
	}
	for (int i = stack_top[2]; i < 10; i++)
	{
		printf("  ");
	}
	printf("\n");
}

/***************************************************************************
  函数名称：
  功    能：打印n层汉诺塔的移动顺序
  输入参数：int n：层数
			char src：起始柱
			char tmp：中间柱
			char dst：目标柱
  返 回 值：
  说    明：1、函数名、形参、返回类型均不准动
			2、本函数不允许出现任何形式的循环
***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	if (n != 1)
	{
		hanoi(n - 1, src, dst, tmp);
	}

	move_counter++;
	int moved = 0;
	moved = stack_body[src - 'A'][--stack_top[src - 'A']];
	stack_body[dst - 'A'][stack_top[dst - 'A']++] = moved;
	result_print(0, n, src, dst);
	if (n != 1)
	{
		hanoi(n - 1, tmp, src, dst);
	}

}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：完成输入(或调用输入函数)、调用递归函数
***************************************************************************/
int main()
{
	int levels = 0;
	char start = 'D', dest = 'D';
	char tmp;
	int cinflag;
	int scanfret = 0, c;
	while (1)
	{
		printf("请输入汉诺塔的层数(1-10)：\n");
		scanfret = scanf("%d", &levels);
		while (1)
		{
			c = getchar();
			if (c == 0 || c == '\n')
			{
				break;
			}
		}
		cinflag = scanfret < 1;
		if (cinflag || levels <= 0 || levels > 10)
		{
			continue;
		}
		break;
	}
	while (1) 
	{
		printf("请输入起始柱(A-C)：\n");
		scanfret = scanf("%c", &start);
		while (1)
		{
			c = getchar();
			if (c == 0 || c == '\n')
			{
				break;
			}
		}
		cinflag = scanfret < 1;
		if (start >= 'a' && start <= 'c')
		{
			start = start - 'a' + 'A';
		}
		if (cinflag || start < 'A' || start>'C')
		{
			continue;
		}
		break;
	}
	for (int i = levels; i >= 1; i--)
	{
		stack_body[start - 'A'][stack_top[start - 'A']++] = i;
	}
	while (1) 
	{
		printf("请输入目标柱(A-C)：\n");
		scanfret = scanf("%c", &dest);
		while (1)
		{
			c = getchar();
			if (c == 0 || c == '\n')
			{
				break;
			}
		}
		cinflag = scanfret < 1;
		if (dest >= 'a' && dest <= 'c')
		{
			dest = dest - 'a' + 'A';
		}
		if (cinflag || dest < 'A' || dest>'C')
		{
			continue;
		}
		if (dest == start)
		{
			printf("目标柱(%c)不能与起始柱(%c)相同\n", dest, start);
			continue;
		}
		break;
	}
	if ((int)(start)+(int)(dest) == (int)('A') + (int)('C'))
	{
		tmp = 'B';
	}
	else if ((int)(start)+(int)(dest) == (int)('B') + (int)('C'))
	{
		tmp = 'A';
	}
	else if ((int)(start)+(int)(dest) == (int)('A') + (int)('B'))
	{
		tmp = 'C';
	}
	//printf("移动步骤为:\n");
	result_print(1, 0, 0, 0);
	hanoi(levels, start, tmp, dest);
	return 0;
}
