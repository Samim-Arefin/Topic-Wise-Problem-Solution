#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ca;
    cin>>ca;
    for(int i=1; i<=ca; i++)
    {
        cout<<"Case "<<i<<":"<<endl;
        stack<string>back,forward,initial;
        initial.push("http://www.lightoj.com/");
        string str;
        while(cin>>str)
        {
            if(str=="QUIT")
            {
                break;
            }
            else
            {
                if(str=="VISIT")
                {
                    string ch;
                    cin>>ch;
                    back.push(ch);
                    cout<<back.top()<<endl;
                    while(!forward.empty())
                    {
                        forward.pop();
                    }
                }
                else if(str=="BACK" && !back.empty())
                {
                    string ch=back.top();
                    forward.push(ch);
                    back.pop();
                    if(!back.empty())
                    {
                        cout<<back.top()<<endl;
                    }
                    if(back.empty())
                    {
                        cout<<initial.top()<<endl;
                    }
                }
                else if(str=="BACK" && back.empty())
                {
                    cout<<"Ignored"<<endl;
                }
                else if(str=="FORWARD" && !forward.empty() )
                {
                    cout<<forward.top()<<endl;
                    string ch=forward.top();
                    back.push(ch);
                    forward.pop();
                }
                else if(str=="FORWARD" && forward.empty())
                {
                    cout<<"Ignored"<<endl;
                }

            }
        }
    }
}
