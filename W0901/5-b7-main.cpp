#include <iostream>
#include <iomanip>
#include <conio.h>
#include "5-b7.h"

#define OFFSET_EQUIV_SIGNS_X 12
#define OFFSET_EQUIV_SIGNS_Y 9

#define OFFSET_SIGN_A_Y 11
#define OFFSET_SIGN_B_Y 21
#define OFFSET_SIGN_C_Y 31
#define OFFSET_SIGN_X 13
#define OFFSET_STEP_DETAIL_X 17
#define OFFSET_COLUMN_TOP_X 2
#define OFFSET_STOP_X 26
#define INT_MAX_SELFDEF 2147483647 //避免使用climits
#define MAX_LEVELS 10
#define STACK_SIZE 10
#define COL_COUNT 3

using namespace std;


static int stack_top_a = 0;
static int stack_top_b = 0;
static int stack_top_c = 0;
static int move_counter = 0;

int stack_a[STACK_SIZE];
int stack_b[STACK_SIZE];
int stack_c[STACK_SIZE];

static int delay_opt = -1;
static int disp_internal_stack = -1;

void transposed_cct_gotoxy(int x, int y)
{
	cct_gotoxy(y, x);
}

void vertical_print_initial()
{
	//打印等号和标签
	transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X, OFFSET_EQUIV_SIGNS_Y);
	cout << "=========================";
	transposed_cct_gotoxy(OFFSET_SIGN_X, OFFSET_SIGN_A_Y);
	cout << "A";
	transposed_cct_gotoxy(OFFSET_SIGN_X, OFFSET_SIGN_B_Y);
	cout << "B";
	transposed_cct_gotoxy(OFFSET_SIGN_X, OFFSET_SIGN_C_Y);
	cout << "C";
	//A柱
	for (int i = 0, j = OFFSET_EQUIV_SIGNS_X - 1; i < stack_top_a; i++, j--)
	{
		transposed_cct_gotoxy(j, OFFSET_SIGN_A_Y - 1);
		cout << setw(2) << stack_a[i];
	}

	//B柱
	for (int i = 0, j = OFFSET_EQUIV_SIGNS_X - 1; i < stack_top_b; i++, j--)
	{
		transposed_cct_gotoxy(j, OFFSET_SIGN_B_Y - 1);
		cout << setw(2) << stack_b[i];
	}
	//C柱
	for (int i = 0, j = OFFSET_EQUIV_SIGNS_X - 1; i < stack_top_c; i++, j--)
	{
		transposed_cct_gotoxy(j, OFFSET_SIGN_C_Y - 1);
		cout << setw(2) << stack_c[i];
	}
}
void vertical_print_alter(char src, char dst)
{
	//从原始柱上消除栈顶
	if (src == 'A')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_a - 1, OFFSET_SIGN_A_Y - 1);
		cout << "  ";
	}
	if (src == 'B')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_b - 1, OFFSET_SIGN_B_Y - 1);
		cout << "  ";
	}
	if (src == 'C')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_c - 1, OFFSET_SIGN_C_Y - 1);
		cout << "  ";
	}
	//添加现有栈顶
	if (dst == 'A')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_a, OFFSET_SIGN_A_Y - 1);
		cout << setw(2) << stack_a[stack_top_a - 1];
	}
	if (dst == 'B')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_b, OFFSET_SIGN_B_Y - 1);
		cout << setw(2) << stack_b[stack_top_b - 1];
	}
	if (dst == 'C')
	{
		transposed_cct_gotoxy(OFFSET_EQUIV_SIGNS_X - stack_top_c, OFFSET_SIGN_C_Y - 1);
		cout << setw(2) << stack_c[stack_top_c - 1];
	}
}

void iterative_sleep(int deg)
{
	for (int i = 0; i < deg; i++)
	{
		for (int j = 0; j <= 20000000; j++)
		{
			int c = 0;
			c++;
		}
	}
	for (int j = 0; j <= 6000000; j++)
	{
		int c = 0;
	}
}

void pause_enter()
{
	if (delay_opt != 0)
		return;
	while (1)
	{
		int s = _getch();
		if (s == 13)
		{
			break;
		}
	}
}

