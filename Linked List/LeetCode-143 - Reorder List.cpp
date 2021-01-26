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
class Solution {
public:
    void reorderList(ListNode* head) {
        int size=0;
        ListNode* Temp=head;
        ListNode* List=head;
        ListNode* Rev=nullptr;
        ListNode* Tail=nullptr;
        while(Temp!=nullptr)
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
            size++;
            Temp=Temp->next;
        }

        ListNode* NextNode=Rev;
        ListNode* CurrentNode=Rev;
        ListNode* PreviousNode=nullptr;
        while(NextNode!=nullptr)
        {
            NextNode=NextNode->next;
            CurrentNode->next=PreviousNode;
            PreviousNode=CurrentNode;
            CurrentNode=NextNode;
        }
        Rev=PreviousNode;

        int i=1;
        ListNode* Node=nullptr;
        ListNode* NodeTail=nullptr;
        while(i<=size)
        {
            if(i%2==1)
            {
                if(Node==nullptr)
                {
                    ListNode* NewNode=new ListNode;
                    NewNode->val=List->val;
                    NewNode->next=nullptr;
                    Node=NodeTail=NewNode;
                }
                else
                {
                    ListNode* NewNode=new ListNode;
                    NewNode->val=List->val;
                    NewNode->next=nullptr;
                    NodeTail->next=NewNode;
                    NodeTail=NodeTail->next;
                }
                List=List->next;
            }
            else
            {
                    ListNode* NewNode=new ListNode;
                    NewNode->val=Rev->val;
                    NewNode->next=nullptr;
                    NodeTail->next=NewNode;
                    NodeTail=NodeTail->next;
                    Rev=Rev->next;
            }
            i++;
        }

        ListNode* New=head;
        while(Node!=nullptr)
        {
            New->val=Node->val;
            Node=Node->next;
            New=New->next;
        }

    }
};
