https://leetcode.com/problems/linked-list-cycle/

# Approach 1

1. Create a hash-set of linked list nodes.
2. Start iterating on the list.
3. If a node is found in the set, i.e.) that node has already been iterated and that means a loop exists, return `true`.
4. If no node is iterated, return `false`.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

```cpp
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
    }
};
```