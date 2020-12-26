#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int num;
		std::cin >> num;
		std::vector<int>v1;
		for (int i = 0; i < num; i++)
		{
			int temp;
			std::cin >> temp;
			v1.push_back(temp);
		}

		int size = num / 2;
		int end = v1.size() - 1;
		bool check = true;
		for (int i = 0; i < size; i++)
		{
			if ((v1[i + 1] - v1[i] <= 1) && (v1[end - 1] - v1[end] <= 1) && (v1[i] == v1[end - i]))
			{
				continue;
			}
			else
			{
				check = false;
				break;
			}
		}
		if (check == true)
		{
			std::cout << "yes\n";
		}
		else
		{
			std::cout << "no\n";
		}

	}
}