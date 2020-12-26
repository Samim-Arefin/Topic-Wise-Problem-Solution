#include<bits/stdc++.h>
int main()
{
	int test;
	std::cin >> test;
	while (test--)
	{
		int x, y, M;
		std::cin >> x >> y >> M;
		std::vector<int>v1;
		std::vector<std::pair<int, int>>v2;
		while (x--)
		{
			int temp;
			std::cin >> temp;
			v1.push_back(temp);
		}
		sort(v1.begin(), v1.end());
		for (int i = 0; i < v1.size(); i++)
		{

			if (v1[i] - y * M <= 0 && v1[i] + y * M >= 100)
			{
				v2.push_back({ 1,100 });
			}
			else if (v1[i] - y * M == 0 && v1[i] + y * M < 100)
			{
				v2.push_back({ 1,v1[i] + y * M });
			}
			else if (v1[i] - y * M > 0 && v1[i] + y * M >= 100)
			{
				v2.push_back({ v1[i] - y * M ,100 });
			}
			else if (v1[i] - y * M < 0 && v1[i] + y * M < 100)
			{
				v2.push_back({ 1,v1[i] + y * M });
			}
			else if (v1[i] - y * M > 0 && v1[i] + y * M < 100)
			{
				v2.push_back({ v1[i] - y * M ,v1[i] + y * M });
			}

		}

		int sum = 0;
		sum += v2[0].first - 1;
		for (int i = 0; i < v2.size() - 1; i++)
		{
			if ((v2[i + 1].first - (v2[i].second + 1)) > 0)
			{
				sum += (v2[i + 1].first - (v2[i].second + 1));
			}
		}
		sum += 100 - v2[v2.size() - 1].second;
		std::cout << sum << '\n';
		v1.clear(), v2.clear();
	}
}