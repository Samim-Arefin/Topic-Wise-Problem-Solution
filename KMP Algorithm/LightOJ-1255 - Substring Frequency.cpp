#include<bits/stdc++.h>
std::vector<int> precalculate(std::string pattern)
{
	std::vector<int>lps(pattern.size());
	int i = 1 ,j = 0;
	while (i < pattern.size())
	{
		if (pattern[i] == pattern[j])
		{
			lps[i] = j + 1;
			i++, j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				lps[i] = j;
				i++;
			}
		}
	}
	return std::vector<int> (lps.begin(), lps.end());
}

int KMP(std::string text,std::string pattern)
{
	std::vector<int>lps(precalculate(pattern));
	int count = 0;
	int i = 0, j = 0;
	while (i < text.size())
	{
		if (text[i] == pattern[j])
		{
			i++, j++;
		}
		else
		{
			if (j != 0)
			{
				j = lps[j - 1];
			}
			else
			{
				i++;
			}
		}
		if (j == pattern.size())
		{
			count++;
			j = lps[j - 1];
		}
	}
	return count;
}
int main()
{
    int test;
  //freopen("input.txt","r",stdin);
 //freopen("output.txt","w",stdout);
    std::cin>>test;
    for(int i=1;i<=test;i++)
    {
        std::string word,pattern;
        std::cin>>word>>pattern;
        std::cout<<"Case "<<i<<": "<<KMP(word,pattern)<<'\n';
    }
}

