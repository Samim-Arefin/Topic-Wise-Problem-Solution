#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> v1;
		while (n--)
		{
			int temp;
			cin >> temp;
			v1.push_back(temp);
		}
		sort(v1.begin(), v1.end());
		int min = 0;
		if (k >= v1[0])
		{
			min = (k - v1[0]);
		}
		cout << min << '\n';
	}
}