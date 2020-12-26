#include<bits/stdc++.h>
#define Max 1000001;
using namespace std;
int phi[1000001];
void ETF()
{
    for(long long i=1;i<=1000001;i++)
    {
        phi[i]=i;
    }
    for(long long i=2;i<=1000001;i++)
    {
        if(phi[i]==i)
        {
            for(long long j=i;j<=1000001;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
int main()
{
   ETF();
   int t;
   cin>>t;
   while(t--)
   {
       long long num;
       cin>>num;
       cout<<phi[num]<<endl;
   }
}
