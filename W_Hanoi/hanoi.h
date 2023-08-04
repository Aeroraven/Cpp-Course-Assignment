#pragma once

/* ------------------------------------------------------------------------------------------------------

     本文件功能：
	1、为了保证 hanoi_main.cpp/hanoi_menu.cpp/hanoi_multiple_solutions.cpp 能相互访问函数的函数声明
	2、一个以上的cpp中用到的宏定义（#define）或全局只读（const）变量，个数不限
	3、可以参考 cmd_console_tools.h 的写法（认真阅读并体会）
   ------------------------------------------------------------------------------------------------------ */

/* 常量 */
#define HANOI_MENU_BORDER_CHAR_COUNT	33 //选项菜单中边框宽度
#define HANOI_SOL_COLUMNS				3  //汉诺塔的总柱子数
#define HANOI_SOL_STACKMAX				10 //汉诺塔的最大层数
#define HANOI_GAME_GETCHARS				20 //游戏版(选项9)中输入区接受的最大输入长度

/* 纵向输出定位常数 */
#define OFFSET_EQUIV_SIGNS_Y			12 //纵向输出中，底盘(等号)的Y坐标
#define OFFSET_EQUIV_SIGNS_X			9  //纵向输出中，底盘(等号)的X起始坐标
#define OFFSET_SIGN_A_X					11 //纵向输出中，底盘标识A的X坐标
#define OFFSET_SIGN_B_X					21 //纵向输出中，底盘标识B的X坐标
#define OFFSET_SIGN_C_X					31 //纵向输出中，底盘标识C的X坐标
#define OFFSET_SIGN_ADD_X				10 //纵向输出中，相邻底盘标识的X坐标差
#define OFFSET_SIGN_Y					13 //纵向输出中，底盘标识的Y坐标
#define OFFSET_STEP_DETAIL_Y			17 //纵向输出中，进行横向输出位置的Y坐标
#define OFFSET_COLUMN_TOP_Y				2  //纵向输出中，柱子顶部的Y坐标
#define OFFSET_STOP_Y					26 //纵向输出中，结束提示的Y坐标
#define OFFSET_ADDED					15 //纵向输出(选项8)中，由于图型绘制需要使纵向输出整体向下偏移的长度

/* 游戏版常数 */
#define OFFSET_GAME_INPUT_TIP_Y			35 //游戏版本中，输入提示的Y坐标
#define OFFSET_GAME_INPUT_TIP2_Y		36 //游戏版本中，输入错误或游戏完成提示的Y坐标

/* 图形输出定位 */
#define GRAPHIC_OFFSET_BASE_A			1	//图形输出中，A柱的X起始坐标
#define GRAPHIC_BASE_DISTANCE			9	//图型输出中，相邻柱子之间的间隔
#define GRAPHIC_OFFSET_COLUMN			11	//图形输出中，柱子相对于底盘左边界的偏移量
#define GRAPHIC_BASE_Y					15	//图形输出中，柱子底盘的Y坐标
#define GRAPHIC_COLUMN_HEIGHT			12	//图形输出中，柱子的高度
#define GRAPHIC_BASE_WIDTH				23	//图形输出中，底盘的宽度
#define GRAPHIC_PRESSENTER_Y			38	//图形输出中，显示按下回车继续提示的Y坐标
#define GRAHPIC_MOVE_TOP				1	//图形输出中，上移需要将盘移到的最小Y坐标
#define GRAHPIC_COLUMN_TOP				3	//图形输出中，柱子顶部的Y坐标

/* 图形输出延迟 */
#define DELAY_OPTION_5					50	 //图形输出中，绘制柱子的延迟
#define DELAY_OPTION_6					50	 //图形输出中，绘制初始盘子的延迟
#define DELAY_OPTION_7					1000 //图形输出中，绘制初始盘子完毕后的延迟
#define DELAY_GAME_INPUT_TIP			1000 //图形输出中，显示输入错误提示的时长


/* 菜单相关函数 hanoi_menu */
int hanoi_menu_select();

/* 不同选项 hanoi_multiple_solution */
void hanoi_sol_type_1_2_3_4(int opt);
void hanoi_sol_type_5();
void hanoi_sol_type_6_7_8_9(int opt);