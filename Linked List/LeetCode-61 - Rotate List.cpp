/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution{
public:
    ListNode* rotateRight(ListNode* head, int k){
        int size=0;
        ListNode* Temp=head;
        ListNode* Temp1=head;
        ListNode* List=head;
        ListNode* Rev=nullptr;
        ListNode* Tail=nullptr;

        while(Temp1!=nullptr)
        {
            size++;
            Temp1=Temp1->next;
        }
        if(k==0 ||size==0 || k%size==0)
        {
            return head;
        }
        else
        {
            int diff=size-(k%size);

            for(int i=1; i<=size; i++)
            {
                if(i>diff)
                {
                    if(Rev==nullptr)
                    {
                        ListNode* NewNode=new ListNode;
                        NewNode->val=Temp->val;
                        NewNode->next=nullptr;
                        Rev=Tail=NewNode;
                    }
                    else
                    {
                        ListNode* NewNode=new ListNode;
                        NewNode->val=Temp->val;
                        NewNode->next=nullptr;
                        Tail->next=NewNode;
                        Tail=Tail->next;
                    }
                }
                Temp=Temp->next;
            }



            int num=k%size,i=1;
            ListNode* Node=nullptr;
            ListNode* NodeTail=nullptr;
            while(i<=size)
            {
                if(i<=num)
                {
                    if(Node==nullptr)
                    {
                        ListNode* NewNode=new ListNode;
                        NewNode->val=Rev->val;
                        NewNode->next=nullptr;
                        Node=NodeTail=NewNode;
                    }
                    else
                    {
                        ListNode* NewNode=new ListNode;
                        NewNode->val=Rev->val;
                        NewNode->next=nullptr;
                        NodeTail->next=NewNode;
                        NodeTail=NodeTail->next;
                    }
                    Rev=Rev->next;
                }
                else
                {
                    ListNode* NewNode=new ListNode;
                    NewNode->val=List->val;
                    NewNode->next=nullptr;
                    NodeTail->next=NewNode;
                    NodeTail=NodeTail->next;
                    List=List->next;
                }
                i++;
            }
            return Node;
        }

    }
};
