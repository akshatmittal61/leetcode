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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* list3 = new ListNode();
        ListNode *temp1 = list1, *temp2 = list2, *temp3 = list3;
        while( temp1 != NULL && temp2 != NULL ) {
            if( temp1->val < temp2->val ) {
                ListNode* newNode = new ListNode(temp1->val);
                if( temp3 == NULL ) list3 = newNode;
                else temp3->next = newNode;
                temp1 = temp1->next;
                temp3 = temp3->next;
            }
            else if( temp2->val <= temp1->val ) {
                ListNode* newNode = new ListNode(temp2->val);
                if( temp3 == NULL ) list3 = newNode;
                else temp3->next = newNode;
                temp2 = temp2->next;
                temp3 = temp3->next;
            }
        }
        while( temp1 != NULL ) {
            ListNode* newNode = new ListNode(temp1->val);
            temp3->next = newNode;
            temp1 = temp1->next;
            temp3 = temp3->next;
        }
        while( temp2 != NULL ) {
            ListNode* newNode = new ListNode(temp2->val);
            temp3->next = newNode;
            temp2 = temp2->next;
            temp3 = temp3->next;
        }
        return list3->next;
    }
};