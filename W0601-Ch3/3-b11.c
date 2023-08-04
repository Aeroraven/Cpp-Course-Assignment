#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <windows.h> //取系统时间

int main()
{
	LARGE_INTEGER tick, begin, end;

	QueryPerformanceFrequency(&tick);	//获得计数器频率
	QueryPerformanceCounter(&begin);	//获得初始硬件计数器计数

	/* 此处是你的程序开始 */

	int counter = 0;
	int no11, no12, no13;//第1个数字的三位
	int no21, no22, no23;//第2个数字的三位
	int no31, no32, no33;//第3个数字的三位
	//如果3*i>=1953(即i>=651)，则增大i也不可能等于1953，故终止该循环
	//650中含零非法，也不考虑
	for (int i = 123; i <= 649; i++)
	{
		//判断数字重复 第1个三位数
		no11 = i % 10;
		no12 = i / 10 % 10;
		no13 = i / 100;
		if (no11 * no12 * no13 == 0)
		{
			continue;
		}
		if (no11 == no12 || no11 == no13 || no12 == no13)
		{
			continue;
		}
		//如果i+j+(j+1)>1953，则增大j也不可能等于1953，故终止该循环
		int temp = 1952 - i;//j可取到的最大值
		int jmin = 1953 - i - 987; //如果j过小，得到的k就不符合要求
		int jstart = 0;
		//确定j的起始值
		if (jmin > i + 1)
		{
			jstart = jmin;
		}
		else
		{
			jstart = i + 1;
		}
		for (int j = jstart; 2 * j <= temp; j++)
		{
			//判断数字重复 第2个三位数
			no21 = j % 10;
			no22 = j / 10 % 10;
			no23 = j / 100;
			if (no21 * no22 * no23 == 0)
			{
				continue;
			}
			if (no21 == no22 || no22 == no23 || no23 == no21)
			{
				continue;
			}
			//判断和之前数字是否重复
			if (no21 == no11 || no21 == no12 || no21 == no13)
			{
				continue;
			}
			if (no22 == no11 || no22 == no12 || no22 == no13)
			{
				continue;
			}
			if (no23 == no11 || no23 == no12 || no23 == no13)
			{
				continue;
			}
			//第三个数

			int k = 1953 - i - j;
			//k值非法，跳过循环
			if (k < 124)
			{
				//最小数位不重复的三位数是123
				//由于j增大后k减小，故k<124时直接终止j的循环
				break;
			}

			//判断数字重复 第3个三位数
			no31 = k % 10;
			no32 = k / 10 % 10;
			no33 = k / 100;
			if (no31 * no32 * no33 == 0)
			{
				continue;
			}
			if (no31 == no32 || no32 == no33 || no33 == no31)
			{
				continue;
			}
			//判断和之前数字是否重复
			if (no31 == no11 || no31 == no12 || no31 == no13)
			{
				continue;
			}
			if (no32 == no11 || no32 == no12 || no32 == no13)
			{
				continue;
			}
			if (no33 == no11 || no33 == no12 || no33 == no13)
			{
				continue;
			}
			if (no31 == no21 || no31 == no22 || no31 == no23)
			{
				continue;
			}
			if (no32 == no21 || no32 == no22 || no32 == no23)
			{
				continue;
			}
			if (no33 == no21 || no33 == no22 || no33 == no23)
			{
				continue;
			}
			//全部合法时，进行输出
			counter++;
			printf("No.%3d : %d+%d+%d=1953\n", counter, i, j, k);

		}
	}
	printf("total=%d\n", counter);
	

	/* 此处是你的程序结束 */

	QueryPerformanceCounter(&end);		//获得终止硬件计数器计数

	//QuadPart是longlong类型 
	printf("计数器频率 : %I64dHz\n", tick.QuadPart);
	printf("计数器计数 : %I64d\n", end.QuadPart - begin.QuadPart);
	printf("%.6f秒\n", (double)(end.QuadPart - begin.QuadPart) / tick.QuadPart);
	return 0;
}
