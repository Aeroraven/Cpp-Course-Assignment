#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define STUDENT_CNT 10

void info_input(char stuId[][8], char stuName[][9], int stuGrades[])
{
	for (int i = 0; i < STUDENT_CNT; i++)
	{
		printf("请输入第%d个人的学号、姓名、成绩\n", i + 1);
		int r = scanf("%s%s%d", stuId[i], stuName[i], &stuGrades[i]);
	}
	printf("\n");
}
int tj_strcmp(const char s1[], const char s2[])
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
void info_sort(char stuId[][8], char stuName[][9], int stuGrades[])
{

	for (int i = 0; i < STUDENT_CNT; i++)
	{
		int select_id = i;
		for (int j = i + 1; j < STUDENT_CNT; j++)
		{
			if (tj_strcmp(stuId[select_id], stuId[j]) < 0)
			{
				select_id = j;
			}
		}
		if (select_id != i)
		{
			//Swap stuId 
			for (int j = 0; j < 8; j++)
			{
				char tmp = stuId[i][j];
				stuId[i][j] = stuId[select_id][j];
				stuId[select_id][j] = tmp;
			}
			//Swap Name
			for (int j = 0; j < 9; j++)
			{
				char tmp = stuName[i][j];
				stuName[i][j] = stuName[select_id][j];
				stuName[select_id][j] = tmp;
			}
			//Swap Grade
			int tmp = stuGrades[i];
			stuGrades[i] = stuGrades[select_id];
			stuGrades[select_id] = tmp;
		}
	}
}

void info_print(char stuId[][8], char stuName[][9], int stuGrades[])
{
	printf("不及格名单:\n");
	for (int i = 0; i < STUDENT_CNT; i++)
	{
		if (stuGrades[i] < 60)
		{
			printf("%s %s %d\n", stuName[i], stuId[i], stuGrades[i]);
		}

	}
}
int main()
{
	char stuId[STUDENT_CNT][8];
	char stuName[STUDENT_CNT][9];
	int stuGrades[STUDENT_CNT];

	info_input(stuId, stuName, stuGrades);
	info_sort(stuId, stuName, stuGrades);
	info_print(stuId, stuName, stuGrades);


	return 0;
}