#include <bits/stdc++.h>

int main() {
    int q;
    std::cin>>q;
    std::list<int>l;
    while(q--)
    {
        int num;
        std::cin>>num;
        if(num==1)
        {
            int temp;
            std::cin>>temp;
            l.push_back(temp);
        }
        else if(num==2)
        {
            l.pop_front();
        }
        else
        {
           std::cout<<l.front()<<'\n';
        }
    }
    return 0;
}
