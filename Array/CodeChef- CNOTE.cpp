#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		bool flag = false;
		long long total_page, remain_page, cost, size;
		std::cin >> total_page >> remain_page >> cost >> size;

		for (int i = 0; i < size; i++)
		{
			int P, C;
			std::cin >> P >> C;
			if ((P + remain_page) >= total_page && cost >= C)
			{
				flag = true;
			}
		}
		if (flag == true)
		{
			std::cout << "LuckyChef\n";
		}
		else
		{
			std::cout << "UnluckyChef\n";
		}
	}
}