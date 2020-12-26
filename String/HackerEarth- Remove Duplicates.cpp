#include<bits/stdc++.h>
int main()
{
    std::string str;
    while(std::cin>>str)
    {
       std:: map<char,int>mp;
       std::string ch;
       for(int i=0;i<str.size();i++)
       {
           if(mp[str[i]]==0)
           {
               ch+=str[i];
           }
           mp[str[i]]++;
       }
       std::cout<<ch<<'\n';
    }
}
