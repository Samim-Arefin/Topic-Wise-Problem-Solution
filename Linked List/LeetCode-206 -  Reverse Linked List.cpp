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
    ListNode* reverseList(ListNode* head) {
        ListNode* NextNode=head;
        ListNode* CurrentNode=head;
        ListNode* PreviousNode=nullptr;
        while(NextNode!=nullptr)
        {
            NextNode=NextNode->next;
            CurrentNode->next=PreviousNode;
            PreviousNode=CurrentNode;
            CurrentNode=NextNode;
        }
        head=PreviousNode;
        return head;
    }
};
