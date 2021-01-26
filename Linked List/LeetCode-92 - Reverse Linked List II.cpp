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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* First=nullptr;
        ListNode* Second=First;
        ListNode* Temp=head;
        ListNode* Store=nullptr;
        ListNode* List=nullptr;
        for(int i=1;i<=m;i++)
        {

            List=Store=Temp;
            Temp=Temp->next;
        }


        for(int i=m;i<=n;i++)
        {
            if(First==nullptr)
            {
                ListNode* Node=new ListNode;
                Node->val=Store->val;
                Node->next=nullptr;
                First=Second=Node;
            }
            else
            {
                ListNode* Node=new ListNode;
                Node->val=Store->val;
                Node->next=nullptr;
                Second->next=Node;
                Second=Second->next;
            }
            Store=Store->next;
        }


        ListNode* NextNode=First;
        ListNode* CurrentNode=First;
        ListNode* PreviousNode=nullptr;
        while(NextNode!=nullptr)
        {
            NextNode=NextNode->next;
            CurrentNode->next=PreviousNode;
            PreviousNode=CurrentNode;
            CurrentNode=NextNode;
        }
        First=PreviousNode;

        for(int i=m;i<=n;i++)
        {
            List->val=First->val;
            List=List->next;
            First=First->next;
        }

        return head;
    }
};
