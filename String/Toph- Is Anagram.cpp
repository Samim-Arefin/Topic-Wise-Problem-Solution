
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str,ch;
	while (cin>>str>>ch)
	{
		if (str.size() == ch.size())
		{
			sort(str.begin(),str.end());
			sort(ch.begin(),ch.end());
			if (str == ch)
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
		else
		{
			cout << "No" << endl;
		}
	}
}
