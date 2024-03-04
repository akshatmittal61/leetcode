https://leetcode.com/problems/same-tree

# Approach 1

1. Check recursively if the left subtree of both trees and same and check the same for right subtree too.
2. If both the nodes are $null$, return `true`.
3. If one of the node is $null$, but the other is not, or their value is different return `false`.

**Time Complexity**: $O(log(n))$
**Space Complexity**: $O(1)$

```cpp
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q)
            return true;
        if(!p || !q || p->val != q->val)
            return false;
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
```