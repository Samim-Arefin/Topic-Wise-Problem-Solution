#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int size, candy;
		std::cin >> size >> candy;
		for (int i = 0; i < size; i++)
		{
			int temp;
			std::cin >> temp;
			candy -= temp;
		}
		if (candy >= 0)
		{
			std::cout << "Yes\n";
		}
		else
		{
			std::cout << "No\n";
		}
	}
}