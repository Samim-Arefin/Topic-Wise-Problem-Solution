#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int N, K;
		std::cin >> N >> K;
		std::vector<std::string>v1;
		std::map<std::string, std::string>mp1;
		std::map<std::string, bool>mp2;
		for (int i = 0; i < N; i++)
		{
			std::string temp;
			std::cin >> temp;
			v1.push_back(temp);
			mp1[temp] = temp;
			mp2[temp] = false;
		}
		while (K--)
		{
			int L;
			std::cin >> L;
			while (L--)
			{
				std::string temp;
				std::cin >> temp;
				if (mp1[temp] == temp)
				{
					mp2[temp] = true;
				}
			}
		}

		int size = v1.size();
		for (int i = 0; i < size; i++)
		{
			if (mp2[v1[i]] == true)
			{
				std::cout << "YES";
			}
			else
			{
				std::cout << "NO";
			}
			if (i + 1 < size)
			{
				std::cout << " ";
			}
		}
		std::cout << "\n";
		v1.clear();
		mp1.clear();
		mp2.clear();

	}
}