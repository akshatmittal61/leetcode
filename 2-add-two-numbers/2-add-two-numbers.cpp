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
        ListNode* l=new ListNode(0);
        ListNode *ans=l;
        int carry=0;
        while(l1&&l2)
        {
            int sum=l1->val+l2->val+carry;
            carry=(sum>9)?1:0;
            ListNode* t=new ListNode(sum%10);
            l->next=t;
            l=l->next;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1)
        {
            int sum=l1->val+carry;
            carry=(sum>9)?1:0;
            l->next=new ListNode(sum%10);
            l1=l1->next;
            l=l->next;
        }
        while(l2)
        {
            int sum=l2->val+carry;
            carry=(sum>9)?1:0;
            l->next=new ListNode(sum%10);
            l2=l2->next;
            l=l->next;
        }
        if(carry)l->next=new ListNode(1);
        return ans->next;
    }
};