#include <iostream>
using namespace std;

int main()
{
	const int STUDENT_SIZE_MAX = 1000;
	const int SCORE_UPPER_BOUND = 101;
	const int END_FLAG = -1;
	const int CRLF_COND = 10;

	int student_score[STUDENT_SIZE_MAX];
	int score_counter[SCORE_UPPER_BOUND];
	int student_size = 0;
	//清空
	for (int i = 0; i < SCORE_UPPER_BOUND; i++)
	{
		score_counter[i] = 0;
	}
	cout << "请输入成绩（最多1000个），以-1结束" << endl;
	for (int i = 0; i < STUDENT_SIZE_MAX; i++)
	{
		cin >> student_score[i];
		if (student_score[i] <= END_FLAG)
		{
			break;
		}
		student_size++;
	}
	if (student_size == 0) {
		cout << "无有效输入" << endl;
		return 0;
	}
	cout << "输入的数组为:" << endl;
	for (int i = 0; i < student_size; i++)
	{
		cout << student_score[i] << " ";
		if ((i + 1) % CRLF_COND == 0 || i == student_size - 1)
		{
			cout << endl;
		}
		score_counter[student_score[i]]++;
	}
	cout << "分数与人数的对应关系为:" << endl;
	for (int i = SCORE_UPPER_BOUND - 1; i >= 0; i--)
	{
		if (score_counter[i] != 0)
		{
			cout << i << " " << score_counter[i] << endl;
		}
	}
	return 0;
}