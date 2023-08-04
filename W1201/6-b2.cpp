#include<iostream>
using namespace std;

bool is_pal(char* s)
{
    if (*s == '\0'||*s=='\n')
        return true;
    char* p = s, * i = s;
    while (*p&&*p!='\n')
    {
        p++;
    }
    p--;
    for (; *i != '\0'&&*i!='\n'; p--, i++)
    {
        if (*i != *p)
            return false;
    }
    return true;
}

int main()
{
    char str[81];
    cout << "请输入一个长度小于80的字符串（回文串）" << endl;
    fgets(str, 81, stdin);
    if (is_pal(str))
    {
        cout << "yes";
    }
    else
    {
        cout << "no";
    }
    cout << endl;
    return 0;
}