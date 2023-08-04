#pragma once

#define CONSOLE_W 80				//控制台宽度

#define GAME_INPUT_ROW_MAX 8		//矩阵最大行数
#define GAME_INPUT_ROW_MIN 3		//矩阵最小行数

#define GAME_INPUT_COL_MAX 10		//矩阵最大列数
#define GAME_INPUT_COL_MIN 3		//矩阵最小列数

#define GAME_INPUT_GOAL_MIN 5		//最小初始游戏目标
#define GAME_INPUT_GOAL_MAX 20		//最大游戏初始目标

#define GAME_INPUT_ROW_CLR 80				//行清空字符数
#define GAME_INPUT_CIN_IGNORE 0x7fffffff	//cin忽略字符数

#define GAME_DELAY_BORDER_DRW 20		//边框绘制时间间隔
#define GAME_DELAY 30					//游戏时间间隔

#define GAME_BASE_PRINT_DFFAULT 0			//控制台方式：默认打印方式
#define GAME_BASE_PRINT_FIND_RESULT 1		//控制台方式：标出查找结果
#define GAME_BASE_PRINT_COLORED_RESULT 2	//控制台方式：高亮查找结果

#define GAME_CON_CW 3	//图形版：格子宽度
#define GAME_CON_CH 3	//图形版：格子高度

#define GAME_CON_LEFT 0		//图形版：按下左箭头
#define GAME_CON_RIGHT 1	//图形版：按下右箭头
#define GAME_CON_UP 2		//图形版：按下上箭头
#define GAME_CON_DOWN 3		//图形版：按下下箭头
#define GAME_CON_ENTER 4	//图形版：按下回车
#define GAME_CON_QUIT 5		//图形版：退出

#define GAME_CON_BLINK_CNT 4		//图像版：格子闪烁次数
#define GAME_CON_BLINK_DELAY 100		//图形版：格子闪烁间隔
#define GAME_CON_DROP_DELAY 20		//图形版：下落间隔
#define GAME_CON_FILL_DELAY 60		//图形版：填充间隔
#define GAME_MENU_OPTS 10			//菜单选项数
#define GAME_CELLWEIGHT 3		//格子分数权重
#define OPT_ITERATIVE 1			//选项1：非递归
#define OPT_RECURSIVE 2			//选项2：递归
#define OPT_FIRST_OP 3			//选项3：第一次操作
#define OPT_COMPLETE 4			//选项4：控制台完整
#define OPT_CON_DRAW1 5			//选项5：绘制边框无间隔
#define OPT_CON_DRAW2 6			//选项6：绘制边框带间隔
#define OPT_CON_FIRST 7			//选项7：图形版选择格子
#define OPT_CON_SINGLE 8		//选项8：图形版单次合成
#define OPT_CON_FULL 9			//选项9：图形版完整版

#define OPT_SEL_HSELECT 2		//图形版：高亮选中块
#define OPT_SEL_SELECT 1		//图形版：高亮标记块
#define OPT_SEL_DEFAULT 0		//图形版：不高亮

#define OPT_DRW_HIGHLIGHT 1		//图形版绘制：高亮
#define OPT_DRW_ALL 0			//图形版绘制：所有格子
#define OPT_DRW_FADE 2			//图形版绘制：取消高亮块

#define FLAGGED 1000			//格子标记


void game_base_options(int opt);

void game_con_options(int type);

void game_tool_input(int* irow, int* icol, int* igoal);
void game_tool_initial_gen(int mat[][GAME_INPUT_COL_MAX], int r, int c);
int game_tool_strlen(const char* s);
char game_tool_uprchr(char x);
void game_tool_swap(int* x, int* y);
int game_tool_rand_gen(int maxval);
int game_tool_getmax(int mat[][GAME_INPUT_COL_MAX], int r, int c);
int game_tool_getch();
void game_tool_wait_continue(const char* t, int key = 13, int skip = 0, int clr = 1,int req_endl=1);
void game_tool_input_end();
void game_tool_find_iterative(int mat[][GAME_INPUT_COL_MAX], int srow, int irow, int icol);
int game_tool_combine(int mat[][GAME_INPUT_COL_MAX], int srow, int scol, int irow, int icol);
void game_tool_remove_flag(int mat[][GAME_INPUT_COL_MAX], int srow, int scol);
int game_tool_check_adjacent(int mat[][GAME_INPUT_COL_MAX], int r, int c, int cr, int cc);
int game_tool_finish_check(int mat[][GAME_INPUT_COL_MAX], int r, int c);

void game_tool_fill_tiles(int mat[][GAME_INPUT_COL_MAX], int r, int c, int isConsole);
void game_tool_drop_tiles(int mat[][GAME_INPUT_COL_MAX], int r, int c, int isConsole);

//为尽可能实现重用加入的声明
void game_con_draw_tile(int val, int cx, int cy, int type = OPT_SEL_DEFAULT);