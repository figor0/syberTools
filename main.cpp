#include <iostream>
#include <string>

std::string binary_str(int number)
{
	std::string str;
	str.reserve(sizeof(number));
	while( number > 0)
	{
		if ((number&1) == 0)
			str.push_back('0');
		else
			str.push_back('1');
		number=number>>1;
	}
	return std::string(str.rbegin(), str.rend());
}

void RemoveDups(char* str)
{
	int change = 0;
	if (str != nullptr)
	{
		int i = 0;
		for(; str[i] != '\n'; i++)
		{
			if ( str[i] == str[i+1])
				change++;
			else
				str[i-change] = str[i];
		}
		str[i-change] = str[i];
	}
}

int main(void)
{
	char str[] = "AABBCCDfg";
	RemoveDups(str);
	std::cout << std::string(str) << std::endl;
	return 0;
}
