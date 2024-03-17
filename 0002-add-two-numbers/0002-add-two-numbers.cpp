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
        while ( temp1 != NULL || temp2 != NULL || carry != 0 ) {
            int s = 0;
            if (temp1 != NULL) {
                s += temp1->val;
            }
            if (temp2 != NULL) {
                s += temp2->val;
            }
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
            if (temp1 != NULL){
                temp1 = temp1->next;
            }
            if (temp2 != NULL){
                temp2 = temp2->next;
            }
        }
        return ans;
    }
};