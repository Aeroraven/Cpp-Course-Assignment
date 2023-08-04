#include <iostream>
#include <iomanip>
#include <conio.h>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "hanoi.h"
#include "cmd_console_tools.h"
using namespace std;
/* ----------------------------------------------------------------------------------

     本文件功能：
    1、存放被 hanoi_main.cpp 中根据菜单返回值调用的各菜单项对应的执行函数

     本文件要求：
    1、不允许定义外部全局变量（const及#define不在限制范围内）
    2、允许定义静态全局变量（具体需要的数量不要超过文档显示，全局变量的使用准则是：少用、慎用、能不用尽量不用）
    3、静态局部变量的数量不限制，但使用准则也是：少用、慎用、能不用尽量不用
    4、按需加入系统头文件、自定义头文件、命名空间等

   ----------------------------------------------------------------------------------- */

   /* 允许的全局变量 */
static int hanoi_steps; //总移动步数
static int hanoi_delay; //延时设置
static int hanoi_stack[HANOI_SOL_COLUMNS][HANOI_SOL_STACKMAX]; //圆柱上现有圆盘的编号
static int hanoi_stack_top[HANOI_SOL_COLUMNS];//圆柱上现有圆盘数量

  /* 函数声明 */
void hanoi_sol_argument_input(int* p_levels, char* p_src, char* p_dst, int* p_speed, int game_flag);
void hanoi_sol_solve(int level, char src, char tmp, char dst, int opt);
void hanoi_sol_move(int level, char src, char dst, int opt);
void hanoi_sol_horizontal_output(int level, char src, char dst, int opt, int initial);
void hanoi_sol_vertical_output(char src, char dst, int opt, int extraopt);
void hanoi_sol_press_enter(int show_tips);
void hanoi_sol_stack_initialization(int levels, char src);
void hanoi_sol_delay(int delay);
void hanoi_sol_draw_columns();
void hanoi_sol_draw_disk(char col, int size, int level);
void hanoi_sol_draw_disk_move(char src, char dst, int size);
bool hanoi_sol_game_move_check(char src, char dst);
bool hanoi_sol_game_complete_check(char dst, int levels);

