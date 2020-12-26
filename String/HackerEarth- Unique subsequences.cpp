#include<bits/stdc++.h>
int main()
{
    int test;
    std::cin>>test;
    while(test--)
    {
        int size;
        std::string str;
        std::cin>>size;
        for(int i=0;i<size;i++)
        {
            char ch;
            std::cin>>ch;
            str.push_back(ch);
        }
        int count=0;
        for(int i=0;i<str.size();i++)
        {
            if(str[i]!=str[i+1])
            {
                count++;
            }
        }
        std::cout<<count<<'\n';
    }
}
