#include <iostream>
#include <string>
#define STUDENT_CNT 10
using namespace std;

void info_input(string stuId[], string stuName[], int stuGrades[])
{
	for (int i = 0; i < STUDENT_CNT; i++)
	{
		cout << "请输入第" << i + 1 << "个人的学号、姓名、成绩" << endl;
		cin >> stuId[i] >> stuName[i] >> stuGrades[i];
	}
	cout << endl;
}
int tj_strcmp(string s1, string s2)
{
	int s1_valid = 1;
	int s2_valid = 1;
	int s1_ascii, s2_ascii;
	int i = 0;
	int ans = 0;
	while (1)
	{
		if (s1[i] == '\0')
		{
			s1_valid = 0;
		}
		if (s1_valid == 0)
		{
			s1_ascii = 0;
		}
		else
		{
			s1_ascii = (int)(s1[i]);
		}

		if (s2[i] == '\0')
		{
			s2_valid = 0;
		}
		if (s2_valid == 0)
		{
			s2_ascii = 0;
		}
		else
		{
			s2_ascii = (int)(s2[i]);
		}
		ans = s1_ascii - s2_ascii;
		if (ans != 0)
		{
			return ans;
		}
		else if (s2_valid == 0 && s1_valid == 0)
		{
			return 0;
		}
		i++;
	}
	return 0;
}
void info_sort(string stuId[], string stuName[], int stuGrades[])
{

	for (int i = 0; i < STUDENT_CNT; i++)
	{
		int select_id = i;
		for (int j = i + 1; j < STUDENT_CNT; j++)
		{
			if (stuId[select_id] < stuId[j])
			{
				select_id = j;
			}
		}
		if (select_id != i)
		{
			//Swap stuId 
			string tmp1 = stuId[i];
			stuId[i] = stuId[select_id];
			stuId[select_id] = tmp1;
			//Swap Name
			string tmp2 = stuName[i];
			stuName[i] = stuName[select_id];
			stuName[select_id] = tmp2;
			//Swap Grade
			int tmp = stuGrades[i];
			stuGrades[i] = stuGrades[select_id];
			stuGrades[select_id] = tmp;
		}
	}
}

void info_print(string stuId[], string stuName[], int stuGrades[])
{
	cout << "不及格名单:" << endl;
	for (int i = 0; i < STUDENT_CNT; i++)
	{
		if (stuGrades[i] < 60)
		{
			cout << stuName[i] << " " << stuId[i] << " " << stuGrades[i] << endl;
		}
	}
}
int main()
{
	string stuId[STUDENT_CNT];
	string stuName[STUDENT_CNT];
	int stuGrades[STUDENT_CNT];

	info_input(stuId, stuName, stuGrades);
	info_sort(stuId, stuName, stuGrades);
	info_print(stuId, stuName, stuGrades);

	return 0;
}