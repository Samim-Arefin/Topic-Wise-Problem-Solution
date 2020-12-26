
#include<bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	while (cin >> str)
	{
		stack<char> st;
		for (int i = 0; i < str.size(); i++)
		{
			if (!st.empty() && st.top() == '(' && str[i] == ')')
			{
				st.pop();
			}
			else if (!st.empty() && st.top() == '{' && str[i] == '}')
			{
				st.pop();
			}
			else if (!st.empty() && st.top() == '[' && str[i] == ']')
			{
				st.pop();
			}
			else
			{
				st.push(str[i]);
			}
		}
		if (!st.empty())
		{
			cout << "No" << endl;
		}
		else
		{
			cout << "Yes" << endl;
		}
	}
}
