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
        int carry = 0, curr = 0;
        ListNode* ans = NULL;
        ListNode* temp = ans;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while ( temp1 != NULL && temp2 != NULL ) {
            int s = temp1->val + temp2->val;
            curr = (carry + s) % 10;
            ListNode* nd = new ListNode(curr);
            if ( temp == NULL ) {
                temp = nd;
                ans = nd;
            } else {
                temp->next = nd;
                temp = temp->next;
            }
            carry = (carry + s) / 10;
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        while ( temp1 != NULL ) {
            int s = temp1->val;
            curr = (carry + s) % 10;
            ListNode* nd = new ListNode(curr);
            if ( temp == NULL ) {
                temp = nd;
                ans = nd;
            } else {
                temp->next = nd;
                temp = temp->next;
            }
            carry = (carry + s) / 10;
            temp1 = temp1->next;
        }
        while ( temp2 != NULL ) {
            int s = temp2->val;
            curr = (carry + s) % 10;
            ListNode* nd = new ListNode(curr);
            if ( temp == NULL ) {
                temp = nd;
                ans = nd;
            } else {
                temp->next = nd;
                temp = temp->next;
            }
            carry = (carry + s) / 10;
            temp2 = temp2->next;
        }
        if ( carry != 0 ) {
            ListNode* nd = new ListNode(carry % 10);
            if (temp == NULL) {
                temp = nd;
                ans = nd;
            } else {
                temp->next = nd;
            }
        }
        return ans;
    }
};