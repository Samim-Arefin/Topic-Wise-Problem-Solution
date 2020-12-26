#include<bits/stdc++.h>
#define Max 1000005
using namespace std;
long long phi[Max];
long long precalculate[Max];
void ETF()
{
    for(int i=1;i<Max;i++)
    {
        phi[i]=i;
    }
    for(int i=2;i<Max;i++)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<Max;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
void calculate()
{
    ETF();
    for(int i=1;i<Max;i++)
    {
        for(int j=i;j<Max;j+=i)
        {
            precalculate[j]+=(i*phi[i]);
        }
    }
}

int main()
{
   calculate();
   int t;
   scanf("%d",&t);
   while(t--)
   {
       long long num;
       scanf("%lld",&num);
       long long res=((precalculate[num]+1)*num);
       res/=2;
       printf("%lld\n",res);
   }
}
