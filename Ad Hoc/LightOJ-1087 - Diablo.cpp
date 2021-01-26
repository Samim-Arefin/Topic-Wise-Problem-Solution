#include<bits/stdc++.h>
int main()
{
    int test;
    std::cin>>test;
    for(int i=1;i<=test;i++)
    {
        int size,query;
        std::cin>>size>>query;
        std::vector<int>v1;
        while(size--)
        {
            int num;
            std::cin>>num;
            v1.push_back(num);
        }
        std::cout<<"Case "<<i<<":\n";
        while(query--)
        {
            char ch;
            std::cin>>ch;
            if(ch=='a')
            {
                int temp;
                std::cin>>temp;
                v1.push_back(temp);
            }
            else
            {
                int temp;
                std::cin>>temp;
                if(temp>v1.size())
                {
                    std::cout<<"none\n";
                }
                else
                {
                    std::cout<<v1[temp-1]<<'\n';
                    v1.erase(v1.begin()+temp-1);
                }
            }
        }
    }
}
