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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* NextNode1=head;
        ListNode* CurrentNode1=head;
        ListNode* PreviousNode1=nullptr;
        while(NextNode1!=nullptr)
        {
            NextNode1=NextNode1->next;
            CurrentNode1->next=PreviousNode1;
            PreviousNode1=CurrentNode1;
            CurrentNode1=NextNode1;
        }
        head=PreviousNode1;


        if(n==1)
        {
            ListNode* Temp=head;
            head=head->next;
            delete Temp;
        }
        else
        {
            ListNode* Next=PreviousNode1;
            ListNode* Current=PreviousNode1;

            for(int i=1; i<n; i++)
            {
                Current=Next;
                Next=Next->next;
            }
            if(Next->next==nullptr)
            {
                Current->next=nullptr;
            }
            else
            {
                Current->next=Next->next;
                delete Next;
            }
        }


         ListNode* NextNode2=head;
         ListNode* CurrentNode2=head;
         ListNode* Node=nullptr;
         while(NextNode2!=nullptr)
         {
             NextNode2=NextNode2->next;
             CurrentNode2->next=Node;
             Node=CurrentNode2;
             CurrentNode2=NextNode2;
         }
         head=Node;
         return head;
    }
};
