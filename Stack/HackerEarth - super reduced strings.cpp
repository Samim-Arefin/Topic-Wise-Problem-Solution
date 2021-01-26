#include<iostream>
using namespace std;
class stack
{
    char ch;
    stack *next;
public:
    void push(char ch);
    void pop();
    void print(stack *temp);
    void reverseprint();
    char top();
    bool empty();
    void clear();

};
stack *head=nullptr;

void stack::push(char ch)
{
    stack* temp=new stack;
    temp->ch=ch;
    temp->next=head;
    head=temp;

}

void stack:: pop()
{
    stack* temp=head;
    head=head->next;
    delete temp;

}

void stack:: reverseprint()
{
    stack* CurrentNode=head;
    stack* NextNode=head;
    stack* PreviousNode=nullptr;
    while(NextNode!=nullptr)
    {
        NextNode=NextNode->next;
        CurrentNode->next=PreviousNode;
        PreviousNode=CurrentNode;
        CurrentNode=NextNode;
    }
    head=PreviousNode;
    while(PreviousNode!=nullptr)
    {
        cout<<PreviousNode->ch;
        PreviousNode=PreviousNode->next;
    }
    cout<<'\n';
}

void stack::print(stack *temp)
{
    if(temp==nullptr)
    {
        cout<<"Empty\n";
        return;
    }
    while(temp!=nullptr)
    {
        cout<<temp->ch;
        temp=temp->next;
    }
    cout<<'\n';
}

char stack::top()
{
    return (head->ch);
}

bool stack:: empty()
{
    if(head==nullptr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void stack:: clear()
{
    while(head!=nullptr)
    {
        stack* temp=head;
        head=head->next;
        delete temp;
    }
}

int main()
{
    string str;
    while(cin>>str)
    {
        stack s;
        for(int i=0; i<str.size(); i++)
        {
            if(!(s.empty()) && s.top()==str[i])
            {
                s.pop();
            }
            else
            {
                s.push(str[i]);
            }
        }
        if(s.empty())
        {
            cout<<"Empty String\n";
        }
        else
        {
            s.reverseprint();
        }
        str.clear();
        s.clear();
    }
}


