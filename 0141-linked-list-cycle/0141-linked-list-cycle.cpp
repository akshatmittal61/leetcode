/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if( head == NULL || head->next == NULL ) {
	        return false;
        }
        set<ListNode*> s;
        ListNode *temp = head;
        while( temp != NULL ) {
            if( s.find(temp) != s.end() ) return true;
            s.insert(temp);
            temp = temp->next;
        }
        return false;
        /* ListNode *slow = head, *fast = head->next;
        while( slow != fast && fast->next != slow ) {
        	if( fast == NULL || fast->next == NULL ) {
                break;
            }
    	    slow = slow->next;
    	    fast = fast->next->next;
        }

        if(slow == fast || fast->next == slow) {
    	    return true;
        } else {
            return false;
        } */
    }
};