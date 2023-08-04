#include<iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
#include "90-b2.h"
#include "cmd_console_tools.h"
using namespace std;
/***************************************************************************
  函数名称：game_con_arrow_key
  功    能：读取方向键和Enter
  输入参数：	
  返 回 值： 按下键的键值对应编号（90-b2.h）
  说    明：
***************************************************************************/
int game_con_arrow_key()
{
	int ch;
	while (1)
	{
		ch = _getch();
		if (ch == 13)
			return GAME_CON_ENTER;
		if (ch == 0xE0 || ch == 0x00)
		{
			ch = _getch();
			if (ch == 75)
				return GAME_CON_LEFT;
			if (ch == 77)
				return GAME_CON_RIGHT;
			if (ch == 72)
				return GAME_CON_UP;
			if (ch == 80)
				return GAME_CON_DOWN;
		}
	}
}
/***************************************************************************
  函数名称：game_con_set_topbar
  功    能：显示得分栏
  输入参数：int totalpt 总得分
			int roundpt 回合得分
			int cells 合成目标
  返 回 值： 
  说    明：
***************************************************************************/
void game_con_set_topbar(int totalpt, int roundpt, int cells)
{
	int w = 0, h = 0, bw = 0, bh = 0;
	cct_setcolor();
	cct_gotoxy(0, 0);
	cct_getconsoleborder(w, h, bw, bh);
	for (int i = 0; i < w; i++)
		cout << " ";
	cct_gotoxy(0, 0);
	cout << "本次得分:" << roundpt << " 总分:" << totalpt << " 合成目标:" << cells;
}
/***************************************************************************
  函数名称：game_con_set_statusbar
  功    能：显示状态栏文字
  输入参数：const char* tip 提示文字
			int pos 状态栏Y坐标
			int prkey 按下键后继续
			int mode 输出模式
			int fgcolor 前景色
			int pos_reset 是否重置X坐标
  返 回 值：mode为1时返回game_con_arrow_key的值
  说    明：
***************************************************************************/
int game_con_set_statusbar(const char* tip, int pos, int prkey = 13, int mode = 0, int fgcolor = COLOR_WHITE, int pos_reset = true)
{
	if (mode == -1)
	{
		Sleep(GAME_DELAY);
		return 0;
	}
	cct_setcolor(0, fgcolor);
	if (pos_reset)
		cct_gotoxy(0, pos);
	game_tool_wait_continue(tip, prkey, mode, pos_reset);
	if (mode == 1)
		return game_con_arrow_key();
	return 0;
}
/***************************************************************************
  函数名称：game_con_draw_tile
  功    能：显示状态栏文字
  输入参数：int val 格子值
			int cx 格子X坐标
			int cy 格子Y坐标
			int type 显示类型
  说    明：
***************************************************************************/
void game_con_draw_tile(int val, int cx, int cy, int type)
{
	const int colors[22] = {
		COLOR_HWHITE,COLOR_HBLACK,COLOR_HPINK,COLOR_WHITE,COLOR_YELLOW, //0~4颜色
		COLOR_PINK,COLOR_HBLUE,COLOR_HCYAN,COLOR_HGREEN,COLOR_HYELLOW, //5~9颜色
		COLOR_HRED,COLOR_GREEN,COLOR_CYAN,COLOR_HGREEN,COLOR_HYELLOW, //10~14颜色
		COLOR_HWHITE,COLOR_HBLACK,COLOR_HPINK,COLOR_WHITE,COLOR_YELLOW,
		COLOR_PINK,COLOR_HBLUE
	};
	if (val % FLAGGED == 0)
		cct_setcolor(COLOR_HWHITE, COLOR_HWHITE);
	else if (type == OPT_SEL_HSELECT)
		cct_setcolor(COLOR_HYELLOW, COLOR_HRED);
	else if (type == OPT_SEL_SELECT)
		cct_setcolor(COLOR_HYELLOW, COLOR_HBLUE);
	else if (val % FLAGGED >= 1)
		cct_setcolor(colors[(val % FLAGGED - 1) % 20 + 1], COLOR_BLACK);
	cct_gotoxy(cx, cy);
	cout << "╔";
	for (int i = 0; i < GAME_CON_CW - 2; i++)
		cout << "═";
	cout << "╗";
	for (int i = 0; i < GAME_CON_CH - 2; i++)
	{
		cct_gotoxy(cx, cy + i + 1);
		cout << "║";
		cout << setw(GAME_CON_CW * 2 - 4);
		cout << (i ? ' ' : val % FLAGGED);
		cout << "║" << endl;
	}
	cct_gotoxy(cx, cy + GAME_CON_CH - 1);
	cout << "╚";
	for (int i = 0; i < GAME_CON_CW - 2; i++)
		cout << "═";
	cout << "╝";
}


