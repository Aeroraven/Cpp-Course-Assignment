#include <iostream>
#include <cmath>
#include <cstdio>
#include <ctime>
using namespace std;

int main()
{
	srand(static_cast<unsigned int>(time(0)));//!!!!!!
	
	const int BOARD_HEIGHT = 10;
	const int BOARD_WIDTH = 26;
	const int MINE_COUNTS = 50;

	char board[BOARD_HEIGHT + 2][BOARD_WIDTH + 2];
	//初始化
	for (int i = 0; i < BOARD_HEIGHT + 2; i++)
	{
		for (int j = 0; j < BOARD_WIDTH + 2; j++)
		{
			board[i][j] = '0';
		}
	}
	//生成雷
	int mines_generated = MINE_COUNTS;
	while (mines_generated)
	{
		int mX, mY;
		mX = rand() % BOARD_HEIGHT + 1;
		mY = rand() % BOARD_WIDTH + 1;
		if (board[mX][mY] == '*')
		{
			continue;
		}
		else
		{
			mines_generated--;
			board[mX][mY] = '*';
		}
	}
	//计算雷数
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
			if (board[i][j] != '*')
			{
				board[i][j] = '0' + cnt;
			}
			cout << board[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
