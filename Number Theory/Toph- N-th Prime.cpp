
#include<bits/stdc++.h>
#define Max 10000005
using namespace std;
bitset<Max> arr;
vector<int> v1;
void sieve()
{
	arr[0] = arr[1] = true;
	for (int i = 4; i < Max; i += 2)
	{
		arr[i] = true;
	}
	for (int i = 3; i * i < Max; i += 2)
	{
		if (arr[i] == false)
		{
			for (int j = i * i; j < Max; j += i + i)
			{
				arr[j] = true;
			}
		}
	}
	v1.push_back(2);
	for (int i = 3; i < Max; i += 2)
	{
		if (arr[i] == false)
		{
			v1.push_back(i);
		}
	}
}
int main()
{
	sieve();
	int num;
	while (cin >> num)
	{
		cout << v1[num - 1] << endl;
	}
}