/***************************************************************************
  函数名称：game_con_shine_tile
  功    能：闪烁格子
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int cr 选中行
			int cc 选中列
  说    明：
***************************************************************************/
void game_con_shine_tile(int mat[][GAME_INPUT_COL_MAX], int cr, int cc)
{
	for (int T = GAME_CON_BLINK_CNT; T >= 0; T--)
	{
		int cx = 2 + cc * (GAME_CON_CW + 1) * 2, cy = 2 + cr * (GAME_CON_CH + 1);
		game_con_draw_tile(mat[cr][cc], cx, cy, (T % 2 ? OPT_SEL_HSELECT : OPT_SEL_DEFAULT));
		Sleep(GAME_CON_BLINK_DELAY);

	}
}

/***************************************************************************
  函数名称：game_con_draw_tiles
  功    能：绘制所有格子
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 总行数
			int c 纵列数
			int cr 选中行
			int cc 选中列
			int type 绘制模式
  说    明：
***************************************************************************/
void game_con_draw_tiles(int mat[][GAME_INPUT_COL_MAX], int r, int c, int cr = -1, int cc = -1, int type = 0)
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cx = 2 + j * (GAME_CON_CW + 1) * 2;
			int cy = 2 + i * (GAME_CON_CH + 1);
			if (type == OPT_DRW_FADE)
			{
				if (mat[i][j] >= FLAGGED)
					game_con_draw_tile(mat[i][j], cx, cy);
			}
			else
			{
				if (i == cr && j == cc)
					game_con_draw_tile(mat[i][j], cx, cy, OPT_SEL_HSELECT);
				else if (mat[i][j] >= FLAGGED)
					game_con_draw_tile(mat[i][j], cx, cy, OPT_SEL_SELECT);
				else
					game_con_draw_tile(mat[i][j], cx, cy);
			}

		}
	}
}
/***************************************************************************
  函数名称：game_con_delayed_output
  功    能：带延迟输出
  输入参数：const char* str 输出文字
			int delay 输出延迟
  说    明：
***************************************************************************/
void game_con_delayed_output(const char* str, int delay)
{
	cout << str;
	if (delay)
		Sleep(delay);
}
/***************************************************************************
  函数名称：game_con_draw_split
  功    能：带分隔的游戏矩阵绘制
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 总行数
			int c 纵列数
			int* status_bar_y 状态栏y坐标（用于返回）
			bool delay 是否进行绘制延迟
  说    明：
***************************************************************************/
void game_con_draw_split(int mat[][GAME_INPUT_COL_MAX], int r, int c, int* status_bar_y, bool delay = false)
{
	int topw = c * GAME_CON_CW + c - 1, lefth = r * GAME_CON_CH + r - 1;
	int wincol = topw * 2 + 5, winrow = lefth + 7, old_wincol, old_winrow, old_bufcol, old_bufrow;
	cct_getconsoleborder(old_wincol, old_winrow, old_bufcol, old_bufrow);
	cct_setconsoleborder(wincol, winrow, -1, old_bufrow);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);
	//上边框
	cct_gotoxy(0, 1);
	cout << "╔";
	for (int i = 0; i < topw; i++)
		game_con_delayed_output(((i + 1) % (GAME_CON_CW + 1) && (i != GAME_CON_CW) ? "═" : "╤"), GAME_DELAY_BORDER_DRW * delay);
	cout << "╗" << endl;
	//中间边框
	for (int i = 0; i < lefth; i++)
	{
		cout << ((i + 1) % (GAME_CON_CH + 1) && (i != GAME_CON_CH) ? "║" : "╟");
		for (int j = 0; j < topw; j++)
		{
			if ((j + 1) % (GAME_CON_CW + 1) && (j != GAME_CON_CW))
				game_con_delayed_output(((i + 1) % (GAME_CON_CH + 1) && (i != GAME_CON_CH) ? "  " : "─"), delay * GAME_DELAY_BORDER_DRW);
			else
				game_con_delayed_output(((i + 1) % (GAME_CON_CH + 1) && (i != GAME_CON_CH) ? "│" : "┼"), delay * GAME_DELAY_BORDER_DRW);
		}
		cout << ((i + 1) % (GAME_CON_CH + 1) && (i != GAME_CON_CH) ? "║" : "╢") << endl;
	}
	//下边框
	cct_gotoxy(0, 2 + lefth);
	cout << "╚";
	for (int i = 0; i < topw; i++)
		game_con_delayed_output(((i + 1) % (GAME_CON_CW + 1) && (i != GAME_CON_CW) ? "═" : "╧"), delay * GAME_DELAY_BORDER_DRW);
	cout << "╝" << endl;
	//数字块
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cx = 2 + j * (GAME_CON_CW + 1) * 2, cy = 2 + i * (GAME_CON_CH + 1);
			game_con_draw_tile(mat[i][j], cx, cy);
			if (delay)
				Sleep(GAME_DELAY_BORDER_DRW);
		}
	}
	//状态栏
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << winrow << "行" << wincol << "列";
	cct_gotoxy(0, 3 + lefth);
	*status_bar_y = 3 + lefth;
}
/***************************************************************************
  函数名称：game_con_draw_nosplit
  功    能：不带分隔的游戏矩阵绘制
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 总行数
			int c 纵列数
  说    明：
***************************************************************************/
void game_con_draw_nosplit(int mat[][GAME_INPUT_COL_MAX], int r, int c)
{
	int topw = c * GAME_CON_CW, lefth = r * GAME_CON_CH;
	int wincol = topw * 2 + 5, winrow = lefth + 7, old_wincol, old_winrow, old_bufcol, old_bufrow;
	cct_getconsoleborder(old_wincol, old_winrow, old_bufcol, old_bufrow);
	cct_setconsoleborder(wincol, winrow, -1, old_bufrow);
	cct_setcolor(COLOR_HWHITE, COLOR_BLACK);

	//边框
	cct_gotoxy(0, 1);
	cout << "╔";
	for (int i = 0; i < topw; i++)
		game_con_delayed_output("═", GAME_DELAY_BORDER_DRW);
	cout << "╗" << endl;
	for (int i = 0; i < lefth; i++)
	{
		cct_gotoxy(0, 2 + i);
		game_con_delayed_output("║", GAME_DELAY_BORDER_DRW);
		cct_gotoxy(2 + topw * 2, 2 + i);
		game_con_delayed_output("║", GAME_DELAY_BORDER_DRW);
	}
	cct_gotoxy(0, 2 + lefth);
	cout << "╚";
	for (int i = 0; i < topw; i++)
		game_con_delayed_output("═", GAME_DELAY_BORDER_DRW);
	cout << "╝" << endl;
	//数字块
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			int cx = 2 + j * GAME_CON_CW * 2, cy = 2 + i * GAME_CON_CH;
			game_con_draw_tile(mat[i][j], cx, cy);
			Sleep(GAME_DELAY_BORDER_DRW);
		}
	}
	//状态栏
	cct_setcolor();
	cct_gotoxy(0, 0);
	cout << "屏幕当前设置为：" << winrow << "行" << wincol << "列";
	cct_gotoxy(0, 3 + lefth);
	game_tool_input_end();
}
/***************************************************************************
  函数名称：game_con_move_seltile
  功    能：移动当前选中块
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int row 总行数
			int col 纵列数
			int cht 移动选项
			int& ccol 当前选中列
			int& crow 当前选中行
  说    明：
***************************************************************************/
void game_con_move_seltile(int mat[][GAME_INPUT_COL_MAX], int& ccol, int& crow, int row, int col, int cht)
{
	game_con_draw_tile(mat[crow][ccol], 2 + ccol * (GAME_CON_CW + 1) * 2, 2 + crow * (GAME_CON_CH + 1), OPT_SEL_DEFAULT);
	if (cht == GAME_CON_LEFT)
		ccol = (ccol + col - 1) % col;
	else if (cht == GAME_CON_RIGHT)
		ccol = (ccol + col + 1) % col;
	else if (cht == GAME_CON_UP)
		crow = (crow + row - 1) % row;
	else if (cht == GAME_CON_DOWN)
		crow = (crow + row + 1) % row;
	game_con_draw_tile(mat[crow][ccol], 2 + ccol * (GAME_CON_CW + 1) * 2, 2 + crow * (GAME_CON_CH + 1), OPT_SEL_SELECT);
}
/***************************************************************************
  函数名称：game_con_finish_check
  功    能：游戏结束检查
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 总行数
			int c 纵列数
			int bar_y 状态栏行数
  说    明：
***************************************************************************/
int game_con_finish_check(int mat[][GAME_INPUT_COL_MAX], int r, int c, int bar_y)
{
	int gameover = game_tool_finish_check(mat, r, c);
	if (gameover)
	{
		game_con_set_statusbar("无可合并的项，游戏结束!", bar_y, 13, 2, COLOR_HYELLOW);
		game_con_set_statusbar("按Q退出", bar_y, 'Q', 0, 7, 0);
		return 1;
	}
	return 0;
}
/***************************************************************************
  函数名称：game_con_ascension
  功    能：游戏目标提升
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int r 总行数
			int c 纵列数
			int bar_y 状态栏行数
			int* goal 游戏目标
			int score 游戏分数
			int roundpt 回合得分
  说    明：
***************************************************************************/
void game_con_ascension(int mat[][GAME_INPUT_COL_MAX], int r, int c, int* goal, int bar_y, int score, int roundpt)
{
	int maxval = game_tool_getmax(mat, r, c);
	if (maxval >= *goal)
	{
		game_con_set_statusbar("已经合成到", bar_y, 13, 2, COLOR_HYELLOW);
		cout << maxval;
		game_con_set_statusbar("，按回车键继续向更高目标进发", bar_y, 13, 0, 7, 0);
		(*goal)++;
		game_con_set_topbar(score, roundpt, *goal);
	}
}
/***************************************************************************
  函数名称：game_con_options_initialize
  功    能：游戏初始化
  输入参数：int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int& row 总行数
			int& col 总列数
			int& goal 游戏目标
			int crow 初始选中行
			int ccol 初始选中列
			int& bar_y 游戏状态栏
  说    明：
***************************************************************************/
int game_con_options_initialize(int type, int mat[][GAME_INPUT_COL_MAX], int& row, int& col, int& goal, int crow, int ccol, int& bar_y)
{
	game_tool_input(&row, &col, (type == OPT_CON_SINGLE || type == OPT_CON_FULL) ? &goal : NULL);
	game_tool_initial_gen(mat, row, col);
	cct_cls();
	if (type == OPT_CON_DRAW1)
	{
		game_con_draw_nosplit(mat, row, col);
		return 0;
	}
	game_con_draw_split(mat, row, col, &bar_y, type == OPT_CON_DRAW2);
	if (type != OPT_CON_DRAW1 && type != OPT_CON_DRAW2)
		game_con_draw_tile(mat[crow][ccol], 2 + ccol * (GAME_CON_CW + 1) * 2, 2 + crow * (GAME_CON_CH + 1), OPT_SEL_SELECT);
	return 1;
}
/***************************************************************************
  函数名称：game_con_options_action
  功    能：完成一次合成
  输入参数：int type 游戏选项
			int mat[][GAME_INPUT_COL_MAX] 游戏矩阵
			int& row 行数
			int& col 列数
			int& goal 分数
			int& crow 选中行
			int& ccol 选中列
			int& bar_y 状态栏坐标
			int& score 游戏分数
  说    明：
***************************************************************************/
int game_con_options_action(int type, int mat[][GAME_INPUT_COL_MAX], int& row, int& col, int& goal, int crow, int ccol, int& bar_y, int& score)
{
	int roundpt = 0;
	score += (roundpt = game_tool_combine(mat, row, col, crow, ccol));
	game_con_set_topbar(score, roundpt, goal);
	game_con_draw_tiles(mat, row, col, crow, ccol);
	game_con_shine_tile(mat, crow, ccol);
	game_con_set_statusbar("合成完成，回车键下落0", bar_y, 13, -(type == OPT_CON_FULL));
	game_tool_drop_tiles(mat, row, col, 1);
	game_con_set_statusbar("下落0完成，回车键填充新值", bar_y, 13, -(type == OPT_CON_FULL));
	game_tool_fill_tiles(mat, row, col, 1);
	if (type == OPT_CON_FULL)
		game_con_ascension(mat, row, col, &goal, bar_y, score, roundpt);
	game_con_set_statusbar("本次合成结束，按C继续新一次的合成", bar_y, 'C', -(type == OPT_CON_FULL));
	return 1;
}
/***************************************************************************
  函数名称：game_con_options
  功    能：图形版主逻辑
  输入参数：int type 游戏模式
  说    明：
***************************************************************************/
void game_con_options(int type)
{
	cct_setcursor(CURSOR_INVISIBLE);
	int row, col, score = 0, bar_y = 0, mat[GAME_INPUT_ROW_MAX][GAME_INPUT_COL_MAX];
	int crow = 0, ccol = 0, goal = 0, moves = 0;
	if (!game_con_options_initialize(type, mat, row, col, goal, crow, ccol, bar_y))
		return;
	while (type != OPT_CON_DRAW1 && type != OPT_CON_DRAW2)
	{
		
		if (game_con_finish_check(mat, row, col, bar_y + 1))
			break;
		int cht = game_con_set_statusbar("箭头键移动，回车键选择并结束", bar_y, 13, 1);
		while (cht == GAME_CON_ENTER)
		{
			if (!game_tool_check_adjacent(mat, row, col, crow, ccol)&&type!=OPT_CON_FIRST)
			{
				game_con_set_statusbar("周围无相同值", bar_y, 13, 2, COLOR_HYELLOW);
				game_con_set_statusbar("，箭头键移动，回车键选择并结束", bar_y, 13, 2, 7, 0);
				do
				{
					cht = game_con_arrow_key();
				} while (cht == GAME_CON_ENTER);
			}
			if (cht != GAME_CON_ENTER || (cht == GAME_CON_ENTER && type == OPT_CON_FIRST))
				break;
			game_tool_find_iterative(mat, row, crow, ccol);
			game_con_draw_tiles(mat, row, col, crow, ccol);
			cht = game_con_set_statusbar("箭头键移动并取消当前选择，回车键合成", bar_y, 13, 1);
			if (cht != GAME_CON_ENTER)
			{
				game_con_draw_tiles(mat, row, col, crow, ccol, OPT_DRW_FADE);
				game_tool_remove_flag(mat, row, col);
				break;
			}
			game_con_options_action(type, mat, row, col, goal, crow, ccol, bar_y, score);
			crow = ccol = 0;
			moves++;
			break;
		}
		if ((moves && type == OPT_CON_SINGLE) || (type == OPT_CON_FIRST && cht == GAME_CON_ENTER))
			break;
		if (!(cht >= 0 && cht <= 4))
			continue;
		game_con_move_seltile(mat, ccol, crow, row, col, cht);
		
	}
	cct_setcolor();
	cct_gotoxy(0, bar_y);
	game_tool_input_end();
}