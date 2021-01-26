#include<iostream>
using namespace std;
class stack
{
    int data;
    stack *next;
public:
    void push(int data);
    void pop();
    void print(stack* temp);
    int top();
    bool empty();
    void clear();

};
stack *head=nullptr;

void stack::push(int data)
{
    stack* temp=new stack;
    temp->data=data;
    temp->next=head;
    head=temp;

}

void stack:: pop()
{
    stack* temp=head;
    head=head->next;
    delete temp;

}

void stack:: print(stack* temp)
{
    if(temp==nullptr)
    {
        cout<<"Empty\n";
        return;
    }
    while(temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<'\n';
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

int stack:: top()
{
    return (head->data);
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
    int t;
    cin>>t;
    while(t--)
    {
        int num;
        cin>>num;
        int *arr=new int[num];
        int *con=new int[num];
        stack s;
        for(int i=0; i<num; i++)
        {
            cin>>arr[i];
        }
        s.push(0);
        con[0]=1;
        for(int i=1; i<num; i++)
        {
            while(!(s.empty()) && arr[s.top()]<=arr[i])
            {
                s.pop();
            }
            if(s.empty())
            {
                con[i]=i+1;
            }
            else
            {
                con[i]=i-s.top();
            }
             s.push(i);
        }

        for(int i=0; i<num; i++)
        {
            cout<<con[i];
            if(i+1<num)
            {
                cout<<" ";
            }
        }
        cout<<'\n';
        s.clear();
        delete [] arr;
        delete [] con;
    }
}
