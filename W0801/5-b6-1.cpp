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
		cout << "��ʼ:" << "               ";
	}
	else
	{
		cout << "��" << setw(4) << move_counter << " ��(" << setw(2) << lvl << "): " << src << "-->" << dst;
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
	 �������ƣ�
	 ��    �ܣ���ӡn�㺺ŵ�����ƶ�˳��
	 ���������int n������
			   char src����ʼ��
			   char tmp���м���
			   char dst��Ŀ����
	 �� �� ֵ��
	 ˵    ����1�����������βΡ��������;���׼��
			   2�������������������κ���ʽ��ѭ��
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
  �������ƣ�
  ��    �ܣ�
  ���������
  �� �� ֵ��
  ˵    �����������(��������뺯��)�����õݹ麯��
***************************************************************************/
int main()
{
	int levels = 0;
	char start = 'D', dest = 'D';
	char tmp = 'D';
	int cinflag;
	while (1)
	{
		cout << "�����뺺ŵ���Ĳ���(1-10)��" << endl;
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
		cout << "��������ʼ��(A-C)��" << endl;
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
		cout << "������Ŀ����(A-C)��" << endl;
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
			cout << "Ŀ����(" << dest << ")��������ʼ��(" << start << ")��ͬ" << endl;
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
	//cout << "�ƶ�����Ϊ:" << endl;
	result_print(1, 0, 0, 0);
	hanoi(levels, start, tmp, dest);

	return 0;
}
