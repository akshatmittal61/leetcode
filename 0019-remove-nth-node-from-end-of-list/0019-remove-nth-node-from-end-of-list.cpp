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
        ListNode* l=NULL;
        ListNode* lH=l;
        ListNode* temp=head;
        while(temp!=NULL)
        {
            ListNode* t=new ListNode(temp->val);
            t->next=l;
            l=t;
            temp=temp->next;
        }
        int k=0;
        ListNode* ans=NULL;
        temp=l;
        while(temp!=NULL)
        {
            ++k;
            if(k!=n)
            {
                ListNode* t=new ListNode(temp->val);
                t->next=ans;
                ans=t;
            }
            temp=temp->next;
        }
        return ans;
    }
};