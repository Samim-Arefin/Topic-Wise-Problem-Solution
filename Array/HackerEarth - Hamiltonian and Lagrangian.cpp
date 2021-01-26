#include<bits/stdc++.h>
using namespace std;
int main()
{
	int size;
	while (cin >> size)
	{
		vector<int> v1, v2;
		while (size--)
		{
			int temp;
			cin >> temp;
			v1.push_back(temp);
		}
		while (1)
		{
			int count = 0, num = v1.size();
			for (int i = 0; i < v1.size() - 1; i++)
			{
				if (v1[i] >= v1[i + 1])
				{
					v2.push_back(v1[i]);
					count++;
				}
			}
			count++;
			v2.push_back(v1[v1.size() - 1]);
			v1.clear();
			v1 = v2;
			v2.clear();
			if (count == num)
			{
				break;
			}
		}
		for (int i = 0; i < v1.size(); i++)
		{
			cout << v1[i];
			if (i + 1 < v1.size())
			{
				cout << " ";
			}
		}
		cout << '\n';
	}
}