/***************************************************************************
  函数名称：hanoi_sol_cin_clear
  功    能：清空输入缓冲区并清除cin的输入标记
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_cin_clear()
{
    cin.clear();
    cin.ignore(0x7fffffff, '\n');
}
/***************************************************************************
  函数名称：hanoi_sol_uprchr
  功    能：将一个字符转换为英文大写
  输入参数：char x	要进行转换的字符
  返 回 值：char 转换后的字符
  说    明：
***************************************************************************/
char hanoi_sol_uprchr(char x)
{
    return(x >= 'a' && x <= 'z') ? (x - 'a' + 'A') : x;
}
/***************************************************************************
  函数名称：hanoi_sol_get_tmp_column
  功    能：获得汉诺塔的中间柱(临时柱)
  输入参数：char src 起始柱编号
            char dst 目标柱编号
  返 回 值：char 中间柱编号
  说    明：
***************************************************************************/
char hanoi_sol_get_tmp_column(char src, char dst)
{
    if (src + dst == 'A' + 'C')
        return 'B';
    else if (src + dst == 'A' + 'B')
        return 'C';
    else
        return 'A';
}
/***************************************************************************
  函数名称：hanoi_sol_argument_input
  功    能：（输入处理）用于处理层数、起始柱、目标柱和延迟设置等的输入
  输入参数：int* p_levels	存储层数变量的指针
            char* p_src		存储起始柱变量的指针
            char* p_dst		存储目标柱子的变量的指针
            char* p_speed	存储延迟设置的变量的指针
            int game_flag	标记该输入是否为游戏版输入
  返 回 值：
  说    明：1.如果不需要进行延迟设置，可以设p_speed为NULL
            2.在game_flag为真时，仅有*p_src和*p_dst两个变量会被修改
***************************************************************************/
void hanoi_sol_argument_input(int* p_levels, char* p_src, char* p_dst, int* p_speed, int game_flag)
{
    int buffer[200], cht, i = 0;
    if (game_flag)
    {
        cct_setcursor(CURSOR_VISIBLE_NORMAL);
        while (1)
        {
            cct_gotoxy(0, OFFSET_GAME_INPUT_TIP_Y);
            for (i = 0; i < HANOI_GAME_GETCHARS+61; i++)
                cout << " ";
            cct_gotoxy(0, OFFSET_GAME_INPUT_TIP_Y);
            cout << "请输入移动的柱号(命令形式：AC=A顶端的盘子移动到C，Q=退出) ：";
            for (i = 0; i < HANOI_GAME_GETCHARS; i++)
            {
                cht = _getch();
                if (cht == 13)
                    break;
                if (cht < 33 || cht> 126)
                {
                    i--;
                    if (cht == 224 || cht == 0)
                        cht = _getch();
                    if (cht == '\b'&& i != -1)
                    {
                        i--;
                        cct_gotoxy(61+i, OFFSET_GAME_INPUT_TIP_Y );
                        cout << "  ";
                        cct_gotoxy(61+i, OFFSET_GAME_INPUT_TIP_Y);
                    }
                    continue;
                }
                cout << static_cast<char>(cht);
                buffer[i] = hanoi_sol_uprchr(static_cast<char>(cht));
            }
            if (i == 1 && buffer[0] == 'Q')
            {
                *p_src = *p_dst = 'q';
                cct_setcursor(CURSOR_INVISIBLE);
                return;
            }
            if (i == 2 && buffer[0] != buffer[1] && buffer[0] >= 'A' && buffer[0] <= 'C' && buffer[1] >= 'A' && buffer[1] <= 'C')
            {
                *p_src = static_cast<char>(buffer[0]);
                *p_dst = static_cast<char>(buffer[1]);
                cct_setcursor(CURSOR_INVISIBLE);
                return;
            }
        }
    }
    cout << endl << endl << endl;
    while (1)//输入层次
    {
        cout << "请输入汉诺塔的层数(1-10)：" << endl;
        cin >> *p_levels;
        if (cin.fail())
        {
            hanoi_sol_cin_clear();
            continue;
        }
        if (*p_levels > 10 || *p_levels < 1)
            continue;
        break;
    }
    while (1) //输入起始层
    {
        cout << "请输入起始柱(A-C)：" << endl;
        cin >> *p_src;
        if (cin.fail())
        {
            hanoi_sol_cin_clear();
            continue;
        }
        hanoi_sol_cin_clear();
        *p_src = hanoi_sol_uprchr(*p_src);
        if (*p_src != 'A' && *p_src != 'B' && *p_src != 'C')
            continue;
        break;
    }
    while (1) //输入目标层
    {
        cout << "请输入目标柱(A-C)：" << endl;
        cin >> *p_dst;
        if (cin.fail())
        {
            hanoi_sol_cin_clear();
            continue;
        }
        hanoi_sol_cin_clear();
        *p_dst = hanoi_sol_uprchr(*p_dst);
       
        if (*p_dst != 'A' && *p_dst != 'B' && *p_dst != 'C')
            continue;
        if (*p_dst == *p_src)
        {
            cout << "目标柱(" << *p_src << ")不能与起始柱(" << *p_dst << ")相同" << endl;
            continue;
        }
        break;
    }
    if (p_speed != NULL) //输入速度
    {
        while (1)
        {
            cout << "请输入移动速度(0-5：0-按回车单步演示 1-延时最长 5-延时最短) ";
            cin >> *p_speed;
            if (cin.fail())
            {
                hanoi_sol_cin_clear();
                continue;
            }
            if (*p_speed > 5 || *p_speed < 0)
                continue;
            break;
        }
    }
    
}
/***************************************************************************
  函数名称：hanoi_sol_solve
  功    能：（递归函数）汉诺塔的递归求解函数
  输入参数：int level	当前移动盘子的层次(大小)
            char src	当前的起始柱
            char dst	当前的目标柱
            char tmp	当前的中间柱
            char opt	选择的菜单选项(处理输出)
  返 回 值：
  说    明：level 以1作为最小盘
***************************************************************************/
void hanoi_sol_solve(int level, char src, char tmp, char dst, int opt)
{
    if (level == 0)
        return;
    hanoi_sol_solve(level - 1, src, dst, tmp, opt);
    hanoi_sol_move(level, src, dst, opt);
    hanoi_sol_solve(level - 1, tmp, src, dst, opt);
}
/***************************************************************************
  函数名称：hanoi_sol_move
  功    能：处理盘子的移动，并根据选项调用相应输出
  输入参数：int level	移动的盘子层次(大小)
            char src	移动盘子的起始柱
            char dst	移动盘子的目标柱
            int opt		选择的菜单项，据此调用不同输出
  返 回 值：
  说    明：1. 在选项为3、4、7、8时会对栈进行操作
            2. 在选项为4、8时会进行横向输出
            3. 在选项为7、8时会进行移动过程的绘制
            4. 在游戏版中调用该选项，可以向opt传入8
***************************************************************************/
void hanoi_sol_move(int level, char src, char dst, int opt)
{
    hanoi_steps++;
    int fetched = 0;
    if (opt == 3 || opt == 4 || opt == 7 || opt == 8)
    {
        fetched = hanoi_stack[src - 'A'][--hanoi_stack_top[src - 'A']];
        hanoi_stack[dst - 'A'][hanoi_stack_top[dst - 'A']++] = fetched;
    }
    if (opt == 4 || opt == 8)
        hanoi_sol_vertical_output(src, dst, opt, 0);
    hanoi_sol_horizontal_output(level, src, dst, opt, 0);
    if (opt == 7 || opt == 8)
        hanoi_sol_draw_disk_move(src, dst, fetched);
}
/***************************************************************************
  函数名称：hanoi_sol_delay
  功    能：根据选项进行延迟、回车提示
  输入参数：int delay	延迟设置
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_delay(int delay)
{
    if (delay == 0)
        hanoi_sol_press_enter(false);
    else
        Sleep((5 - delay) * 50 + 0);
}
/***************************************************************************
  函数名称：hanoi_sol_horizontal_output
  功    能：汉诺塔横向输出
  输入参数：int level	当前移动盘的级别(大小)
            char src	当前移动的起始柱
            char dst	当前移动的目标柱
            int opt		选择的菜单项(进行不同格式的输出)
            int initial	标记输出是否为初始状态
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_horizontal_output(int level, char src, char dst, int opt, int initial) {
    switch (opt)
    {
        case 1: //基本解
            cout << level << "# " << src << "---->" << dst << endl;
            break;
        case 2: //基本解(步数记录)
            cout << "第" << setw(4) << hanoi_steps << " 步(" << setw(2) << level << "#: " << src << "-->" << dst << ")" << endl;
            break;
    }
    int added_offset = 0;
    if (opt == 8)
    {
        added_offset = OFFSET_ADDED;
    }
    if (opt == 3 || opt == 4 || opt == 8)//横向输出
    {
        if (opt == 4 || opt == 8)
            cct_gotoxy(0,OFFSET_STEP_DETAIL_Y + added_offset);
        if (initial)
            cout << "初始: ";
        else
            cout << "第" << setw(4) << hanoi_steps << " 步(" << setw(2) << level << "#: " << src << "-->" << dst << ") ";
        for (int i = 0; i < HANOI_SOL_COLUMNS; i++)
        {
            cout << " " << static_cast<char>('A' + i) << ":";
            for (int j = 0; j < hanoi_stack_top[i]; j++)
                cout << setw(2) << hanoi_stack[i][j];
            for (int j = hanoi_stack_top[i]; j < HANOI_SOL_STACKMAX; j++)
                cout << "  ";
        }
        cout << endl;
        if (opt == 4)
            hanoi_sol_delay(hanoi_delay);
    }
}
/***************************************************************************
  函数名称：hanoi_sol_vertical_output
  功    能：汉诺塔纵向输出
  输入参数：char src	 当前移动的起始柱
            char dst	 当前移动的目标柱
            int opt		 选择的菜单项(进行不同格式的输出)
            int extraopt 标记输出是否为初始状态
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_vertical_output(char src, char dst, int opt, int extra_opt)
{
    int added_offset = 0;
    if (opt == 8||opt==9)
        added_offset = OFFSET_ADDED;
    if (extra_opt == 1) //初始化打印
    {
        //打印等号和标签
        cct_gotoxy(OFFSET_EQUIV_SIGNS_X,OFFSET_EQUIV_SIGNS_Y + added_offset );
        cout << "=========================";
        cct_gotoxy(OFFSET_SIGN_A_X,OFFSET_SIGN_Y + added_offset);
        cout << "A";
        cct_gotoxy(OFFSET_SIGN_B_X,OFFSET_SIGN_Y + added_offset );
        cout << "B";
        cct_gotoxy(OFFSET_SIGN_C_X,OFFSET_SIGN_Y + added_offset );
        cout << "C";

        for (int t = 0; t < HANOI_SOL_COLUMNS; t++)
        {
            for (int i = 0, j = OFFSET_EQUIV_SIGNS_Y - 1; i < hanoi_stack_top[t]; i++, j--)
            {
                cct_gotoxy(OFFSET_SIGN_A_X+t*OFFSET_SIGN_ADD_X - 1, j + added_offset);
                cout << setw(2) << hanoi_stack[t][i];
            }
        }
    }
    else //移动后修改
    {
        //从原始柱上消除栈顶
        for (int i = 0; i < HANOI_SOL_COLUMNS; i++)
        {
            if (src == static_cast<char>('A'+i))
            {
                cct_gotoxy(OFFSET_SIGN_A_X+i * OFFSET_SIGN_ADD_X - 1, OFFSET_EQUIV_SIGNS_Y - hanoi_stack_top[i] - 1 + added_offset);
                cout << "  ";
            }
        }
        //添加现有栈顶
        for (int i = 0; i < HANOI_SOL_COLUMNS; i++)
        {
            if (dst == static_cast<char>('A' + i))
            {
                cct_gotoxy(OFFSET_SIGN_A_X+ i * OFFSET_SIGN_ADD_X - 1, OFFSET_EQUIV_SIGNS_Y - hanoi_stack_top[i] + added_offset);
                cout << setw(2) << hanoi_stack[i][hanoi_stack_top[i] - 1];
            }
        }
    }
}
/***************************************************************************
  函数名称：hanoi_sol_type_1_2_3_4
  功    能：功能1、2、3、4
  输入参数：int  opt 选项1至4
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_type_1_2_3_4(int opt)//选项1,2,3,4
{
    hanoi_steps = 0;
    int levels, speed = 0;
    char src, dst, tmp;
    if(opt!=4)
        hanoi_sol_argument_input(&levels, &src, &dst, NULL, 0);
    else
        hanoi_sol_argument_input(&levels, &src, &dst, &speed, 0);
    if (opt == 4)
    {
        cct_cls();
        cout << "从 " << src << " 移动到 " << dst << "，共 " << levels << " 层，延时设置为 " << speed;
        hanoi_delay = speed;
    }
    tmp = hanoi_sol_get_tmp_column(src, dst);
    hanoi_sol_stack_initialization(levels, src);
    if (opt == 4)
    {
        hanoi_sol_vertical_output(src, dst, 4, 1);
        hanoi_sol_horizontal_output(levels, src, dst, 4, 1);
    }
    hanoi_sol_solve(levels, src, tmp, dst, opt);
    cout << endl;
    hanoi_sol_press_enter(true);
}

void hanoi_sol_press_enter(int show_tips)
{
    if (show_tips)
        cout << "按回车键继续";
    while (1)
    {
        if (_getch() == 13)
            break;
    }
}
/***************************************************************************
  函数名称：hanoi_sol_stack_initialization
  功    能：初始化汉诺塔的内部数组
  输入参数：int level 初始化的层数
            char src 初始化的柱子
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_stack_initialization(int levels, char src)
{
    for (int i = 0; i < HANOI_SOL_COLUMNS; i++)
        hanoi_stack_top[i] = 0;
    for (int i = levels; i >= 1; i--)
        hanoi_stack[src - 'A'][hanoi_stack_top[src - 'A']++] = i;
}
/***************************************************************************
  函数名称：void hanoi_sol_draw_columns
  功    能：绘制汉诺塔的柱子-图形版
  输入参数：
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_draw_columns()
{
    cct_setcursor(CURSOR_INVISIBLE);
    cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);
    for (int t = 0; t < HANOI_SOL_COLUMNS; t++)
    {
        cct_gotoxy(t * (GRAPHIC_BASE_WIDTH + GRAPHIC_BASE_DISTANCE) + GRAPHIC_OFFSET_BASE_A, GRAPHIC_BASE_Y);
        for (int i = 0; i < GRAPHIC_BASE_WIDTH; i++)
            cout << " ";
        Sleep(DELAY_OPTION_5);
    }
    for (int i = 0; i < GRAPHIC_COLUMN_HEIGHT; i++)
    {
        for (int j = 0; j < HANOI_SOL_COLUMNS; j++)
        {
            cct_gotoxy(j * (GRAPHIC_BASE_WIDTH + GRAPHIC_BASE_DISTANCE) + GRAPHIC_OFFSET_BASE_A + GRAPHIC_OFFSET_COLUMN, GRAPHIC_BASE_Y - i - 1);
            cout << " ";
            Sleep(DELAY_OPTION_5);
        }
    }
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);

}
//选项5
void hanoi_sol_type_5()
{
    cct_cls();
    hanoi_sol_draw_columns();
    cct_gotoxy(0, GRAPHIC_PRESSENTER_Y);
    hanoi_sol_press_enter(true);
}
/***************************************************************************
  函数名称：void hanoi_sol_draw_columns
  功    能：绘制汉诺塔的盘子-图形版
  输入参数：char col	盘子所在柱
            int size	盘子大小
            int level	盘子所在层次
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_draw_disk(char col, int size, int level)
{
    int offset_x = (col - 'A') * (GRAPHIC_BASE_WIDTH + GRAPHIC_BASE_DISTANCE) + GRAPHIC_OFFSET_BASE_A + GRAPHIC_OFFSET_COLUMN;
    int offset_y = GRAPHIC_BASE_Y - 1;
    offset_x -= size;
    offset_y -= level;
    cct_gotoxy(offset_x, offset_y);
    cct_setcolor(size, size);
    for (int i = 0; i < 2 * size + 1; i++)
        cout << " ";
    cct_setcolor(COLOR_BLACK, COLOR_HWHITE);
}


/***************************************************************************
  函数名称：hanoi_sol_draw_disk_move
  功    能：移动汉诺塔的盘子-图形版
  输入参数：char src	源柱
            char dst	目标柱
            int size	盘子大小
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_draw_disk_move(char src, char dst, int size)
{
    int cur_x, cur_y, dst_x;
    int dst_y;
    cur_x = (src - 'A') * (GRAPHIC_BASE_WIDTH + GRAPHIC_BASE_DISTANCE) + GRAPHIC_OFFSET_BASE_A + GRAPHIC_OFFSET_COLUMN;
    dst_x = (dst - 'A') * (GRAPHIC_BASE_WIDTH + GRAPHIC_BASE_DISTANCE) + GRAPHIC_OFFSET_BASE_A + GRAPHIC_OFFSET_COLUMN;
    cur_y = GRAPHIC_BASE_Y - hanoi_stack_top[src - 'A'] - 1;
    dst_y = GRAPHIC_BASE_Y - hanoi_stack_top[dst - 'A'];
    //向上移动
    for (int i = cur_y; i >= GRAHPIC_MOVE_TOP; i--)
    {
        cur_y = i;
        cct_gotoxy(cur_x - size, cur_y);
        //绘制
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(size, size);
            cout << " ";
        }
        hanoi_sol_delay(hanoi_delay);
        cct_gotoxy(cur_x - size, cur_y);
        //清除
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(COLOR_BLACK, COLOR_BLACK);
            if (j == size && i >= GRAHPIC_COLUMN_TOP)
                cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);
            cout << " ";
        }
    }
    //平移
    for (; cur_x != dst_x; (cur_x < dst_x) ? cur_x++ : cur_x--)
    {
        cct_gotoxy(cur_x - size, cur_y);
        //绘制
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(size, size);
            cout << " ";
        }
        hanoi_sol_delay(hanoi_delay);

        cct_gotoxy(cur_x - size, cur_y);
        //清除
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(COLOR_BLACK, COLOR_BLACK);
            cout << " ";
        }
    }
    //下移
    for (; cur_y <= dst_y; cur_y++)
    {
        cct_gotoxy(cur_x - size, cur_y);
        //绘制
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(size, size);
            cout << " ";
        }
        hanoi_sol_delay(hanoi_delay);
        cct_gotoxy(cur_x - size, cur_y);

        if (cur_y == dst_y)
            break;
        //清除
        for (int j = 0; j < 2 * size + 1; j++)
        {
            cct_setcolor(COLOR_BLACK, COLOR_BLACK);
            if (j == size && cur_y >= GRAHPIC_COLUMN_TOP)
                cct_setcolor(COLOR_HYELLOW, COLOR_HYELLOW);
            cout << " ";
        }
    }
    cct_setcolor(COLOR_BLACK, COLOR_WHITE);
}

/***************************************************************************
  函数名称：hanoi_sol_type_6_7_8_9
  功    能：功能6、7、8、9
  输入参数：int  opt 选项6至9
  返 回 值：
  说    明：
***************************************************************************/
void hanoi_sol_type_6_7_8_9(int opt)
{
    hanoi_steps = 0;
    //主体部分
    int levels, speed = 4;
    char src, dst, tmp, ssrc, sdst;
    if(opt==8)
        hanoi_sol_argument_input(&levels, &src, &dst, &speed, 0);
    else
        hanoi_sol_argument_input(&levels, &src, &dst, NULL, 0);
    cct_cls();
    cout << "从 " << src << " 移动到 " << dst << "，共 " << levels << " 层";
    if (opt == 8)
        cout << "，延时设置为 " << speed;
    hanoi_delay = speed = ((opt == 8) ? speed : 4 + (opt == 9));
    tmp = hanoi_sol_get_tmp_column(src, dst);
    hanoi_sol_draw_columns();
    cct_setcursor(CURSOR_INVISIBLE);
    hanoi_sol_stack_initialization(levels, src);
    if (opt == 8||opt==9)
    {
        hanoi_sol_vertical_output(src, dst, 8, 1);
        hanoi_sol_horizontal_output(levels, src, dst, 8, 1);
    }
    //画盘子
    for (int i = 0; i < hanoi_stack_top[src - 'A']; i++)
    {
        hanoi_sol_draw_disk(src, hanoi_stack[src - 'A'][i], i);
        Sleep(DELAY_OPTION_6);
    }
    Sleep(DELAY_OPTION_7);
    //求解和移动
    if (opt == 8)
        hanoi_sol_solve(levels, src, tmp, dst, opt);	
    if (opt == 7)
    {
        srand(static_cast<unsigned int>(time(0)));
        int x = rand() % 2;
        if(x)
            hanoi_sol_move(1, src, tmp, 7);//第一次从源柱移到中间柱子
        else
            hanoi_sol_move(1, src, dst, 7);//第一次从源柱移到目标柱子
    }
        
    if (opt == 9)
    {
        while (1)
        {
            hanoi_sol_argument_input(NULL, &ssrc, &sdst, NULL, 1);
            if (ssrc == 'q')
                break;
            if (hanoi_sol_game_move_check(ssrc, sdst))
            {
                if (hanoi_stack_top[ssrc - 'A'] > 0) //处理 Intellisense
                    hanoi_sol_move(hanoi_stack[ssrc - 'A'][hanoi_stack_top[ssrc - 'A'] - 1], ssrc, sdst, 8);
            }
            if (hanoi_sol_game_complete_check(dst, levels))
                break;
        }
    }
    cct_gotoxy(0, GRAPHIC_PRESSENTER_Y);
    cct_setcursor(CURSOR_VISIBLE_NORMAL);
    hanoi_sol_press_enter(true);
}

