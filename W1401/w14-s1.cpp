#include <iostream>
#include <iomanip>
using namespace std;

/* ----具体要求----
   1、不允许添加其它头文件
   2、不允许定义全局变量、静态局部变量（全局只读变量或宏定义不受此限制）
   3、最多允许添加一个函数，且需要满足要求
   ---------------------------------------------------------------------
*/

#define N	10

struct course {
	float value;	//某课程的成绩（百分制）
	float weight;	//某课程的学分（权重）
	int   gpa;	//某课程的绩点（同济规则，[0..60) - 0, [60,70) - 2, [70,80) - 3, [80-90) - 4,[90,100] - 5）
};

struct student {
	int   no;               //学号（虽然用int不够合理，此处不考虑）
	char  name[9];          //假设姓名最长4个汉字
	struct course score[3]; //数组放三门课的成绩（未使用宏定义，函数实现时，直接写3即可）
	float wgpa_sum;                        //可增加其它你认为需要增加的结构体成员（限一个），不要则删除本行
};

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：此处最多允许添加一个函数，且函数的形参、自动变量等都必须是简单变量（即不允许[]形式）
***************************************************************************/



/***************************************************************************
  函数名称：
  功    能：输入10个学生的信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void input(struct student* stu, int num)
{
	/* 除这两个整型变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int k=0; )形式的新变量定义同样禁止 */
		
	int i, j;
	/* 函数的实现部分 */
	for(i=0;i<num;i++)
	{
		cout<<"请输入第"<<setw(2)<<i+1<<"个学生的信息 : ";
		cin>>stu[i].no;
		cin>>stu[i].name;
		stu[i].wgpa_sum=0;
		for(j=0;j<3;j++)
		{
			cin>>stu[i].score[j].value;
			cin>>stu[i].score[j].weight;
			if(stu[i].score[j].value<60)
			{
				stu[i].score[j].gpa=0;
			}
			else if(stu[i].score[j].value<70)
			{
				stu[i].score[j].gpa=2;
			}
			else if(stu[i].score[j].value<80)
			{
				stu[i].score[j].gpa=3;
			}
			else if(stu[i].score[j].value<90)
			{
				stu[i].score[j].gpa=4;
			}
			else if(stu[i].score[j].value<=100)
			{
				stu[i].score[j].gpa=5;
			}
			else
			{
				stu[i].score[j].gpa=0;
			} 
			stu[i].wgpa_sum+=stu[i].score[j].weight*stu[i].score[j].gpa;
			
		} 
		stu[i].wgpa_sum/=(stu[i].score[0].weight+stu[i].score[1].weight+stu[i].score[2].weight);
	}

}

/***************************************************************************
  函数名称：
  功    能：输出基本信息
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_base(struct student* stu, int num)
{
	/* 除这两个指针变量外，本函数不再允许定义任何形式的变量
		 如果不用，允许删除，但不得增加或替换为其它形式的变量
		包括for(int i=0; )形式的新变量定义同样禁止 */
	struct student* ps;
	struct course* pc;
	
	/* 函数的实现部分，不允许任何形式的[]出现 */
	cout<<endl;
	cout<<"10个学生的成绩为"<<endl;
	cout<<"序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点"<<endl;
	cout<<"=================================================================="<<endl;

	cout<<setiosflags(ios::left);
	for(ps=stu;ps-stu<num;ps++)
	{
		cout<<resetiosflags(ios::fixed);
		cout<<setprecision(-1);
		
		cout<<setw(5)<<(ps-stu)+1;
		cout<<setw(8)<<ps->no;
		cout<<setw(9)<<ps->name;
		for(pc=ps->score;pc-(ps->score)<3;pc++)
		{
			cout<<setw(6)<<pc->gpa;
			cout<<setw(6)<<pc->weight;
		}
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(3);
		cout<<setw(6)<<ps->wgpa_sum<<endl;
	}
	
}

/***************************************************************************
  函数名称：
  功    能：输出绩点最高的学生（可能有并列）
  输入参数：
  返 回 值：
  说    明：不允许出现宏定义N
***************************************************************************/
void output_max(struct student* stu, int num)
{
	/* 本函数中允许定义各种类型的简单变量，但不允许定义数组 */
	float maxval=-3;
	for(int i=0;i<num;i++)
	{
		if(stu[i].wgpa_sum>maxval)
		{
			maxval=stu[i].wgpa_sum;
		}
	}
	

	cout<<endl;
	cout<<"10个学生的成绩为"<<endl;
	cout<<"序号 学号    姓名     绩点1 权重1 绩点2 权重2 绩点3 权重3 平均绩点"<<endl;
	cout<<"=================================================================="<<endl;
	cout<<setiosflags(ios::left);
	for(int i=0;i<num;i++)
	{
		if(stu[i].wgpa_sum!=maxval)
			continue;
		cout<<resetiosflags(ios::fixed);
		cout<<setprecision(-1);
		
		cout<<setw(5)<<i+1;
		cout<<setw(8)<<stu[i].no;
		cout<<setw(9)<<stu[i].name;
		for(int j=0;j<3;j++)
		{
			cout<<setw(6)<<stu[i].score[j].gpa;
			cout<<setw(6)<<stu[i].score[j].weight;
			
		}
		cout<<setiosflags(ios::fixed);
		cout<<setprecision(3);
		cout<<setw(6)<<stu[i].wgpa_sum<<endl;
	}
	//cout<<endl;
}

/***************************************************************************
  函数名称：
  功    能：
  输入参数：
  返 回 值：
  说    明：main函数不准动
***************************************************************************/
int main()
{
	struct student stu[N];

	input(stu, 10);		//输入10个学生的信息
	output_base(stu, 10);	//输出10个学生的基本信息
	output_max(stu, 10);	//输出最高（可能有多个）
	
	return 0;
}

/*
测试数据，复制到cmd即可，姓名随机抓取，无任何特殊含义（测试时，不限于这一组）

*/
