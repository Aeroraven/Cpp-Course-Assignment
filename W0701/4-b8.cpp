#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、仅允许hanoi中定义一个静态局部变量
   3、允许添加用于输入层数、起始/目标柱的函数，函数中允许使用循环处理错误输入
   4、如果输入用函数进行，则main中不允许出现任何形式的循环（while、do-while、for、if-goto）
	  如果输入在main中进行，则main中允许出现循环
   --------------------------------------------------------------------- */

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
			   3、允许定义一个静态局部变量
   ***************************************************************************/
void hanoi(int n, char src, char tmp, char dst)
{
	static int cnt = 0;
	if (n > 1)
	{
		hanoi(n - 1, src, dst, tmp);
	}
	//move (src->dst);
	cout << setw(5) << (++cnt) << ":" << setw(3) << n << "# " << src << "-->" << dst << endl;
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
	while (1)
	{
		cout << "请输入汉诺塔的层数(1-16)" << endl;
		cin >> levels;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(2147483647, '\n');
		if (cinflag || levels <= 0 || levels > 16)
		{
			continue;
		}
		break;
	}
	while (1) {
		cout << "请输入起始柱(A-C)" << endl;
		cin >> start;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(2147483647, '\n');
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
	while (1)
	{
		cout << "请输入目标柱(A-C)" << endl;
		cin >> dest;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(2147483647, '\n');
		if (dest >= 'a' && dest <= 'c')
		{
			dest = dest - 'a' + 'A';
		}
		if (cinflag || dest < 'A' || dest>'C' )
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
	cout << "移动步骤为:" << endl;
	hanoi(levels, start, tmp, dest);
	return 0;
}
