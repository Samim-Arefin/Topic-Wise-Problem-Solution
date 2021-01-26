#include<bits/stdc++.h>
using namespace std;
class BSTNode
{
    int data;
    BSTNode* Left;
    BSTNode* Right;
public:
    BSTNode* NewNode(int value);
    BSTNode* Build(BSTNode* root,int value);
    void InorderPrint(BSTNode* root);
    void PreorderPrint(BSTNode* root);
    void Search(BSTNode* root,int value);
};

BSTNode* BSTNode:: NewNode(int value)
{
    BSTNode* temp=new BSTNode;
    temp->data=value;
    temp->Left=temp->Right=nullptr;
    return temp;
}

BSTNode* BSTNode:: Build(BSTNode* root,int value)
{
    if(root==nullptr)
    {
        root=NewNode(value);
        return root;
    }
    else if(value<=root->data)
    {
        root->Left=Build(root->Left,value);
    }
    else
    {
        root->Right=Build(root->Right,value);
    }
    return root;
}

void BSTNode:: InorderPrint(BSTNode* root)
{
    if(root==nullptr)
    {
        return;
    }

    InorderPrint(root->Left);
    cout<<root->data<<'\n';
    InorderPrint(root->Right);

}

void BSTNode:: PreorderPrint(BSTNode* root)
{
    if(root==nullptr)
    {
        return;
    }

    cout<<root->data<<'\n';
    PreorderPrint(root->Left);
    PreorderPrint(root->Right);

}

void BSTNode:: Search(BSTNode* root,int value)
{
    if(root==nullptr)
    {
        return;
    }
    else
    {
        BSTNode* CurrentNode=root;
        while(CurrentNode!=nullptr)
        {
            if(CurrentNode==nullptr)
            {
                return;
            }
            else if(CurrentNode->data==value)
            {
                PreorderPrint(CurrentNode);
                break;
            }
            else if(value<=CurrentNode->data)
            {
                CurrentNode=CurrentNode->Left;
            }
            else
            {
                CurrentNode=CurrentNode->Right;
            }
        }
    }
}

int main()
{
    int num;
    while(cin>>num)
    {
        BSTNode* root=nullptr;
        BSTNode obj;
        for(int i=0; i<num; i++)
        {
            int temp;
            cin>>temp;
            root=obj.Build(root,temp);
        }

        int val;
        cin>>val;
        obj.Search(root,val);
    }
}
