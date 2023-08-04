#include <iostream>
#include <iomanip>
#include <cstdio>
using namespace std;

/* -----------------------------------------------------------------------------------
		允许   ：按需增加一个或多个函数，但是所有增加的函数中不允许任何形式的循环
				 定义符号常量
				 定义const型变量
		不允许 ：定义全局变量
   ----------------------------------------------------------------------------------- */
void seq_print_level(int total_levels, int cur_level, int cur_pos)
{
	if (cur_pos == cur_level)
	{
		cout << setw(total_levels - cur_level) << static_cast<char>(cur_pos + 'A');
		if (cur_level != 0)
		{
			seq_print_level(total_levels, cur_level, cur_pos - 1);
		}
	}
	else if (cur_pos > 0)
	{
		cout << static_cast<char>(cur_pos + 'A');
		seq_print_level(total_levels, cur_level, cur_pos - 1);
	}
	else if (cur_pos == 0)
	{
		cout << 'A';
		if (cur_level != 0)
		{
			seq_print_level(total_levels, cur_level, cur_pos - 1);
		}
	}
	else if (cur_pos > -cur_level)
	{
		cout << static_cast<char>(-cur_pos + 'A');
		seq_print_level(total_levels, cur_level, cur_pos - 1);
	}
	else
	{
		cout << static_cast<char>(-cur_pos + 'A');
	}
	return;
}

void inv_print_level(int total_levels, int cur_level, int cur_pos)
{
	if (cur_pos == cur_level)
	{
		cout << setw(total_levels - cur_level) << static_cast<char>((total_levels-1-cur_pos) + 'A');
		if (cur_level != 0)
		{
			inv_print_level(total_levels, cur_level, cur_pos - 1);
		}
	}
	else if (cur_pos > 0)
	{
		cout << static_cast<char>((total_levels - 1 -cur_pos) + 'A');
		inv_print_level(total_levels, cur_level, cur_pos - 1);
	}
	else if (cur_pos == 0)
	{
		cout << static_cast<char>(total_levels-1 + 'A');
		if (cur_level != 0)
		{
			inv_print_level(total_levels, cur_level, cur_pos - 1);
		}
	}
	else if (cur_pos > -cur_level)
	{
		cout << static_cast<char>((total_levels - 1 +cur_pos) + 'A');
		inv_print_level(total_levels, cur_level, cur_pos - 1);
	}
	else
	{
		cout << static_cast<char>((total_levels - 1 +cur_pos) + 'A');
	}
	return;
}
   /***************************************************************************
	 函数名称：
	 功    能：正向或反向打印三角塔
	 输入参数：order - 0 ：正三角形塔
			   order - 1 ：倒三角形塔
	 返 回 值：
	 说    明：
   ***************************************************************************/
void print_tower(char start_ch, char end_ch, int order)
{
	/* 按需实现，函数中不允许任何形式的循环，不允许定义静态局部变量 */
	cout << setfill(' ');
	if (order == 0)
	{
		seq_print_level(end_ch - 'A' + 1, start_ch - 'A', start_ch - 'A');
		cout << endl;
		if (start_ch != end_ch)
		{
			print_tower(start_ch + 1, end_ch, order);
		}
	}
	else if (order == 1)
	{
		inv_print_level(end_ch - 'A' + 1, end_ch - start_ch, end_ch - start_ch);
		cout << endl;
		if (start_ch != end_ch)
		{
			print_tower(start_ch + 1, end_ch, order);
		}
	}
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准修改
***************************************************************************/
int main()
{
	char end_ch;

	/* 键盘输入结束字符(仅大写有效) */
	while (1) {
		cout << "请输入结束字符(A~Z)" << endl;
		end_ch = getchar();			//读缓冲区第一个字符
		while (getchar() != '\n')	//清空缓冲区剩余字符
			;
		if (end_ch >= 'A' && end_ch <= 'Z')
			break;
	}

	/* 正三角字母塔(中间为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	cout << "正三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl;/* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 0);
	cout << endl;

	/* 倒三角字母塔(两边为A) */
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	cout << "倒三角字母塔" << endl;
	cout << setfill('=') << setw((end_ch - 'A') * 2 + 1) << '=' << endl; /* 按字母塔最大长度输出= */
	print_tower('A', end_ch, 1);
	cout << endl;

	return 0;
}
