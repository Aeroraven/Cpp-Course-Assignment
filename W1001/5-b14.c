/* 已验证 xxx 的扫雷内部数组 */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 26
#define MINE_COUNTS 50
#define STR_TMP_LEN 5000

int main()
{
	char s[STR_TMP_LEN];
	char board[BOARD_HEIGHT+2][BOARD_WIDTH + 2];
	char tmp;
	for (int i = 1; i <= BOARD_HEIGHT; i++)
	{
		for (int j = 1; j <= BOARD_WIDTH; j++)
		{
			int x = scanf("%s", &s);
			board[i][j] = s[0];
			x++; 
		}
	}
	//检验错误1
	int mine_cnt = 0;
	for (int i = 1; i <= BOARD_HEIGHT; i++)
	{
		for (int j = 1; j <= BOARD_WIDTH; j++)
		{
			if (board[i][j] == '*')
			{
				mine_cnt++;
			}
		}
	}
	if (mine_cnt != MINE_COUNTS)
	{
		printf("错误1\n");
		return 0;
	}
	//检验错误2
	for (int i = 1; i <= BOARD_HEIGHT; i++)
	{
		for (int j = 1; j <= BOARD_WIDTH; j++)
		{
			int cnt = 0;
			for (int k = i - 1; k <= i + 1; k++)
			{
				for (int m = j - 1; m <= j + 1; m++)
				{
					if (board[k][m] == '*')
					{
						cnt++;
					}
				}
			}
			if (cnt+'0' != board[i][j] && board[i][j]!='*')
			{
				printf("错误2\n");
				return 0;
			}
		}
	}
	//正确
	printf("正确\n");
	return 0;
}