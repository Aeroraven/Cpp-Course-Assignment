#include<iostream>
#include <iomanip>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;

/***************************************************************************
  函数名称：game_base_find_recursive
  功    能：命令行版矩阵打印
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
			int type 输出方式
  返 回 值：
  说    明：
***************************************************************************/
void game_base_print_mat(int mat[][GAME_INPUT_COL_MAX], int r, int c, int type = GAME_BASE_PRINT_DFFAULT)
{
	cout << "  | ";
	for (int i = 0; i < c; i++)
		cout << setw(2) << i << " ";
	cout << endl;
	cout << "--+-";
	for (int i = 0; i < c; i++)
		cout << "---";
	cout << endl;
	for (int i = 0; i < r; i++)
	{
		cout << static_cast<char>('A' + i);
		cout << " | ";
		for (int j = 0; j < c; j++)
		{
			if (type == GAME_BASE_PRINT_DFFAULT)
			{
				cout << setw(2) << mat[i][j] % FLAGGED << " ";
			}
			else if (type == GAME_BASE_PRINT_FIND_RESULT)
			{
				if (mat[i][j] >= FLAGGED)
					cout << setw(2) << "*" << " ";
				else
					cout << setw(2) << "0" << " ";
			}
			else if (type == GAME_BASE_PRINT_COLORED_RESULT)
			{
				if (mat[i][j] >= FLAGGED)
					cct_setcolor(0, COLOR_HYELLOW);
				else
					cct_setcolor(0, COLOR_HWHITE);
				cout << setw(2) << mat[i][j] % FLAGGED << " ";
			}
		}
		cct_setcolor(0, COLOR_HWHITE);
		cout << endl;
	}
}

/***************************************************************************
  函数名称：game_base_find_recursive
  功    能：命令行版——递归标记
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int irow 选中矩阵行数
			int icol 选中矩阵列数
			int srow 矩阵行数
			int scol 矩阵列数
  返 回 值：
  说    明：
***************************************************************************/
void game_base_find_recursive(int mat[][GAME_INPUT_COL_MAX], int srow, int scol, int irow, int icol)
{
	//Recursive DFS
	int cx = irow, cy = icol;
	mat[cx][cy] = (mat[cx][cy] % FLAGGED) + FLAGGED;
	if (cx - 1 >= 0 && mat[cx - 1][cy] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx - 1][cy] < FLAGGED)
		game_base_find_recursive(mat, srow, scol, cx - 1, cy);
	if (cy - 1 >= 0 && mat[cx][cy - 1] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx][cy - 1] < FLAGGED)
		game_base_find_recursive(mat, srow, scol, cx, cy - 1);
	if (cx + 1 < srow && mat[cx + 1][cy] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx + 1][cy] < FLAGGED)
		game_base_find_recursive(mat, srow, scol, cx + 1, cy);
	if (cy + 1 >= 0 && mat[cx][cy + 1] % FLAGGED == mat[cx][cy] % FLAGGED && mat[cx][cy + 1] < FLAGGED)
		game_base_find_recursive(mat, srow, scol, cx, cy + 1);
}

