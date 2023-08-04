#include <iostream>
using namespace std;

int main()
{
	const int ARRAY_SIZE = 21;
	const int INPUT_SIZE_MAX = 20;
	const int END_FLAG = 0;

	int array_size = 0;
	int array_content[ARRAY_SIZE];
	
	cout << "请输入任意个正整数（升序，最多20个），以-1结束" << endl;
	for (int i = 0; i < INPUT_SIZE_MAX; i++)
	{
		cin >> array_content[i];
		if (array_content[i] > END_FLAG)
		{
			array_size = i + 1;
		}
		else
		{
			break;
		}
	}
	cin.clear();
	cin.ignore(2147483647, '\n');
	if (array_size == 0)
	{
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "原数组为：" << endl;
	for (int i = 0; i < array_size; i++)
	{
		cout << array_content[i] << " ";
	}
	int insert_num = 0;
	cout << endl;
	cout << "请输入要插入的正整数" << endl;
	cin >> insert_num;
	//查找插入位置
	int l = 0, r = array_size - 1;
	while (l <= r)
	{
		int mid = (l + r) / 2;
		if (array_content[mid] > insert_num)
		{
			r = mid - 1;
		}
		else if(array_content[mid]<insert_num)
		{
			l = mid +1;
		}
		else
		{
			l = r = mid;
			break;
		}
	}
	//插入
	for (int i = array_size - 1; i >= l; i--)
	{
		array_content[i + 1] = array_content[i];
	}
	array_content[l] = insert_num;
	//输出
	cout << "插入后的数组为：" << endl;
	for (int i = 0; i <= array_size; i++)
	{
		cout << array_content[i] << " ";
	}
	cout << endl;
	return 0;
}