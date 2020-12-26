#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int num, val,count=0;
		std::cin >> num >> val;
		for (int i = 0; i < num; i++)
		{
			int temp;
			std::cin >> temp;
			if ((temp + val) % 7 == 0)
			{
				count++;
			}
		}
		std::cout << count << '\n';
	}
}
