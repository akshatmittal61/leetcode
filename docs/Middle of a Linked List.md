https://leetcode.com/problems/middle-of-the-linked-list/

# Approach 1

1. Create two pointers, `slow` and `head`.
2. Initiate them from `head`.
3. Start iterating on list, incrementing `slow` by $1$ and `fast` by $2$ on every iteration.
4. Keep iterating till `fast` reaches the end of list.
5. Return `slow` at the end of iteration.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(1)$

```cpp
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
        ListNode *slow = head, *fast = head;
        while ( fast != NULL && fast->next != NULL ) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};
```