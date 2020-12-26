#include<bits/stdc++.h>
int main()
{
  std::string str,ch;
  while(std::cin>>str>>ch)
  {
      int count=0;
      for(int i=0;i<str.size();i++)
      {
          if(ch[i]>=str[i])
          {
              count++;
          }
      }
      if(count==str.size())
      {
          std::cout<<"YES\n";
      }
      else
      {
          std::cout<<"NO\n";
      }
  }
}
