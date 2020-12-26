#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int size;
		long long count=0;
		std::cin >> size;
		for (int i = 0; i < size; i++)
		{
			char ch;
			std::cin >> ch;
			if (ch == '1')
			{
				count++;
			}
		}
		long long ans=(count * (count + 1)) / 2 ;
		std::cout <<ans << '\n';
	}
}
