#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		std::string str;
		std::cin >> str;
		int size = str.size();

		if (size & 1)
		{
			int beg, end;
			beg = end = (size / 2) + 1;

			std::string str1(str.begin(), str.end() - end);
			std::string str2(str.begin() + beg, str.end());

			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());

			if (str1 == str2)
			{
				std::cout << "YES\n";
			}
			else
			{
				std::cout << "NO\n";
			}
		}
		else
		{
			int beg, end;
			beg = end = size / 2;

			std::string str1(str.begin(), str.end() - end);
			std::string str2(str.begin() + beg, str.end());

			sort(str1.begin(), str1.end());
			sort(str2.begin(), str2.end());

			if (str1 == str2)
			{
				std::cout << "YES\n";
			}
			else
			{
				std::cout << "NO\n";
			}
		}
		str.clear();
	}
	
}