#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int size;
		cin >> size;
		double store = (pow(2, size)) / 2;
		unsigned long long num;
		double sum = 0.0;
		while (size--)
		{
			cin >> num;
			if (num >= store)
			{
				sum += num;
			}
		}
		cout << sum << '\n';
	}
}