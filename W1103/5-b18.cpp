#include <iostream>
using namespace std;

#define TEMP_CNT 1000
#define PASSWORD_LINES 10
#define PASSWORD_MAXLEN 17

int main() 
{
	int valid = 1;
	char tip_line[TEMP_CNT];
	cin.getline(tip_line, TEMP_CNT);
	int len, upper, lower, number, other;
	
	while (1)
	{
		cin >> len >> upper >> lower >> number >> other;
		if (cin.fail())
		{
			cout << "错误" << endl;
			return 0;
		}
		if (len < 12 || len>16)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (upper < 2)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (lower < 2)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (number < 2)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (other < 2)
		{
			cout << "错误" << endl;
			return 0;
		}
		if (upper + lower + number + other > len)
		{
			cout << "错误" << endl;
			return 0;
		}
		break;
	}

	char password[PASSWORD_MAXLEN];
	cin.getline(password, PASSWORD_MAXLEN);
	for (int i = 0; i < PASSWORD_LINES; i++)
	{
		int upper_real =0 , lower_real=0, number_real=0, other_real=0;
		cin >> password;
		int j = 0;
		while (password[j])
		{
			if (password[j] >= 'a' && password[j] <= 'z')
			{
				lower_real++;
			}
			else if (password[j] >= 'A' && password[j] <= 'Z')
			{
				upper_real++;
			}
			else if (password[j] >= '0' && password[j] <= '9')
			{
				number_real++;
			}
			else
			{
				other_real++;
			}
			j++;
		}
		if (j != len || upper_real < upper || lower_real < lower)
		{
			valid = 0;
			break;
		}
		if (number_real < number || other_real < other)
		{
			valid = 0;
			break;
		}
	}
	if (valid)
	{
		cout << "正确" << endl;
	}
	else
	{
		cout << "错误" << endl;
	}
	return 0;
}