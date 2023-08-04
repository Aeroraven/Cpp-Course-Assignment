/* 已验证 xxx 的hex文件生成*/
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

char hex2char(char* t)
{
	char ret = 0;
	ret = (t[0] >= 'a' ? (t[0] - 'a' + 0xa) : (t[0] - '0' + 0x0));
	ret *= 0x10;
	ret += (t[1] >= 'a' ? (t[1] - 'a' + 0xa) : (t[1] - '0' + 0x0));
	return ret;
}
int main()
{
	ifstream ifs;
	ofstream ofs;
	char s[1000], p[1000];
	char temp[1000];
	cerr << "文件名以下形式均可以：" << endl;
	cerr << "    a.txt：不带路径形式" << endl;
	cerr << "    ..\\data\b.dat：相对路径形式" << endl;
	cerr << "    C:\\Windows\\System32\\c.dat：绝对相对路径形式" << endl;
	cerr << "请输入文件名: ";
	cin >> s;
	cerr << "请输入转换后的文件名 :";
	cin >> p;
	ifs.open(s, ios::in);
	ofs.open(p, ios::out | ios::binary);
	if (ifs.fail())
	{
		cout << "文件" << s << "打开失败!" << endl;
		return 0;
	}
	if (ofs.fail())
	{
		ifs.close();
		cout << "文件" << p << "打开失败!" << endl;
		return 0;
	}
	while (1)
	{
		int endflag = 0;
		while (1)
		{
			//offset
			ifs >> temp;
			if (ifs.eof())
			{
				endflag = 1;
				break;
			}
			ifs.get(temp[2]);
			ifs.get(temp[2]);
			//hex
			for (int i = 0; i < 0x10; i++)
			{
				if (i == 0x8)
				{
					ifs.get(temp[0]);
					ifs.get(temp[1]);
					if (ifs.eof())
					{
						endflag = 1;
						break;
					}
				}
				
				ifs.get(temp[0]);
				ifs.get(temp[1]);
				ifs.get(temp[2]);
				if (ifs.eof())
				{
					endflag = 1;
					break;
				}
				if (temp[0] == 32 && temp[1] == 32)
					continue;
				char x = hex2char(temp);
				ofs.write(&x, 1);
			}
			//characters
			char x = 0;
			while(x!='\n')
			{
				ifs.get(x);
				if (ifs.eof())
				{
					endflag = 1;
					break;
				}
			}
		}
		if (endflag)
			break;
	}
	ifs.close();
	ofs.close();


	return 0;
}
