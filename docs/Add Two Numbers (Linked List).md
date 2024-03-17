https://leetcode.com/problems/add-two-numbers

# Approach 1

1. Create a new linked list `ans`.
2. Create two variables, `carry` and `curr`, and initiate them by $0$.
3. Start iterating on both linked list.
4. Get the `curr` by adding the value of current nodes and also add the `carry` if it has some value from previous iteration.
5. If the `ans` list is empty, initiate it, else insert at the end of it.
6. Get the value of `carry` -> one's digit of the sum of current node's values and the previous carry.
7. Continue the iteration even if one of list is not completely iterated.
8. If after iteration, `carry` still has some value, insert that to `ans` list.
9. Return the head to `ans` list.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

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
```


# Approach 2

1. We don't need multiple iterations.
2. By using right conditions, it can be done in one iteration itself.

**Time Complexity**: $O(n)$
**Space Complexity**: $O(n)$

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0, curr = 0;
        ListNode* ans = NULL;
        ListNode* temp = ans;
        ListNode* temp1 = l1;
        ListNode* temp2 = l2;
        while ( temp1 != NULL || temp2 != NULL || carry != 0 ) {
            int s = 0;
            if (temp1 != NULL)
                s += temp1->val;
            if (temp2 != NULL)
                s += temp2->val;
            curr = (carry + s) % 10;
            ListNode* nd = new ListNode(curr);
            if ( temp == NULL )
                temp = nd, ans = nd;
            else {
                temp->next = nd;
                temp = temp->next;
            }
            carry = (carry + s) / 10;
            if (temp1 != NULL)
                temp1 = temp1->next;
            if (temp2 != NULL)
                temp2 = temp2->next;
        }
        return ans;
    }
};
```