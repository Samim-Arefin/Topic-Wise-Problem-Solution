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
    ListNode* middleNode(ListNode* head) {
        int size=0;
        ListNode* Temp=head;
        ListNode* Count=head;
        ListNode* Value=nullptr;
        while(Temp!=nullptr)
        {
            size++;
            Temp=Temp->next;
        }
        int val=(size/2)+1;
        for(int i=1;i<=size;i++)
        {
            if(i==val)
            {
                Value=Count;
                break;
            }
            Count=Count->next;
        }
        return Value;
    }
};
