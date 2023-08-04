#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* ----具体要求----
   1、不允许添加其它头文件
   2、允许定义一个全局变量、不允许定义静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */
int cnt = 0;

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
	if (n > 1)
	{
		hanoi(n - 1, src, dst, tmp);
	}
	//move (src->dst);
	printf("%5d:%3d# %c-->%c\n", ++cnt, n, src, dst);
	if (n > 1)
	{
		hanoi(n - 1, tmp, src, dst);
	}
	return;
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
	int a_used = 0, b_used = 0, c_used = 0;
	int cinflag;
	int scanfret = 0, c;
	while (1) {
		printf("请输入汉诺塔的层数(1-16)\n");
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
		if (cinflag || levels <= 0 || levels > 16)
		{
			continue;
		}
		break;
	}
	while (1) {
		printf("请输入起始柱(A-C)\n");
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
	while (1) {
		printf("请输入目标柱(A-C)\n");
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
	printf("移动步骤为:\n");
	hanoi(levels, start, tmp, dest);
	return 0;
}
