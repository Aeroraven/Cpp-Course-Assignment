int tj_strlen(const char str[]) 
{
	int i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return i;
}
int tj_strcat(char s1[], const char s2[])
{
	int i = 0, j=0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (1)
	{
		s1[i++] = s2[j];
		if (s2[j++] == '\0')
		{
			break;
		}
	}
	return 0;
}
int tj_strncat(char s1[], const char s2[], const int len)
{
	int i = 0, j = 0;
	while (s1[i] != '\0')
	{
		i++;
	}
	while (s2[j]!='\0')
	{
		s1[i++] = s2[j++];
		if (j == len)
		{
			break;
		}
	}
	s1[i] = '\0';
	return 0;
}
int tj_strcpy(char s1[], const char s2[])
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i++];
	}
	s1[i] = '\0';
	return 0;
}

int tj_strncpy(char s1[], const char s2[], const int len)
{
	int i = 0;
	while (s2[i] != '\0')
	{
		s1[i] = s2[i++];
		if (i >= len)
		{
			break;
		}
	}
	return 0;
}
int tj_strcmp(const char s1[], const char s2[])
{
	int s1_valid = 1;
	int s2_valid = 1;
	int s1_ascii, s2_ascii;
	int i = 0;
	int ans = 0;
	while (1)
	{
		if (s1[i] == '\0')
		{
			s1_valid = 0;
		}
		if (s1_valid == 0)
		{
			s1_ascii = 0;
		}
		else
		{
			s1_ascii = static_cast<int>(s1[i]);
		}

		if (s2[i] == '\0')
		{
			s2_valid = 0;
		}
		if (s2_valid == 0)
		{
			s2_ascii = 0;
		}
		else
		{
			s2_ascii = static_cast<int>(s2[i]);
		}
		ans = s1_ascii - s2_ascii;
		if (ans != 0)
		{
			return ans;
		}
		else if (s2_valid == 0 && s1_valid == 0)
		{
			return 0;
		}
		i++;
	}
	return 0;
}

int tj_strcasecmp(const char s1[], const char s2[])
{
	int s1_valid = 1;
	int s2_valid = 1;
	int s1_ascii, s2_ascii;
	int i = 0;
	int ans = 0;
	while (1)
	{
		if (s1[i] == '\0')
		{
			s1_valid = 0;
		}
		if (s1_valid == 0)
		{
			s1_ascii = 0;
		}
		else
		{
			s1_ascii = static_cast<int>(s1[i]);
			if (s1_ascii >= static_cast<int>('A') && s1_ascii <= static_cast<int>('Z'))
			{
				s1_ascii = s1_ascii - static_cast<int>('A') + static_cast<int>('a');
			}
		}

		if (s2[i] == '\0')
		{
			s2_valid = 0;
		}
		if (s2_valid == 0)
		{
			s2_ascii = 0;
		}
		else
		{
			s2_ascii = static_cast<int>(s2[i]);
			if (s2_ascii >= static_cast<int>('A') && s2_ascii <= static_cast<int>('Z'))
			{
				s2_ascii = s2_ascii - static_cast<int>('A') + static_cast<int>('a');
			}
		}
		ans = s1_ascii - s2_ascii;
		if (ans != 0)
		{
			return ans;
		}
		else if (s2_valid == 0 && s1_valid == 0)
		{
			return 0;
		}
		i++;
	}
	return 0;
}
int tj_strncmp(const char s1[], const char s2[], const int len)
{
	int s1_valid = 1;
	int s2_valid = 1;
	int s1_ascii, s2_ascii;
	int i = 0;
	int ans = 0;
	while (1)
	{
		if (s1[i] == '\0')
		{
			s1_valid = 0;
		}
		if (s1_valid == 0)
		{
			s1_ascii = 0;
		}
		else
		{
			s1_ascii = static_cast<int>(s1[i]);
		}

		if (s2[i] == '\0')
		{
			s2_valid = 0;
		}
		if (s2_valid == 0)
		{
			s2_ascii = 0;
		}
		else
		{
			s2_ascii = static_cast<int>(s2[i]);
		}
		ans = s1_ascii - s2_ascii;
		if (ans != 0)
		{
			return ans;
		}
		else if (s2_valid == 0 || s1_valid == 0)
		{
			return 0;
		}
		i++;
		if (i >= len)
		{
			return 0;
		}
	}
	return 0;
}

