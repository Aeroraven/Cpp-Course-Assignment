#include<iostream>
#include<cstdio>
#include<iomanip>
#include<conio.h>
#include <ctime>
#include <cstdlib>
#include "cmd_console_tools.h"

#include "90-b2.h"
using namespace std;
/***************************************************************************
  函数名称：int game_menu_print()
  功    能：打印菜单
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
int game_menu_print()
{
	const char* menuOpts[GAME_MENU_OPTS][2] = 
	{
		{"命令行找出可合成项并标识（非递归）","1"},
		{"命令行找出可合成项并标识（递归）","2"},
		{"命令行完成一次合成（分步骤显示）","3"},
		{"命令行完整版（分步骤显示）","4"},
		{"伪图形界面显示初始数组（无分隔线）","5"},
		{"伪图形界面显示初始数组（有分隔线）","6"},
		{"伪图形界面下用箭头键选择当前色块","7"},
		{"伪图形界面完成一次合成（分步骤）","8"},
		{"伪图形界面完整版","9"},
		{"退出","0"},
	};
	cct_cls();
	cout << "-----------------------------------" << endl;
	for (int i = 0; i < GAME_MENU_OPTS; i++)
		cout << menuOpts[i][1] << "." << menuOpts[i][0] << endl;
	cout << "----------------------------------- " << endl;
	int ch = 0;
	cout << "[请选择0-9]";
	while (1)
	{
		ch = _getch();
		if (ch >= '0' && ch <= '9')
			break;
		if (ch == 0xE0 || ch == 0x00)
			ch = _getch();
	}
	cout << static_cast<char>(ch);
	return ch - '0';
}

int main()
{
	srand(static_cast<unsigned int>(time(0)));
	int old_wincol, old_winrow, old_bufcol, old_bufrow;
	cct_setcolor();
	cct_getconsoleborder(old_wincol, old_winrow, old_bufcol, old_bufrow);
	int option = 0;
	while (1)
	{
		cct_setcursor(CURSOR_VISIBLE_NORMAL);
		cct_setconsoleborder(80, 25, -1, old_bufrow);
		option = game_menu_print();
		if (!option)
			break;
		switch (option)
		{
			case 1:
				game_base_options(OPT_ITERATIVE);
				break;
			case 2:
				game_base_options(OPT_RECURSIVE);
				break;
			case 3:
				game_base_options(OPT_FIRST_OP);
				break;
			case 4:
				game_base_options(OPT_COMPLETE);
				break;
			case 5:
				game_con_options(OPT_CON_DRAW1);
				break;
			case 6:
				game_con_options(OPT_CON_DRAW2);
				break;
			case 7:
				game_con_options(OPT_CON_FIRST);
				break;
			case 8:
				game_con_options(OPT_CON_SINGLE);
				break;
			case 9:
				game_con_options(OPT_CON_FULL);
				break;
		}
	}
	cct_gotoxy(0, 23);
	cout << "请按任意键继续. . .";
	game_tool_getch();
	return 0;
}