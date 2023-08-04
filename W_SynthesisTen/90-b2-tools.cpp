#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;
/***************************************************************************
  函数名称：game_tool_finish_check
  功    能：游戏结束判定
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
  返 回 值：是否结束
  说    明：
***************************************************************************/
int game_tool_finish_check(int mat[][GAME_INPUT_COL_MAX], int r, int c)
{
	int valid = 0;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			valid += (game_tool_check_adjacent(mat, r, c, i, j) != 0);
		}
	}
	return valid == 0;
}
/***************************************************************************
  函数名称：game_tool_combine
  功    能：标记块合成
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int srow 矩阵行数
			int scol 矩阵列数
			int irow 选中行
			int icol 选中列
  返 回 值：单次得分
  说    明：
***************************************************************************/
int game_tool_combine(int mat[][GAME_INPUT_COL_MAX], int srow, int scol, int irow, int icol)
{
	int ans = 0;
	for (int i = 0; i < srow; i++)
	{
		for (int j = 0; j < scol; j++)
		{
			if (mat[i][j] > FLAGGED && (i != irow || j != icol))
			{
				if (ans == 0)
					ans += mat[i][j] % FLAGGED;
				ans += mat[i][j] % FLAGGED;
				mat[i][j] = FLAGGED;
			}
		}
	}
	mat[irow][icol]++;
	return ans * GAME_CELLWEIGHT;
}
/***************************************************************************
  函数名称：game_tool_check_adjacent
  功    能：检查周围是否有相同块
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
			int cr 选中行
			int cc 选中列
  返 回 值：周围是否有相同块
  说    明：
***************************************************************************/
int game_tool_check_adjacent(int mat[][GAME_INPUT_COL_MAX], int r, int c, int cr, int cc)
{
	int valid = 0;
	if (cc - 1 >= 0 && mat[cr][cc - 1] % FLAGGED == mat[cr][cc] % FLAGGED)
		valid++;
	if (cr - 1 >= 0 && mat[cr - 1][cc] % FLAGGED == mat[cr][cc] % FLAGGED)
		valid++;
	if (cc + 1 < c && mat[cr][cc + 1] % FLAGGED == mat[cr][cc] % FLAGGED)
		valid++;
	if (cr + 1 < r && mat[cr + 1][cc] % FLAGGED == mat[cr][cc] % FLAGGED)
		valid++;
	return valid;

}
/***************************************************************************
  函数名称：game_tool_find_iterative
  功    能：迭代查找和标记
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int srow 矩阵行数
			int irow 选中行
			int icol 选中列
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_find_iterative(int mat[][GAME_INPUT_COL_MAX], int srow, int irow, int icol)
{
	int stackx[1000], stacky[1000];
	int cur = 0;
	stackx[cur] = irow;
	stacky[cur++] = icol;
	//Stack-based DFS
	while (cur)
	{
		int cx = stackx[cur - 1], cy = stacky[--cur];
		mat[cx][cy] = (mat[cx][cy] % FLAGGED) + FLAGGED;
		if (cx - 1 >= 0 && mat[cx - 1][cy] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx - 1][cy] < FLAGGED)
		{
			stackx[cur] = cx - 1;
			stacky[cur++] = cy;
		}
		if (cy - 1 >= 0 && mat[cx][cy - 1] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx][cy - 1] < FLAGGED)
		{
			stackx[cur] = cx;
			stacky[cur++] = cy - 1;
		}
		if (cx + 1 < srow && mat[cx + 1][cy] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx + 1][cy] < FLAGGED)
		{
			stackx[cur] = cx + 1;
			stacky[cur++] = cy;
		}
		if (cy + 1 >= 0 && mat[cx][cy + 1] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx][cy + 1] < FLAGGED)
		{
			stackx[cur] = cx;
			stacky[cur++] = cy + 1;
		}
	}
}
/***************************************************************************
  函数名称：game_tool_remove_flag
  功    能：清空标记
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int srow 矩阵行数
			int scol 矩阵列数
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_remove_flag(int mat[][GAME_INPUT_COL_MAX], int srow, int scol)
{
	for (int i = 0; i < srow; i++)
	{
		for (int j = 0; j < scol; j++)
			mat[i][j] %= FLAGGED;
	}
}
/***************************************************************************
  函数名称：game_tool_getch
  功    能：_getch（处理0xE0）
  输入参数：	
  返 回 值：_getch 返回值
  说    明：
***************************************************************************/
int game_tool_getch()
{
	int ch = 0;
	while (1)
	{
		ch = _getch();
		if (ch == 0xE0 || ch == 0x00)
		{
			ch = _getch();
			continue;
		}
		break;
	}
	return ch;
}
/***************************************************************************
  函数名称：game_tool_wait_continue
  功    能：等待继续
  输入参数：const char* t 提示文字
			int key 按下何键继续
			int skip 是否跳过
			int clr 是否清空该行
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_wait_continue(const char* t, int key, int skip, int clr,int req_endl)
{
	int cx = 0, cy = 0;
	if (clr)
	{
		cct_getxy(cx, cy);
		for (int i = 0; i < CONSOLE_W; i++)
			cout << " ";
		cct_gotoxy(0, cy);
	}
	cout << t;
	if (skip)
		return;
	while (1)
	{
		if (static_cast<int>(game_tool_uprchr(static_cast<char>(game_tool_getch()))) == key)
			break;
	}
	if(req_endl)
		cout << endl;
}
/***************************************************************************
  函数名称：game_tool_swap
  功    能：交换两数
  输入参数：int* x 用于交换的值
			int *y 用于交换的值
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_swap(int* x, int* y)
{
	int t = *x;
	*x = *y;
	*y = t;
}
/***************************************************************************
  函数名称：game_tool_uprchr
  功    能：转为大写/等效于toupper
  输入参数：char x 要转换的字符
  返 回 值：转换后的字符
  说    明：
***************************************************************************/
char game_tool_uprchr(char x)
{
	return (x >= 'a' && x <= 'z') ? x - 'a' + 'A' : x;
}
/***************************************************************************
  函数名称：game_tool_strlen
  功    能：转为大写/等效于strlen
  输入参数：const char* x 要计算的字符串
  返 回 值：字符串长度
  说    明：
***************************************************************************/
int game_tool_strlen(const char* s)
{
	if (s == NULL)
		return 0;
	int x = 0;
	while (*s++)
		x++;
	return x;
}
/***************************************************************************
  函数名称：game_tool_getmax
  功    能：获取矩阵最大值
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
  返 回 值：矩阵中的最大值
  说    明：
***************************************************************************/
int game_tool_getmax(int mat[][GAME_INPUT_COL_MAX], int r, int c)
{
	int ans = -0x7fffffff;
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
			ans = (mat[i][j] % FLAGGED > ans) ? mat[i][j] % FLAGGED : ans;
	}
	return ans;
}
/***************************************************************************
  函数名称：game_tool_rand_gen
  功    能：根据矩阵中的最大值生成一个随机数
  输入参数：int maxval 最大值
  返 回 值：生成的随机数
  说    明：
***************************************************************************/
int game_tool_rand_gen(int maxval)
{
	if (maxval <= 3)
		return rand() % 3 + 1;
	if (maxval == 4)
	{
		int x = rand() % 10 + 1;
		if (x <= 9)
			return rand() % 3 + 1;
		return 4;
	}
	if (maxval == 5)
	{
		int x = rand() % 100 + 1;
		if (x <= 75)
			return rand() % 3 + 1;
		if (x <= 90)
			return 4;
		return 5;
	}
	if (maxval == 6)
	{
		int x = rand() % 100 + 1;
		if (x <= 80)
			return rand() % 4 + 1;
		if (x <= 95)
			return 5;
		return 6;
	}
	if (maxval > 6)
	{
		int x = rand() % 100 + 1;
		if (x <= 80)
			return rand() % (maxval - 3) + 1;
		if (x <= 90)
			return maxval - 2;
		if (x <= 95)
			return maxval - 1;
		return maxval;
	}
	return 0;
}
/***************************************************************************
  函数名称：game_tool_fill_tiles
  功    能：填充矩阵
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
			int isConsole 是否是图形版
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_fill_tiles(int mat[][GAME_INPUT_COL_MAX], int r, int c, int isConsole)
{
	int maxval = game_tool_getmax(mat, r, c);
	for (int j = 0; j < c; j++)
	{
		for (int i = r - 1; i >= 0; i--)
		{
			int cx = 2 + j * (GAME_CON_CW + 1) * 2;
			int cy = 2 + i * (GAME_CON_CH + 1);
			if (isConsole)
				mat[i][j] %= FLAGGED;
			if (mat[i][j] % FLAGGED == 0)
			{
				mat[i][j] = game_tool_rand_gen(maxval) + (!isConsole) * FLAGGED;
				if (isConsole)
				{
					game_con_draw_tile(mat[i][j], cx, cy);
					Sleep(GAME_CON_FILL_DELAY);
				}
			}
		}
	}
}
/***************************************************************************
  函数名称：game_tool_drop_tile
  功    能：下落单个数块
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int cc 选中列
			int cr 选中行
			int isConsole 是否是图形版
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_drop_tile(int mat[][GAME_INPUT_COL_MAX], int r, int cr, int cc, int isConsole)
{
	if (!isConsole)
	{
		if (mat[cr][cc] % FLAGGED)
			mat[cr][cc] %= FLAGGED;
	}
	int pr = r - 1;
	for (; pr > cr; pr--)
	{
		if (mat[pr][cc] % FLAGGED == 0)
			break;
	}
	if (isConsole)
	{
		int ybegin = 2 + cr * (GAME_CON_CH + 1), yend = 2 + pr * (GAME_CON_CH + 1);
		int x = 2 + cc * (GAME_CON_CW + 1) * 2;
		for (int i = ybegin; i < yend; i++)
		{
			cct_gotoxy(x, i);
			cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
			for (int j = 0; j < GAME_CON_CW; j++)
				cout << ((i - 2) % (GAME_CON_CH + 1) == GAME_CON_CH ? "─" : "  ");
			cct_gotoxy(x, i + 1);
			game_con_draw_tile(mat[cr][cc], x, i + 1, OPT_SEL_DEFAULT);
			Sleep(GAME_CON_DROP_DELAY);
		}
	}
	game_tool_swap(&mat[cr][cc], &mat[pr][cc]);
	
}
/***************************************************************************
  函数名称：game_tool_drop_tiles
  功    能：下落所有数块
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
			int isConsole 是否是图形版
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_drop_tiles(int mat[][GAME_INPUT_COL_MAX], int r, int c, int isConsole)
{
	for (int j = 0; j < c; j++)
	{
		for (int i = r - 1; i >= 0; i--)
		{
			if (mat[i][j] % FLAGGED)
				game_tool_drop_tile(mat, r, i, j, isConsole);
		}
	}

}
/***************************************************************************
  函数名称：game_tool_input_end
  功    能：处理输入结束
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_input_end()
{
	cct_setcursor(CURSOR_VISIBLE_NORMAL);
	int rx = 0, ry = 0;
	char inputs[1000];
	const char* tips = "本小题结束，请输入End继续...";
	while (1)
	{
		cout << tips;
		cct_getxy(rx, ry);
		for (int i = GAME_INPUT_ROW_CLR-game_tool_strlen(tips); i; i--)
			cout << " ";
		cct_gotoxy(rx, ry);
		//cin >> inputs;
		cin.getline(inputs, 999);
		if (cin.fail() || game_tool_strlen(inputs) < 3)
		{
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(0, ry);
			continue;
		}
		if (game_tool_uprchr(inputs[0]) != 'E' || game_tool_uprchr(inputs[1]) != 'N' || game_tool_uprchr(inputs[2]) != 'D')
		{
			cout << "输入错误，请重新输入" << endl;
			cct_gotoxy(0, ry);
			continue;
		}
		break;
	}
}
/***************************************************************************
  函数名称：game_tool_initial_gen
  功    能：生成初盘
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_initial_gen(int mat[][GAME_INPUT_COL_MAX], int r, int c)
{
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			mat[i][j] = game_tool_rand_gen(0);
}
/***************************************************************************
  函数名称：game_tool_input_single
  功    能：处理带范围限制的输入
  输入参数：int* ivar 输入的变量指针
			const char* 显示字符串
			int lowlimit 输入下限
			int highlimit 输入上限
			int& rx 用于定位输出X
			int& ry 用于定位输出Y
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_input_single(int* ivar, const char* description, int lowlimit, int highlimit, int& rx, int& ry)
{
	cct_getxy(rx, ry);
	while (1)
	{
		cct_gotoxy(0, ry);
		for (int i = GAME_INPUT_ROW_CLR; i; i--)
			cout << " ";
		cct_gotoxy(0, ry);
		cout << description << "(" << lowlimit << "-";
		cout << highlimit << ")： ";
		bool flag = cin.fail();
		cin >> *ivar;
		cin.clear();
		cin.ignore(GAME_INPUT_CIN_IGNORE, '\n');
		if (flag || *ivar<lowlimit || *ivar>highlimit)
		{
			cct_gotoxy(0, ry+1);
			cout << "输入不合法，请重新输入";
			continue;
		}
		break;
	}
}
/***************************************************************************
  函数名称：game_tool_input
  功    能：处理公共输入
  输入参数：int* irow 矩阵行数
			int* icol 矩阵列数
			int* igoal 游戏目标
  返 回 值：
  说    明：
***************************************************************************/
void game_tool_input(int* irow, int* icol, int* igoal)
{
	cct_cls();
	int rx = 0, ry = 0;
	if (irow != NULL)
		game_tool_input_single(irow, "请输入行数", GAME_INPUT_ROW_MIN, GAME_INPUT_ROW_MAX, rx, ry);
	if (icol != NULL)
		game_tool_input_single(icol, "请输入列数", GAME_INPUT_COL_MIN, GAME_INPUT_COL_MAX, rx, ry);
	if (igoal != NULL)
		game_tool_input_single(igoal, "请输入合成目标", GAME_INPUT_GOAL_MIN, GAME_INPUT_GOAL_MAX, rx, ry);
}