#include <iostream>
using namespace std;

int main()
{
	//常量
	//Demo是1001,作业要求是1000,但不考虑输入错误,所以该项可以为任意>=1000的值
	const int ARRAY_SIZE_MAX = 1001;
	const int END_FLAG = -1;

	//变量
	int score_size = 0;
	int score_list[ARRAY_SIZE_MAX];
	int read_int = 0;

	//输入处理
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	while (1)
	{
		read_int = END_FLAG;
		cin >> read_int;
		if (read_int > END_FLAG)
		{
			score_list[score_size++] = read_int;
			if (score_size >= ARRAY_SIZE_MAX)
			{
				break;
			}
			continue;
		}
		if (!score_size)
		{
			cout << "无有效输入" << endl;
			return 0;
		}
		break;
	}
	cout << "输入的数组为:" << endl;
	for (int i = 0; i < score_size; i++)
	{
		cout << score_list[i] << " ";
		if (i + 1 == score_size || i % 10 == 9)
		{
			cout << endl;
		}
	}
	cout << "分数与名次的对应关系为:" << endl;

	//堆排序
	int heap_adjust_node = score_size;
	int heap_size = score_size;
	while (heap_adjust_node--)
	{
		int current_node = heap_adjust_node;
		int child_node = current_node * 2 + 1;
		int father_value = score_list[heap_adjust_node];
		while (child_node < score_size)
		{
			//选择更小节点
			if (child_node < score_size - 1)
			{
				if (score_list[child_node + 1] < score_list[child_node])
				{
					child_node++;
				}
			}
			//比较结点
			if (father_value > score_list[child_node])
			{
				score_list[current_node] = score_list[child_node];
				current_node = child_node;
				child_node = child_node * 2;
				child_node++;
			}
			else
			{
				break;
			}
		}
		score_list[current_node] = father_value;
	}
	while (heap_size > 1)
	{
		//交换
		int temp = score_list[0];
		score_list[0] = score_list[--heap_size];
		score_list[heap_size] = temp;

		
		int current_node = 0;
		int child_node = current_node * 2 + 1;
		int father_value = score_list[0];
		while (child_node < heap_size)
		{
			//选择更小节点
			if (child_node < heap_size - 1)
			{
				if (score_list[child_node + 1] < score_list[child_node])
				{
					child_node++;
				}
			}
			//比较结点
			if (father_value > score_list[child_node])
			{
				score_list[current_node] = score_list[child_node];
				current_node = child_node;
				child_node = child_node * 2;
				child_node++;
			}
			else
			{
				break;
			}
		}
		score_list[current_node] = father_value;
	}
	//输出
	int last_output = -1, parallel_counter = 1, rank = 0;
	for (int i = 0; i < score_size; i++)
	{
		if (score_list[i] == last_output)
		{
			parallel_counter++;
		}
		else
		{
			last_output = score_list[i];
			rank += parallel_counter;
			parallel_counter = 1;
		}
		cout << score_list[i] << ' ' << rank << endl;
	}

	return 0;
}
