/* 已验证 xxx 的hex文件生成*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	ifstream fs;
	char s[1001];
	char t[10];
	char h[16];
	unsigned int c, i = 0;
	cerr << "文件名以下形式均可以：" << endl;
	cerr << "    a.txt：不带路径形式" << endl;
	cerr << "    ..\\data\b.dat：相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat：绝对相对路径形式" << endl;
	cerr << "请输入文件名: ";
	cin.getline(s, 1000);
	fs.open(s, ios::binary | ios::in);
	if (fs.fail())
	{
		cout << "文件" << s << "打开失败!" << endl;
		return 0;
	}
	cout << hex;
	while (1) 
	{
		fs.read(t, 1);
		if (fs.eof())
			break;
		if (i % 0x10 == 0x8)
			cout << " -";
		if (i % 0x10 == 0)
		{
			cout << setfill('0') << setw(8) << i << " ";
			cout << setfill(' ');
		}
		c = ((unsigned int)t[0] % 0x100u);
		cout << " " << setfill('0') << setw(2) << (unsigned int)c;
		cout << setfill(' ');
		h[i % 0x10] = t[0];
		i++;
		
		if (i % 0x10 == 0x0)
		{
			cout << "     ";
			for (int j = 0; j < 0x10; j++)
			{
				cout << (h[j] >= 33 && h[j] <= 126 ? h[j] : '.');
			}
			cout << endl;
		}
	}
	if (i % 0x10 != 0)
	{
		if (i % 0x10 <= 0x8)
		{
			cout << "  ";
		}
		for (int j = i % 0x10; j < 0x10; j++)
		{
			cout << "   ";
		}
		cout << "     ";
		for (int j = 0; static_cast<unsigned int>(j) < i % 0x10; j++)
		{
			cout << (h[j] >= 33 && h[j] <= 126 ? h[j] : '.');
		}
		cout << endl;
	}
	fs.close();
	return 0;
}