int tj_strcasencmp(const char s1[], const char s2[], const int len)
{
	int s1_valid = 1;
	int s2_valid = 1;
	int s1_ascii, s2_ascii;
	int i = 0;
	int ans = 0;
	while (1)
	{
		if (s1[i] == '\0')
		{
			s1_valid = 0;
		}
		if (s1_valid == 0)
		{
			s1_ascii = 0;
		}
		else
		{
			s1_ascii = static_cast<int>(s1[i]);
			if (s1_ascii >= static_cast<int>('A') && s1_ascii <= static_cast<int>('Z'))
			{
				s1_ascii = s1_ascii - static_cast<int>('A') + static_cast<int>('a');
			}
		}

		if (s2[i] == '\0')
		{
			s2_valid = 0;
		}
		if (s2_valid == 0)
		{
			s2_ascii = 0;
		}
		else
		{
			s2_ascii = static_cast<int>(s2[i]);
			if (s2_ascii >= static_cast<int>('A') && s2_ascii <= static_cast<int>('Z'))
			{
				s2_ascii = s2_ascii - static_cast<int>('A') + static_cast<int>('a');
			}
		}
		ans = s1_ascii - s2_ascii;
		if (ans != 0)
		{
			return ans;
		}
		else if (s2_valid == 0 || s1_valid == 0)
		{
			return 0;
		}
		i++;
		if (i >= len)
		{
			return 0;
		}
	}
	return 0;
}

int tj_strupr(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 'a' + 'A';
		}
		i++;
	}
	return 0;
}
int tj_strlwr(char str[])
{
	int i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] = str[i] - 'A' + 'a';
		}
		i++;
	}
	return 0;
}
int tj_strchr(const char str[], const char ch)
{
	int i = 0;
	//Because the maximal output is n, according to the instruction
	// '\0' will not be counted
	while (str[i] != '\0')
	{
		if (str[i] == ch)
		{
			return i + 1;
		}
		i++;
	}
	return 0;
}
int tj_strstr(const char str[], const char substr[])
{
	int str_len = tj_strlen(str);
	int sub_len = tj_strlen(substr);
	for (int i = 0; i <str_len; i++)
	{
		if (i + sub_len > str_len)
		{
			break;
		}
		int match = true;
		for (int j = 0; j < sub_len; j++)
		{
			if (str[i + j] != substr[j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return i + 1;
		}
	}
	return 0;
}
int tj_strrchr(const char str[], const char ch)
{
	//Because the maximal output is n, according to the instruction
	// '\0' will not be counted
	int l = tj_strlen(str);
	for (int i = l - 1; i >= 0; i--)
	{
		if (str[i] == ch)
		{
			return i + 1;
		}
	}
	return 0;
}
int tj_strrstr(const char str[], const char substr[])
{
	int str_len = tj_strlen(str);
	int sub_len = tj_strlen(substr);
	for (int i = str_len - sub_len; i >= 0; i--)
	{
		int match = true;
		for (int j = 0; j < sub_len; j++)
		{
			if (str[i + j] != substr[j])
			{
				match = false;
				break;
			}
		}
		if (match)
		{
			return i + 1;
		}
	}
	return 0;
}

int tj_strrev(char str[])
{
	int len = tj_strlen(str);
	if (len <= 1 )
	{
		return 0;
	}
	int ub = (len - 1) / 2;
	for (int i = 0; i <= ub; i++)
	{
		int tmp = str[i];
		str[i] = str[len - 1 - i];
		str[len - 1 - i] = tmp;
	}
	return 0;
}