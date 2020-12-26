
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string num;
	while(cin>>num)
	{
		stack<char> s;
		for (int i = num.size() - 1,j=0; i >= 0; i--,j++)
		{
			if (j == 3)
			{
				s.push(',');
				j = 0;
			}
			s.push(num[i]);
		}
		while (!s.empty())
		{
			cout << s.top();
			s.pop();
		}
		cout << endl;
	}
}
