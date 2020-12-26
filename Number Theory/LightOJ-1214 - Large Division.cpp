
#include<bits/stdc++.h>
using namespace std;
bool divisor(string a,long long num)
{
    if(a[0]=='-' || num<0)
    {
        if(a[0]=='-')
        {
            reverse(a.begin(),a.end());
            a.pop_back();
            reverse(a.begin(),a.end());
        }
        if(num<0)
        {
            num=-num;
        }
    }
    long long check=0;
    for(int i=0;i<a.size();i++)
    {
        check=((check*10)+a[i]-'0')%num;
    }
    if(check==0)
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
    int t;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       string str;
       long long num;
       cin>>str>>num;
       if(divisor(str,num)==true)
       {
           cout<<"Case "<<i<<": divisible"<<endl;
       }
       else
       {
           cout<<"Case "<<i<<": not divisible"<<endl;
       }

    }
}
