
#include<bits/stdc++.h>
#define Max 10000005
using namespace std;
bitset<Max> arr;
vector<long long> v1;
void sieve()
{
    arr[0]=arr[1]=true;
    for(long long i=4;i<Max;i+=2)
    {
        arr[i]=true;
    }
    for(long long i=3;i*i<Max;i+=2)
    {
        if(arr[i]==false)
        {
            for(long long j=i*i;j<Max;j+=i+i )
            {
               arr[j]=true;
            }
        }
    }
    v1.push_back(2);
    for(long long i=3;i<Max;i+=2)
    {
        if(arr[i]==false)
        {
            v1.push_back(i);
        }
    }
}
bool factor(long long num)
{
    map<long long,long long>mp;
    map<long long,long long>::iterator it;
    for(long long i=0;v1[i]*v1[i]<=num;i++)
    {
        if(num%v1[i]==0)
        {
            while(num%v1[i]==0)
            {
                num/=v1[i];
                mp[v1[i]]++;
            }
        }
    }
    if(num>1)
    {
        mp[num]++;
    }
    int e_c=0,o_c=0;
    for(it=mp.begin();it!=mp.end();it++)
    {
       if((it->second)%2==0)
       {
           e_c++;
       }
       else
       {
           o_c++;
       }
    }
    if(e_c>o_c)
    {
        return true;
    }
    else
    {
      return false;
    }

}
int main()
{
    sieve();
    long long t;
    scanf("%lld",&t);
    while(t--)
    {
        long long num;
        scanf("%lld",&num);
        if(factor(num)==true)
        {
            printf("Psycho Number\n");
        }
        else
        {
            printf("Ordinary Number\n");
        }

    }
}
