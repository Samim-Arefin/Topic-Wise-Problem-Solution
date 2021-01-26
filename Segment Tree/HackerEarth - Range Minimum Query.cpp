#include<bits/stdc++.h>
using namespace std;

void Init(vector<int>&arr,vector<int>&tree,int node,int b,int e)
{
    if(b==e)
    {
        tree[node]=arr[b];
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    Init(arr,tree,left,b,mid);
    Init(arr,tree,right,mid+1,e);
    tree[node]=min(tree[left],tree[right]);
}

void Update(vector<int>&tree,int node,int b,int e,int i,int value)
{
    if(b>i || i>e)
    {
        return;
    }
    else if(b>=i && e<=i)
    {
        tree[node]=value;
        return;
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    Update(tree,left,b,mid,i,value);
    Update(tree,right,mid+1,e,i,value);
    tree[node]=min(tree[left],tree[right]);
}

int Query(vector<int>&tree,int node,int b,int e,int i,int j)
{
    if(b>j || i>e)
    {
        return INT_MAX;
    }
    else if(b>=i && e<=j)
    {
        return tree[node];
    }
    int left=node*2;
    int right=node*2+1;
    int mid=(b+e)/2;
    int val1=Query(tree,left,b,mid,i,j);
    int val2=Query(tree,right,mid+1,e,i,j);
    return min(val1,val2);
}

int main()
{
    int size,q;
    while(cin>>size>>q)
    {
        vector<int>arr(size+2),tree(4*size+2);
        for(int i=1; i<=size; i++)
        {
            cin>>arr[i];
        }
        Init(arr,tree,1,1,size);

        while(q--)
        {
            char ch;
            cin>>ch;
            if(ch=='q')
            {
                int i,j;
                cin>>i>>j;
                cout<<Query(tree,1,1,size,i,j)<<'\n';
            }
            else
            {
                int i,value;
                cin>>i>>value;
                Update(tree,1,1,size,i,value);
            }
        }
        arr.clear(),tree.clear();
    }
}
