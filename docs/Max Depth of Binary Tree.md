
https://leetcode.com/problems/maximum-depth-of-binary-tree

# Approach 1

1. Calculate the `maxDepth` of both left and right subtrees.
2. Return `1 + result_of_above_expression`;
3. For base case, check if the $root$ is `NULL`.
4. If yes, then there is no tree, return $0$.
5. If the root is not $NULL$, but it is a leaf node, i.e.) its $left$ and $right$ are `NULL`, return 1;

**Time Complexity**: $O(log(n))$
**Space Compelxity**: $O(1)$

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
    int maxDepth(TreeNode* root) {
        if ( root == NULL )
            return 0;
        if ( root->left == NULL && root->right == NULL )
            return 1;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};
```