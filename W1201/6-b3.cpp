#include <iostream>
using namespace std;

int main()
{
    char str[33];
    unsigned int ans = 0u;
    cout << "请输入一个0/1组成的字符串，长度不超过32" << endl;
    cin >> str;
    for (char* i = str; *i != '\0'; i++)
    {
        ans = ans * 2u + (*i - '0');
    }
    cout << ans << endl;
    return 0;
}