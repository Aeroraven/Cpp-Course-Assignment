#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
#include <windows.h>
using namespace std;

const int MAX_X = 69;	//定义*组成的边框的宽度
const int MAX_Y = 17;	//定义*组成的边框的高度

/***************************************************************************
  函数名称：
  功    能：完成与system("cls")一样的功能，但效率高
  输入参数：
  返 回 值：
  说    明：清除整个屏幕缓冲区，不仅仅是可见窗口区域(使用当前颜色)
***************************************************************************/
void cls(const HANDLE hout)
{
	COORD coord = { 0, 0 };
	CONSOLE_SCREEN_BUFFER_INFO binfo; /* to get buffer info */
	DWORD num;

	/* 取当前缓冲区信息 */
	GetConsoleScreenBufferInfo(hout, &binfo);
	/* 填充字符 */
	FillConsoleOutputCharacter(hout, (TCHAR)' ', binfo.dwSize.X * binfo.dwSize.Y, coord, &num);
	/* 填充属性 */
	FillConsoleOutputAttribute(hout, binfo.wAttributes, binfo.dwSize.X * binfo.dwSize.Y, coord, &num);

	/* 光标回到(0,0) */
	SetConsoleCursorPosition(hout, coord);
	return;
}

/***************************************************************************
  函数名称：gotoxy
  功    能：将光标移动到指定位置
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void gotoxy(const HANDLE hout, const int X, const int Y)
{
	COORD coord;
	coord.X = X;
	coord.Y = Y;
	SetConsoleCursorPosition(hout, coord);
}

/***************************************************************************
  函数名称：showch
  功    能：在指定位置处打印一个指定的字符
  输入参数：HANDLE hout ：输出设备句柄
			int X       ：指定位置的x坐标
			int Y       ：指定位置的y坐标
			char ch     ：要打印的字符
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void showch(const HANDLE hout, const int X, const int Y, const char ch)
{
	gotoxy(hout, X, Y);
	putchar(ch);
}

/***************************************************************************
  函数名称：init_border
  功    能：显示初始的边框及随机字符
  输入参数：HANDLE hout：输出设备句柄
  返 回 值：无
  说    明：此函数不准修改
***************************************************************************/
void init_border(const HANDLE hout)
{
	gotoxy(hout, 0, 0);	//光标移回左上角(0,0)
	cout << "***********************************************************************" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "*                                                                     *" << endl;
	cout << "***********************************************************************" << endl;

	/* 随机显示20个大写字母，字母的值、XY坐标都随机显示
	   rand()函数的功能：随机生成一个在 0-32767 之间的整数
	   思考：在什么情况下，下面这个循环执行生成后，你看到的实际字母个数不足20个？ */
	int i;
	for (i = 0; i < 20; i++)
		showch(hout, rand() % MAX_X + 1, rand() % MAX_Y + 1, 'A' + rand() % 26);

	return;
}

/* -- 按需增加的若干函数可以放在此处 --*/
/***************************************************************************
  函数名称：menu
  功    能：显示并选择菜单
  输入参数：无
  返 回 值：选择的菜单项
  说    明：
***************************************************************************/
int menu()
{
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); //取标准输出设备对应的句柄
	int menu_selected_item = 0;
	while (1)
	{
		cls(hout);
		cout << "1.用I、J、K、L键控制上下左右(大小写均可，边界停止)" << endl;
		cout << "2.用I、J、K、L键控制上下左右(大小写均可，边界回绕)" << endl;
		cout << "3.用箭头键控制上下左右，边界停止" << endl;
		cout << "4.用箭头键控制上下左右，边界回绕" << endl;
		cout << "5.用I、J、K、L键控制上下左右(大小写均可，边界停止，按左方向键不移动)" << endl;
		cout << "6.用I、J、K、L键控制上下左右(大小写均可，边界回绕，按左方向键不移动)" << endl;
		cout << "0.退出" << endl;
		cout << "[请选择0-6] ";
		menu_selected_item = _getche();
		if (menu_selected_item < '0' || menu_selected_item>'6')
		{
			continue;
		}
		break;
	}
	return menu_selected_item - '0';
}