void result_print(int is_first, int lvl, char src, char dst)
{
	transposed_cct_gotoxy(OFFSET_STEP_DETAIL_X, 0);
	if (is_first)
	{
		cout << "初始:" << "               ";
	}
	else
	{
		cout << "第" << setw(4) << move_counter << "步(" <<  lvl << "#: " << src << "-->" << dst << ") ";
	}
	if (disp_internal_stack == 0)
	{
		cout << endl;
		return;
	}
	cout << " A:";
	for (int i = 0; i < stack_top_a; i++)
	{
		cout << setw(2) << stack_a[i];
	}
	for (int i = stack_top_a; i < 10; i++)
	{
		cout << "  ";
	}
	cout << " B:";
	for (int i = 0; i < stack_top_b; i++)
	{
		cout << setw(2) << stack_b[i];
	}
	for (int i = stack_top_b; i < 10; i++)
	{
		cout << "  ";
	}
	cout << " C:";
	for (int i = 0; i < stack_top_c; i++)
	{
		cout << setw(2) << stack_c[i];
	}
	for (int i = stack_top_c; i < 10; i++)
	{
		cout << "  ";
	}
	cout << endl;
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
	if (src == 'A')
	{
		moved = stack_a[--stack_top_a];
	}
	if (src == 'B')
	{
		moved = stack_b[--stack_top_b];
	}
	if (src == 'C')
	{
		moved = stack_c[--stack_top_c];
	}
	if (dst == 'A')
	{
		stack_a[stack_top_a++] = moved;
	}
	if (dst == 'B')
	{
		stack_b[stack_top_b++] = moved;
	}
	if (dst == 'C')
	{
		stack_c[stack_top_c++] = moved;
	}

	if (delay_opt <= 5 && delay_opt >= 1)
	{
		iterative_sleep((5 - delay_opt) * (5 - delay_opt));
	}

	result_print(0, n, src, dst);
	pause_enter();
	vertical_print_alter(src, dst);
	pause_enter();

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
	char tmp = 'D';
	int cinflag;
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-10)" << endl;
		cin >> levels;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX_SELFDEF, '\n');
		if (cinflag || levels <= 0 || levels > 10)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "请输入起始柱(A-C)" << endl;
		cin >> start;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX_SELFDEF, '\n');
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
	if (start == 'A')
	{
		for (int i = levels; i >= 1; i--)
		{
			stack_a[stack_top_a++] = i;
		}
	}
	if (start == 'B')
	{
		for (int i = levels; i >= 1; i--)
		{
			stack_b[stack_top_b++] = i;
		}
	}
	if (start == 'C')
	{
		for (int i = levels; i >= 1; i--)
		{
			stack_c[stack_top_c++] = i;
		}
	}
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dest;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(INT_MAX_SELFDEF, '\n');
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
			cout << "目标柱(" << dest << ")不能与起始柱(" << start << ")相同" << endl;
			continue;
		}
		break;
	}
	if (static_cast<int>(start) + static_cast<int>(dest) == static_cast<int>('A') + static_cast<int>('C'))
	{
		tmp = 'B';
	}
	else if (static_cast<int>(start) + static_cast<int>(dest) == static_cast<int>('B') + static_cast<int>('C'))
	{
		tmp = 'A';
	}
	else if (static_cast<int>(start) + static_cast<int>(dest) == static_cast<int>('A') + static_cast<int>('B'))
	{
		tmp = 'C';
	}

	while (1)
	{
		delay_opt = 9999;
		cout << "请输入移动速度(0-5: 0-按回车单步演示 1-延时最长 5-延时最短)" << endl;
		cin >> delay_opt;
		cinflag = cin.fail();
		if (cinflag)
		{
			cin.clear();
			cin.ignore(INT_MAX_SELFDEF, '\n');
		}
		if (cinflag || delay_opt < 0 || delay_opt > 5)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		disp_internal_stack = 9999;
		cout << "请输入是否显示内部数组值(0-不显示 1-显示)" << endl;
		cin >> disp_internal_stack;
		cinflag = cin.fail();
		if (cinflag)
		{
			cin.clear();
			cin.ignore(INT_MAX_SELFDEF, '\n');
		}
		if (cinflag || disp_internal_stack < 0 || disp_internal_stack > 1)
		{
			continue;
		}
		break;
	}
	//处理输出
	cct_cls();
	transposed_cct_gotoxy(0, 0);
	if (disp_internal_stack)
	{
		cout << "从 " << start << " 移动到 " << dest << "，共 " << levels << " 层，延时设置为 " << delay_opt << "，显示内部数组值" << endl;
	}
	else
	{
		cout << "从 " << start << " 移动到 " << dest << "，共 " << levels << " 层，延时设置为 " << delay_opt << "，不显示内部数组值" << endl;
	}
	if (disp_internal_stack == 1)
	{
		result_print(1, 0, 0, 0);
		pause_enter();
	}
	vertical_print_initial();
	pause_enter();
	hanoi(levels, start, tmp, dest);

	//终止光标定位
	transposed_cct_gotoxy(OFFSET_STOP_X, 0);
	return 0;
}
