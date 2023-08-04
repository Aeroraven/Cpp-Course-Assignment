#include <iostream>
using namespace std;

int main()
{
	const int MATRIX_SIZE = 9;
	const int HOUSE_SIZE = 3;
	int matrix[MATRIX_SIZE][MATRIX_SIZE];
	int counter[MATRIX_SIZE + 1];
	for (int i = 0; i <= MATRIX_SIZE; i++)
	{
		counter[i] = 0;
	}
	cout << "请输入9*9的矩阵，值为1-9之间" << endl;
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			while (1)
			{
				matrix[i][j] = 1000;
				cin >> matrix[i][j];
				if (cin.fail())
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					cin.clear();
					cin.ignore(65536, '\n');
					continue;
				}
				if (matrix[i][j] <= 0 || matrix[i][j] > MATRIX_SIZE)
				{
					cout << "请重新输入第" << i + 1 << "行" << j + 1 << "列(行列均从1开始计数)的值" << endl;
					//cin.clear();
					//cin.ignore(65536, '\n');
					continue;
				}
				break;
			}

		}
	}
	int valid_flag = true;

	//按行统计
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			counter[matrix [i][j]] ++;
		}
		int standard = counter[1];
		for (int j = 1; j <= MATRIX_SIZE; j++)
		{
			if (counter[j] != standard)
			{
				valid_flag = false;
			}
		}
	}

	//按列统计
	for (int i = 0; i < MATRIX_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE; j++)
		{
			counter[matrix[j][i]] ++;
		}
		int standard = counter[1];
		for (int j = 1; j <= MATRIX_SIZE; j++)
		{
			if (counter[j] != standard)
			{
				valid_flag = false;
			}
		}
	}
	//宫格
	for (int i = 0; i < MATRIX_SIZE / HOUSE_SIZE; i++)
	{
		for (int j = 0; j < MATRIX_SIZE / HOUSE_SIZE; j++)
		{
			for (int k = 0; k < HOUSE_SIZE; k++)
			{
				for (int m = 0; m < HOUSE_SIZE; m++)
				{
					int row = i * HOUSE_SIZE + k;
					int col = j * HOUSE_SIZE + m;
					counter[matrix[row][col]]++;
				}
			}
			int standard = counter[1];
			for (int k = 1; k <= MATRIX_SIZE; k++)
			{
				if (counter[k] != standard)
				{
					valid_flag = false;
				}
			}
		}
	}
	//输出结果
	if (valid_flag)
	{
		cout << "是数独的解" << endl;
	}
	else
	{
		cout << "不是数独的解" << endl;
	}
	return 0;
}
