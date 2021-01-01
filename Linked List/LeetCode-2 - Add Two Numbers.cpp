
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* NextNode1=l1;
        ListNode* CurrentNode1=l1;
        ListNode* PreviousNode1=nullptr;
        while(NextNode1!=nullptr)
        {
            NextNode1=NextNode1->next;
            CurrentNode1->next=PreviousNode1;
            PreviousNode1=CurrentNode1;
            CurrentNode1=NextNode1;
        }
        l1=PreviousNode1;
        std::string sum1;
        while(l1!=nullptr)
        {
            sum1+=std::to_string(l1->val);
            l1=l1->next;
        }


        ListNode* NextNode2=l2;
        ListNode* CurrentNode2=l2;
        ListNode* PreviousNode2=nullptr;
        while(NextNode2!=nullptr)
        {
            NextNode2=NextNode2->next;
            CurrentNode2->next=PreviousNode2;
            PreviousNode2=CurrentNode2;
            CurrentNode2=NextNode2;
        }
        l2=PreviousNode2;
        std::string sum2;
        while(l2!=nullptr)
        {
            sum2+=std::to_string(l2->val);
            l2=l2->next;
        }

        if(sum1.size()>sum2.size())
        {
            swap(sum1,sum2);
        }
        reverse(sum1.begin(),sum1.end());
        reverse(sum2.begin(),sum2.end());
        std::string sum;
        int carry=0;
        for(int i=0;i<sum1.size();i++)
        {
            int temp=sum1[i]-'0'+sum2[i]-'0'+carry;
            sum.push_back(temp%10+'0');
            carry=temp/10;

        }
        for(int i=sum1.size();i<sum2.size();i++)
        {
            int temp=sum2[i]-'0'+carry;
            sum.push_back(temp%10+'0');
            carry=temp/10;

        }
        if(carry>0)
        {
            sum.push_back(carry+'0');
        }

        ListNode* Head=new ListNode;
        ListNode* Tail=new ListNode;
        Head=Tail=nullptr;

        for(auto it:sum)
        {

            if(Head==nullptr)
            {
                 ListNode *Temp=new ListNode;
                 Temp->val=(it-'0');
                 Temp->next=nullptr;
                 Head=Tail=Temp;
            }
            else
            {
                 ListNode *Temp=new ListNode;
                 Temp->val=(it-'0');
                 Temp->next=nullptr;
                 Tail->next=Temp;
                 Tail=Tail->next;
            }


        }

        return Head;
    }
};