/***************************************************************************
  函数名称：game_base_coord_input
  功    能：命令行版选择格子的输入
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int* irow 选中矩阵行数
			int* icol 选中矩阵列数
			int srow 矩阵行数
			int scol 矩阵列数
  返 回 值：
  说    明：
***************************************************************************/
void game_base_coord_input(int mat[][GAME_INPUT_COL_MAX], int* irow, int* icol, int srow, int scol)
{
	int rety = 0, retx = 0, rflag = 1;
	char base_input[1000];
	if (irow == NULL || icol == NULL)
		return;
	while (1)
	{
		if (!rflag)
		{
			cct_gotoxy(0, rety);
			for (int i = GAME_INPUT_ROW_CLR; i; i--)
				cout << " ";
			cct_gotoxy(0, rety);
		}
		rflag = 0;
		cct_getxy(retx, rety);
		cout << "请以字母+数字形式[例：c2]输入矩阵坐标：";
		bool flag = cin.fail();
		cin >> base_input;
		cin.clear();
		cin.ignore(GAME_INPUT_CIN_IGNORE, '\n');

		if (flag || game_tool_strlen(base_input) < 2)
		{
			cout << "输入错误，请重新输入.";
			continue;
		}
		base_input[0] = game_tool_uprchr(base_input[0]);
		if (base_input[0] < 'A' || base_input[0] >= 'A' + srow || base_input[1] < '0' || base_input[1] >= '0' + scol)
		{
			cout << "输入错误，请重新输入.";
			continue;
		}
		cout << "输入为" << base_input[0] << "行" << base_input[1] << "列" << endl;
		if (!game_tool_check_adjacent(mat, srow, scol, base_input[0] - 'A', base_input[1] - '0'))
		{
			cout << "输入的矩阵坐标位置处无连续相同值，请重新输入" << endl;
			rflag = 1;
			continue;
		}
		break;
	}
	*irow = base_input[0] - 'A';
	*icol = base_input[1] - '0';
}
/***************************************************************************
  函数名称：game_base_finish_check
  功    能：命令行版游戏结束判定（提示输出）
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
  返 回 值：1-游戏结束 0-游戏继续
  说    明：
***************************************************************************/
int game_base_finish_check(int mat[][GAME_INPUT_COL_MAX], int r, int c)
{
	int flag = game_tool_finish_check(mat, r, c);
	if (flag)
	{
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		cout << "无可合并的项，游戏结束!" << endl;
		cct_setcolor();
		return 1;
	}
	return 0;
}
/***************************************************************************
  函数名称：game_base_ascension
  功    能：命令行版游戏目标提升（提示输出）
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 矩阵行数
			int c 矩阵列数
			int* goal 游戏目标
  返 回 值：
  说    明：
***************************************************************************/
void game_base_ascension(int mat[][GAME_INPUT_COL_MAX], int r, int c, int* goal)
{
	int maxval = game_tool_getmax(mat, r, c);
	if (maxval >= *goal)
	{
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
		cout << "已经合成到" << maxval << endl;
		cct_setcolor();
		game_tool_wait_continue("按回车键继续向更高目标进发...");
		(*goal)++;
	}

}
/***************************************************************************
  函数名称：game_base_options_action
  功    能：命令行版完成一次合成
  输入参数：	int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int row 矩阵行数
			int col 矩阵列数
			int irow 当前选中行
			int icol 当前选中列
			int& score 游戏分数
			int& goal 游戏目标
  返 回 值：
  说    明：
***************************************************************************/
void game_base_options_action(int opt,int mat[][GAME_INPUT_COL_MAX], int row, int col, int irow, int icol, int& score, int& goal)
{
	int tmp;
	cout << endl << "相同值归并后的数组(不同色标识)：" << endl;
	score += (tmp = game_tool_combine(mat, row, col, irow, icol));
	game_base_print_mat(mat, row, col, GAME_BASE_PRINT_COLORED_RESULT);
	cout << endl << "本次得分：" << tmp << " 总得分：" << score << " 合成目标：" << goal << endl;
	cout << endl;
	game_tool_wait_continue("按回车键进行数组下落除0操作...");
	cout << "除0后的数组(不同色标识)：" << endl;
	game_tool_drop_tiles(mat, row, col, 0);
	game_base_print_mat(mat, row, col, GAME_BASE_PRINT_COLORED_RESULT);
	cout << endl;
	game_tool_wait_continue("按回车键进行新值填充...");
	cout << "新值填充后的数组(不同色标识)：" << endl;
	game_tool_fill_tiles(mat, row, col,0);
	game_base_print_mat(mat, row, col, GAME_BASE_PRINT_COLORED_RESULT);
	if (opt == OPT_COMPLETE)
	{
		cout << endl << "本次合成结束，按回车键继续新一次的合成..." << endl;
		game_tool_wait_continue("", 13, 0, 1, 0);
	}
}
/***************************************************************************
  函数名称：game_base_option_print_mat
  功    能：命令行版打印矩阵
  输入参数：int opt 选项号
			int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int& row 矩阵行数
			int& col 矩阵列数
			int& irow 当前选中行
			int& icol 当前选中列
  返 回 值：0 - opt为 OPT_RECURSIVE 或 OPT_ITERATIVE 其他为1
  说    明：
***************************************************************************/
int game_base_option_print_mat(int opt, int mat[][GAME_INPUT_COL_MAX], int& row, int& col, int& irow, int& icol)
{
	cout << endl << "当前数组：" << endl;
	game_base_print_mat(mat, row, col);
	cout << endl;
	if (game_base_finish_check(mat, row, col))
		return 0;
	game_base_coord_input(mat, &irow, &icol, row, col);
	cout << endl << "查找结果数组：" << endl;
	if (opt != OPT_RECURSIVE)
		game_tool_find_iterative(mat, row, irow, icol);
	else if (opt == OPT_RECURSIVE)
		game_base_find_recursive(mat, row, col, irow, icol);
	game_base_print_mat(mat, row, col, GAME_BASE_PRINT_FIND_RESULT);
	cout << endl << endl << "当前数组(不同色标识)：" << endl;
	game_base_print_mat(mat, row, col, GAME_BASE_PRINT_COLORED_RESULT);

	if (opt == OPT_RECURSIVE || opt == OPT_ITERATIVE)
		return 0;
	return 1;
}
/***************************************************************************
  函数名称：game_base_options
  功    能：控制台版主逻辑
  输入参数：int opt 选项号
  返 回 值：
  说    明：
***************************************************************************/
void game_base_options(int opt)
{
	int row, col, irow, icol, score = 0, rx = 0, ry = 0, cht = 0, mat[GAME_INPUT_ROW_MAX][GAME_INPUT_COL_MAX];
	int goal = 990;
	game_tool_input(&row, &col, (opt == OPT_COMPLETE || opt==OPT_FIRST_OP ? &goal : NULL));
	game_tool_initial_gen(mat, row, col);
	while (1)
	{
		game_base_ascension(mat, row, col, &goal);
		game_tool_remove_flag(mat, row, col);

		if (!game_base_option_print_mat(opt, mat, row, col, irow, icol))
			break;

		if (opt == OPT_FIRST_OP || opt == OPT_COMPLETE)
		{
			cout << endl << "请确认是否把相邻的相同值合并到" << static_cast<char>(irow + 'A') << icol << "中(Y/N/Q)";
			cct_getxy(rx, ry);
			while (1)
			{
				cht = game_tool_uprchr(static_cast<char>(game_tool_getch()));
				if (cht != 'Y' && cht != 'N' && cht != 'Q')
					continue;
				break;
			}
			cout << static_cast<char>(cht) << endl;
			if (cht == 'Y')
				game_base_options_action(opt, mat, row, col, irow, icol, score, goal);
			if (opt != OPT_COMPLETE || cht == 'Q')
				break;
			if (cht == 'N')
				continue;
		}
	}
	cout << endl;
	game_tool_input_end();
}