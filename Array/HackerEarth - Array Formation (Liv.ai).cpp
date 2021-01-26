#include<bits/stdc++.h>
using namespace std;
struct Stack
{
    int data;
    Stack *next;
};
Stack* shead=nullptr;

struct Queue
{
    int data;
    Queue *next;
};
Queue* qhead=nullptr,*tail=nullptr;

void spush(int sdata)
{
    Stack* temp=new Stack;
    temp->data=sdata;
    temp->next=shead;
    shead=temp;
}
int ssize(Stack* temp)
{
    int count=0;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}
void spop()
{
    Stack* temp=shead;
    shead=shead->next;
    delete temp;
}
void sclear()
{
    while(shead!=nullptr)
    {
        Stack* temp=shead;
        shead=shead->next;
        delete temp;
    }
}
void sprint(Stack* temp)
{
    int i=0,size=ssize(shead);
    while(temp!=nullptr)
    {
        cout<<temp->data;
        if(i+1<size)
        {
            cout<<" ";
        }
        temp=temp->next;
        i++;
    }
    cout<<"\n";
}

void qpush(int qdata)
{
    Queue* temp=new Queue;
    temp->data=qdata;
    temp->next=nullptr;
    if(qhead==nullptr)
    {
        qhead=tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=tail->next;
    }
}

int qsize(Queue* temp)
{
    int count=0;
    while(temp!=nullptr)
    {
        count++;
        temp=temp->next;
    }
    return count;
}

void qpop()
{
    Queue* CurrentNode=qhead;
    Queue* PreviousNode=nullptr;
    while(CurrentNode->next!=nullptr)
    {
        PreviousNode=CurrentNode;
        CurrentNode=CurrentNode->next;
    }
    tail=PreviousNode;
    PreviousNode->next=nullptr;
    delete CurrentNode;
}
void qclear()
{
    while(qhead!=nullptr)
    {
        Queue* temp=qhead;
        qhead=qhead->next;
        delete temp;
    }
}
void qprint(Queue* temp)
{
    int i=0,size=qsize(qhead);
    while(temp!=nullptr)
    {
        cout<<temp->data;
        if(i+1<size)
        {
            cout<<" ";
        }
        temp=temp->next;
        i++;
    }
    cout<<"\n";
}
bool prime(int data)
{
    bool check=false;
    for(int i=2;i*i<=data;i++)
    {
        if(data%i==0)
        {
            check=true;
            return check;
        }
    }
    return check;
}
int main()
{
    int num;
    while(cin>>num)
    {
        for(int i=0;i<num;i++)
        {
            int temp;
            cin>>temp;
            if(!(prime(temp)))
            {
                qpush(temp);
            }
            else
            {
                spush(temp);
            }
        }
        qprint(qhead);
        sprint(shead);
        sclear();
        qclear();
    }
}
