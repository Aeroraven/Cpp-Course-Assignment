#include <iostream>
#include <iomanip>
using namespace std;

const int STACK_SIZE = 10;
const int COL_COUNT = 3;

int stack_top_a = 0;
int stack_top_b = 0;
int stack_top_c = 0;
int move_counter = 0;

int stack_a[STACK_SIZE];
int stack_b[STACK_SIZE];
int stack_c[STACK_SIZE];

void result_print(int is_first, int lvl, char src,char dst)
{
	if (is_first)
	{
		cout << "锟斤拷始:" << "               ";
	}
	else
	{
		cout << "锟斤拷" << setw(4) << move_counter << " 锟斤拷(" << setw(2) << lvl << "): " << src << "-->" << dst;
	}
	cout << " A:";
	for (int i = 0; i < stack_top_a; i++) 
	{
		cout << setw(2)<< stack_a[i];
	}
	for (int i = stack_top_a ; i < 10; i++) 
	{
		cout << "  ";
	}
	cout << " B:";
	for (int i = 0; i < stack_top_b; i++)
	{
		cout << setw(2)<< stack_b[i] ;
	}
	for (int i = stack_top_b ; i < 10; i++)
	{
		cout << "  ";
	}
	cout << " C:";
	for (int i = 0; i < stack_top_c; i++)
	{
		cout <<setw(2)<< stack_c[i];
	}
	for (int i = stack_top_c ; i < 10; i++)
	{
		cout << "  ";
	}
	cout << endl;
}
   /***************************************************************************
	 锟斤拷锟斤拷锟斤拷锟狡ｏ拷
	 锟斤拷    锟杰ｏ拷锟斤拷印n锟姐汉诺锟斤拷锟斤拷锟狡讹拷顺锟斤拷
	 锟斤拷锟斤拷锟斤拷锟斤拷锟絠nt n锟斤拷锟斤拷锟斤拷
			   char src锟斤拷锟斤拷始锟斤拷
			   char tmp锟斤拷锟叫硷拷锟斤拷
			   char dst锟斤拷目锟斤拷锟斤拷
	 锟斤拷 锟斤拷 值锟斤拷
	 说    锟斤拷锟斤拷1锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿参★拷锟斤拷锟斤拷锟斤拷锟酵撅拷锟斤拷准锟斤拷
			   2锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟轿猴拷锟斤拷式锟斤拷循锟斤拷
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
	result_print(0,n, src, dst);
	if (n != 1) 
	{
		hanoi(n - 1, tmp, src, dst);
	}
	
}

/***************************************************************************
  锟斤拷锟斤拷锟斤拷锟狡ｏ拷
  锟斤拷    锟杰ｏ拷
  锟斤拷锟斤拷锟斤拷锟斤拷锟�
  锟斤拷 锟斤拷 值锟斤拷
  说    锟斤拷锟斤拷锟斤拷锟斤拷锟斤拷锟�(锟斤拷锟斤拷锟斤拷锟斤拷牒拷锟�)锟斤拷锟斤拷锟矫递归函锟斤拷
***************************************************************************/
int main()
{
	int levels = 0;
	char start = 'D', dest = 'D';
	char tmp = 'D';
	int cinflag;
	while (1)
	{
		cout << "锟斤拷锟斤拷锟诫汉诺锟斤拷锟侥诧拷锟斤拷(1-10)锟斤拷" << endl;
		cin >> levels;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(2147483647, '\n');
		if (cinflag || levels <= 0 || levels > 10)
		{
			continue;
		}
		break;
	}
	while (1)
	{
		cout << "锟斤拷锟斤拷锟斤拷锟斤拷始锟斤拷(A-C)锟斤拷" << endl;
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
		cout << "锟斤拷锟斤拷锟斤拷目锟斤拷锟斤拷(A-C)锟斤拷" << endl;
		cin >> dest;
		cinflag = cin.fail();
		cin.clear();
		cin.ignore(2147483647, '\n');
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
			cout << "目锟斤拷锟斤拷(" << dest << ")锟斤拷锟斤拷锟斤拷锟斤拷始锟斤拷(" << start << ")锟斤拷同" << endl;
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
	//cout << "锟狡讹拷锟斤拷锟斤拷为:" << endl;
	result_print(1, 0, 0, 0);
	hanoi(levels, start, tmp, dest);

	return 0;
}