/***************************************************************************
  函数名称：move_by_ijkl
  功    能：ijkl控制移动
  输入参数：int cylic_move 是否循环移动
  返 回 值：1
  说    明：
***************************************************************************/
int move_by_ijkl(int cylic_move)
{
	//之前没看到全局的const
	const int max_x = 69;
	const int max_y = 17;
	int cur_x = 35; //当前X坐标
	int cur_y = 9; //当前Y坐标
	int ch = 0; //按键返回值
	int disallow_special_function = 0; //禁止特殊按键
	int special_scancode_flag = 0; //功能按键是否被按下

	/* 初始化工作 */
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE); 
	cls(hout);//清空菜单输入
	init_border(hout);//初始化边框
	gotoxy(hout, cur_x, cur_y); //移动光标到屏幕中心

	/* 主体内容 */
	while (1)
	{
		//重置标记状态
		special_scancode_flag = 0; 
		ch = _getch();

		//处理特殊按键
		while (ch == 0x00 || ch == 0xE0 || ch == 0xF0) 
		{
			special_scancode_flag = disallow_special_function;
			ch = _getch();
		}
		//不允许按下特殊按键时，要求重新输入
		if (special_scancode_flag)
		{
			continue;
		}

		//判断按键，移动光标
		if (ch == 'i' || ch == 'I') //向上移动
		{
			cur_y--;
			if (cylic_move && cur_y==0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		if (ch == 'j' || ch == 'J') //向左移动
		{
			cur_x--;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 'l' || ch == 'L') //向右移动
		{
			cur_x++;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 'k' || ch == 'K') //向下移动
		{
			cur_y++;
			if (cylic_move && cur_y == 0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		//退出游戏
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int chw = _getch();
				if (chw == 13)
				{
					break;
				}
			}
			break;
		}
		//消除字符
		if (ch == ' ')
		{
			cout << " ";
		}
		//实际移动
		gotoxy(hout, cur_x, cur_y);
	}
	return 1;
}

/***************************************************************************
  函数名称：move_by_arrow
  功    能：上下左右控制移动
  输入参数：int cylic_move 是否循环移动
  返 回 值：1
  说    明：
***************************************************************************/
int move_by_arrow(int cylic_move)
{
	const int max_x = 69;
	const int max_y = 17;
	int cur_x = 35; //当前X坐标
	int cur_y = 9; //当前Y坐标
	int ch = 0; //按键返回值
	int special_scancode_flag = 0; //功能按键是否被按下

	/* 初始化工作 */
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hout);//清空菜单输入
	init_border(hout);//初始化边框
	gotoxy(hout, cur_x, cur_y); //移动光标到屏幕中心

	/* 主体内容 */
	while (1)
	{
		//重置标记状态
		special_scancode_flag = 0;
		ch = _getch();

		//处理特殊按键
		while (ch == 0x00 || ch == 0xE0 || ch == 0xF0)
		{
			special_scancode_flag = 1;
			ch = _getch();
		}
		//按下其他键时，重新输入
		if (!special_scancode_flag && ch!='q' && ch!=' ' && ch!='Q' )
		{
			continue;
		}

		//判断按键，移动光标
		if (ch == 72) //向上移动
		{
			cur_y--;
			if (cylic_move && cur_y == 0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		if (ch == 75) //向左移动
		{
			cur_x--;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 77) //向右移动
		{
			cur_x++;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 80) //向下移动
		{
			cur_y++;
			if (cylic_move && cur_y == 0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		//退出游戏
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int chw = _getch();
				if (chw == 13)
				{
					break;
				}
			}
			break;
		}
		//消除字符
		if (ch == ' ')
		{
			cout << " ";
		}

		//实际移动
		gotoxy(hout, cur_x, cur_y);
	}
	return 1;
}

/***************************************************************************
  函数名称：move_by_ijkl_ignoring_arrowkeys
  功    能：ijkl移动，左方向键不移动
  输入参数：int cylic_move 是否循环移动
  返 回 值：1
  说    明：
***************************************************************************/
int move_by_ijkl_ignoring_arrowkeys(int cylic_move)
{
	const int max_x = 69;
	const int max_y = 17;
	int cur_x = 35; //当前X坐标
	int cur_y = 9; //当前Y坐标
	int ch = 0; //按键返回值
	/*如果允许，可以把下面的disallow_special_function作为一个参数*/
	int disallow_special_function = 1; //禁止特殊按键
	int special_scancode_flag = 0; //功能按键是否被按下

	/* 初始化工作 */
	const HANDLE hout = GetStdHandle(STD_OUTPUT_HANDLE);
	cls(hout);//清空菜单输入
	init_border(hout);//初始化边框
	gotoxy(hout, cur_x, cur_y); //移动光标到屏幕中心

	/* 主体内容 */
	while (1)
	{
		//重置标记状态
		special_scancode_flag = 0;
		ch = _getch();

		//处理特殊按键
		//0xE0对应于方向键，0x00对应于小键盘关闭NumLocks的方向键
		while (ch == 0x00 || ch == 0xE0 || ch == 0xF0)
		{
			special_scancode_flag = disallow_special_function;
			ch = _getch();
			
		}
		//不允许按下特殊按键时，要求重新输入
		if (special_scancode_flag)
		{
			continue;
		}

		//判断按键，移动光标
		if (ch == 'i' || ch == 'I') //向上移动
		{
			cur_y--;
			if (cylic_move && cur_y == 0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		if (ch == 'j' || ch == 'J') //向左移动
		{
			cur_x--;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 'l' || ch == 'L') //向右移动
		{
			cur_x++;
			if (cylic_move && cur_x == 0)
			{
				cur_x = max_x;
			}
			else if (cylic_move && cur_x == max_x + 1)
			{
				cur_x = 1;
			}
			else if (cur_x == 0)
			{
				cur_x = 1;
			}
			else if (cur_x == max_x + 1)
			{
				cur_x = max_x;
			}
		}
		if (ch == 'k' || ch == 'K') //向下移动
		{
			cur_y++;
			if (cylic_move && cur_y == 0)
			{
				cur_y = max_y;
			}
			else if (cylic_move && cur_y == max_y + 1)
			{
				cur_y = 1;
			}
			else if (cur_y == 0)
			{
				cur_y = 1;
			}
			else if (cur_y == max_y + 1)
			{
				cur_y = max_y;
			}
		}
		//退出游戏
		if (ch == 'q' || ch == 'Q')
		{
			gotoxy(hout, 0, 23);
			cout << "游戏结束，按回车键返回菜单.";
			while (1)
			{
				int chw = _getch();
				if (chw == 13)
				{
					break;
				}
			}
			break;
		}
		//消除字符
		if (ch == ' ')
		{
			cout << " ";
		}
		//实际移动
		gotoxy(hout, cur_x, cur_y);
	}
	return 1;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数仅用于初始演示，可以按题目要求全部推翻重写
***************************************************************************/
int main()
{
	srand((unsigned int)(time(0)));

	while (1)
	{
		int menu_selected_item = 0; //选择的菜单项
		menu_selected_item = menu(); //菜单输入

		switch (menu_selected_item)
		{
			case 1:
				move_by_ijkl(0);
				break;
			case 2:
				move_by_ijkl(1);
				break;
			case 3:
				move_by_arrow(0);
				break;
			case 4:
				move_by_arrow(1);
				break;
			case 5:
				move_by_ijkl_ignoring_arrowkeys(0);
				break;
			case 6:
				move_by_ijkl_ignoring_arrowkeys(1);
				break;
			case 0:
				return 0;
		}
	}
	
	return 0;
}
/*
【补充】：
Demo中按下Ctrl+Shift+Alt+F10会使得“游戏结束”标识出现(此时第二次getch返回值被认为按下了q键)

【思考题回答(1)】
这与输入缓冲区和_getch()的返回有关。
（下方中，0xE0是按下方向键的第一个返回，0x00是关闭NumsLock后小键盘方向键的第一个返回）
在按下键盘的普通按键时，输入缓冲区有一般仅有一个值，且为按键对应字符或控制符的ASCII码
在按下键盘的特殊功能按键时，输入缓冲区内会有两个值，第一个为0xE0(对应于十进制224)或0x00，第二个则
可用于表征按下哪一个功能按键。通常读取一个控制符需要两次_getch()，第一次返回224(或0)，第二次则
取决于按下的功能按键。
重现此问题的原因是：通过一个无限循环，每次循环要求用户按下一个按键(执行一次_getch())，如果符合
是ijkl的ASCII码值，则执行对应的移动操作，否则不移动。按下左键时，第一次_getch得到的值是224或0,此时
该循环内不进行其他的操作，此时输入缓冲区还剩下左键输入留下的75，第二次_getch从输入缓冲区中得到
了这一个75，正好对应于ASCII中的'K'，在选择判定中，'K'对应于向下移动，因此此时执行处理向下移动部分
的代码，从而导致错误执行。
问题解决得方法是，如果第一次读取得_getch返回值是0xE0或0x00，则标记当前读取的是特殊功能键，再次执行一次
_getch()，综合标记和第二次读取得_getch()值判断按下得是方向键还是字母键

另外，Ctrl+Alt+Shift+F3、Ctrl+Alt+Shift+F4、Ctrl+Alt+Shift+F2、Ctrl+Alt+Shift+F5也对造成光标移动，原理同上
（在实现的5，6中，按下这些按键不会移动）

【思考题回答(2)】：
init_border产生随机显示字符的原理是生成20个整数x,y
并通过gotoxy将光标定位到控制台的(x,y)处，在此处进行putchar输出字符
如果两次随机数产生的x和y相同，则第二次putchar后，会将第一次putchar的结果覆盖掉
每覆盖一次，显示的字符个数就减少1
*/