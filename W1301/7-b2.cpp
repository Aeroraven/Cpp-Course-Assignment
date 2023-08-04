#include <iostream>
#include <cstdio>
#include <conio.h>
#include <iomanip>
using namespace std;
struct KFC
{
    char id;
    const char* name;
    double price;
};
struct SPECIAL
{
    const char* set;
    const char* name;
    double price;
};
char chrupr(char x)
{
    return (x <= 'z' && x >= 'a') ? (x - 'a' + 'A') : x;
}
void print_detail(const KFC* menu_list,const char* order_info,int* recv)
{

    int dish[256];
    
    int first_flag = 1;
    for (int i = 0; i < 256; i++)
        dish[i] = 0;
        
    for (const char* k = order_info; *k; k++)
    {
        dish[static_cast<int>(chrupr(*k))]++;
    }
    for (int i = 0; i < 256; i++)
    {
        if (dish[i])
        {
            for (const KFC* k = menu_list; (*k).id; k++)
            {
                if (k->id == chrupr(static_cast<char>(i)))
                {
                    if (first_flag)
                    {
                        first_flag = 0;
                    }
                    else
                    {
                        cout << "+";
                    }
                    cout << k->name;
                }
            }
            if (dish[i] - 1)
            {
                cout << "*" << dish[i];
            }

        }
    }
    if (recv != NULL)
    {
        for (int i = 0; i < 256; i++)
        {
            recv[i] = dish[i];
            
        }
    }
}
void print_order(const KFC* menu_list, const SPECIAL* spec_list, const char* order)
{
    int dish[256];
    int spec_req[256];
    cout << "您的点餐=";
    print_detail(menu_list, order, dish);
    double price = 0;
    //处理优惠
    if (1)
    {
        const SPECIAL* i = spec_list;
        do
        {
            
            for (int j = 0; j < 256; j++)
                spec_req[j] = 0;
            for (const char* j = i->set; *j; j++)
                spec_req[static_cast<int>(*j)]++;
            while (1)
            {
                int satisfied = 1;
                for (int j = 0; j < 256; j++)
                {
                    if (dish[j] < spec_req[j])
                    {
                        satisfied = 0;
                        break;
                    }
                }
                if (!satisfied)
                    break;
                price += i->price;
                for (int j = 0; j < 256; j++)
                {
                    dish[j] -= spec_req[j];
                }
            }

        } while ((++i)->name);
    }
    //处理单点
    if (1)
    {
        const KFC* i = menu_list;
        do
        {
            price += dish[static_cast<int>(i->id)] * i->price;
        } while ((++i)->id);
    }
    cout << endl;
    //完成
    cout << "共计：" << price << "元" <<endl;
    cout << "点单完成，按任意键继续." << endl;
    while (1)
    {
        int ch = _getch();
        if (ch != 0 && ch != 224)
            break;
    }
}
void print_menu(const KFC* menu_list,const SPECIAL* spec_list)
{
    //打印标题
    for (int i = 0; i < 61; i++)
        cout << "=";
    cout << endl;
    cout << setiosflags(ios::right);
    cout << setw(38) << "KFC 2021春季菜单" << endl;
    cout << resetiosflags(ios::right);
    for (int i = 0; i < 61; i++)
        cout << "=";
    cout << endl;
    
    //打印菜单
    cout << setiosflags(ios::left);
    if (1)
    {
        const KFC* i = menu_list;
        do
        {
            cout << " " << i->id << " ";
            cout << setw(20) << i->name;
            cout << setw(7) << i->price;
            if ((i - menu_list) % 2 == 0)
            {
                cout << "|  ";
            }
            else
            {
                cout << endl;
            }
        } while ((++i)->id);
    }
    cout << endl;

    //打印优惠信息
    cout << "【优惠信息】：" << endl;
    if (1)
    {
        const SPECIAL* j = spec_list;
        do
        {
            cout << j->name << "=";
            print_detail(menu_list, j->set, NULL);
            cout << "=" << (j->price) << endl;
        } while ((++j)->set != NULL);
    }
    //打印输入规则
    cout << endl;
    const char* example1 = "ANV";
    const char* example2 = "akaak";
    cout << "【输入规则说明】：" << endl;
    cout << example1 << "=";
    print_detail(menu_list, example1, NULL);
    cout << " / ";
    cout << example2 << "=";
    print_detail(menu_list, example2, NULL);
    cout << endl;
    cout << "字母不分大小写，不限顺序，单独输入0则退出程序";
    cout << endl;
    cout << endl;

}
int main()
{
    const struct KFC list[] = {
    {'A', "香辣鸡腿堡",         18},
    {'B', "劲脆鸡腿堡",         18},
    {'C', "新奥尔良烤鸡腿堡",   18.5},
    {'D', "鸡肉火腿帕尼尼",   14.0},
    {'E', "老北京鸡肉卷",       16.5},
    {'F', "川辣嫩牛卷",     19},
    {'G', "吮指原味鸡(1块)",   11.5},
    {'H', "热辣薯片脆皮鸡",   12.5},
    {'I', "新奥尔良烤翅(2块)", 12},
    {'J', "劲爆鸡米花",         10.5},
    {'K', "香辣鸡翅(2块)",     11.0},
    {'L', "热辣香骨鸡(3块)",     11.0},
    {'M', "鲜蔬色拉",           12.5},
    {'N', "薯条(小)",           8},
    {'O', "薯条(中)",           11},
    {'P', "薯条(大)",           13},
    {'Q', "芙蓉蔬荟汤",         8},
    {'R', "原味花筒冰激凌",     6},
    {'S', "醇香土豆泥",         6.5},
    {'T', "香甜粟米棒",         8.0},
    {'U', "葡式蛋挞",           7.5},
    {'V', "百事可乐(小)",       7.0},
    {'W', "百事可乐(中)",       9.5},
    {'X', "百事可乐(大)",       11.5},
    {'Y', "九珍果汁饮料",       12.0},
    {'Z', "纯纯玉米饮",         11.0},
    {'\0', NULL,                0}
    };

    const struct SPECIAL special[] = {
        //	{"ANV", "香辣鸡腿堡工作日午餐",    22}, //如果有需要，放开此项，注释掉下一行的“BMV”优惠，观察优惠菜单是否发生了变化
            {"BMV", "劲脆鸡腿堡超值套餐",    24},
            {"ABCGGIIKKOUWWW", "超值全家桶", 100},
            {"KIIRRJUWW", "缤纷小吃桶",  65},
            {"JJ","劲爆鸡米花(2份小)",      9.5},
            {NULL, NULL, 0}
    };
    system("mode con cols=120 lines=35");
    char order[8292];
    while (1)
    {
        int fail_flag = 0;
        system("cls");
        print_menu(list, special);
        cout << "请点单:";
        cin.getline(order, 8290);
        cin.clear();
        if (!*order)
        {
            continue;
        }
        if (*order == '0' && order[1] == 0)
            return 0;
        for (char* i = order; *i; i++)
        {
            if (!(chrupr(*i) >= 'A' && chrupr(*i) <= 'Z'))
            {
                fail_flag = 1;
                cout << "输入错误，按任意键继续." << endl;
                while (1)
                {
                    int ch = _getch();
                    if (ch != 0 && ch != 224)
                        break;
                }
                break;
            }
            if (fail_flag)
                break;
        }
        if (fail_flag)
            continue;
        print_order(list, special, order);
    }
    
    return 0;
}