/***************************************************************************
  函数名称：hanoi_sol_game_move_check
  功    能：移动合法性检查-游戏版
  输入参数：char src	源柱
            char dst	目标柱
  返 回 值：bool		是否合法
  说    明：
***************************************************************************/
bool hanoi_sol_game_move_check(char src, char dst)
{
    if (hanoi_stack_top[src - 'A'] == 0)
    {
        cct_gotoxy(0, OFFSET_GAME_INPUT_TIP2_Y);
        cout << "源柱为空!";
        Sleep(DELAY_GAME_INPUT_TIP);
        cct_gotoxy(0, OFFSET_GAME_INPUT_TIP2_Y);
        cout << "                         ";
        return false;
    }
    if (hanoi_stack_top[dst - 'A'] != 0)
    {
        if (hanoi_stack[src - 'A'][hanoi_stack_top[src - 'A'] - 1] > hanoi_stack[dst - 'A'][hanoi_stack_top[dst - 'A'] - 1])
        {
            cct_gotoxy(0, OFFSET_GAME_INPUT_TIP2_Y);
            cout << "大盘压小盘，非法移动!";
            Sleep(DELAY_GAME_INPUT_TIP);
            cct_gotoxy(0, OFFSET_GAME_INPUT_TIP2_Y);
            cout << "                         ";
            return false;
        }
    }
    return true;
}
/***************************************************************************
  函数名称：hanoi_sol_game_move_check
  功    能：游戏结束检查-游戏版
  输入参数：char dst	最终目标柱
            int levels	总层数
  返 回 值：
  说    明：
***************************************************************************/
bool hanoi_sol_game_complete_check(char dst, int levels)
{
    if (hanoi_stack_top[dst - 'A'] == levels)
    {
        cct_gotoxy(0, OFFSET_GAME_INPUT_TIP2_Y);
        cout << "游戏结束!!!!!";
        return true;
    }
    return false;
}