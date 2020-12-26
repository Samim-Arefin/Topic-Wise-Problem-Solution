
#include<bits/stdc++.h>
#define Max 1000005
using namespace std;
bitset<Max> arr;
vector<int> v1;
void sieve()
{
    arr[0]=arr[1]=true;
    for(int i=4;i<Max;i+=2)
    {
        arr[i]=true;
    }
    for(int i=3;i*i<Max;i+=2)
    {
        if(arr[i]==false)
        {
            for(int j=i*i;j<Max;j+=i+i)
            {
                arr[j]=true;
            }
        }
    }
    v1.push_back(2);
    for(int i=3;i<Max;i+=2)
    {
        if(arr[i]==false)
        {
            v1.push_back(i);
        }
    }
}

map<int,int> countfactor (int num)
{
    map<int,int>mp;
    for(int i=0;i<v1.size() && v1[i]<=num;i++)
    {
        int fre=0;
        int temp=num;
        while(temp/v1[i])
        {
            fre+=temp/v1[i];
            temp/=v1[i];
        }
        mp[v1[i]]=fre;
    }
    return map<int,int>(mp.begin(),mp.end());

}
int main()
{
    sieve();
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
        int num;
        cin>>num;
        map<int,int>mp(countfactor(num));
        map<int,int>::iterator it;
        cout<<"Case "<<i<<": "<<num<<" = ";
        int count=0;
        for(it=mp.begin();it!=mp.end();it++)
        {
            cout<<it->first<<" ("<<it->second<<")";
            if(++count<mp.size())
            {
                cout<<" * ";
            }
        }
        cout<<endl;
    }
}
