int atoi1(const char* str)
	{
		int result = 0;
		for (int i = 0; (str[i] - '0') >= 0 && (str[i] - '0') < 10; ++i)
		{
			result *= 10;
			result += str[i] - '0';
		}
		return result;
	}
