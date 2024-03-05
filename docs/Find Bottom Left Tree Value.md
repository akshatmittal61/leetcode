https://leetcode.com/problems/find-bottom-left-tree-value

# Approach 1

1. Create two tracking variables, `dep` and `left`.
2. Create a utility which takes `dep`, `left`, `root` node and the `ans` node.
3. If the node is `NULL`, stop iterating, you have reached the end of tree branch.
4. Reach the max depth for a branch. Update the `left` till you reach the end.
5. Continue to iterate for left and right sub-trees.

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
    void solve(TreeNode* root, int curr, int &depth, int &left) {
        if ( root == NULL )
            return;
        if ( curr > depth ) {
            depth = curr;
            left = root->val;
        }
        solve(root->left, curr + 1, depth, left);
        solve(root->right, curr + 1, depth, left);
    }
    int findBottomLeftValue(TreeNode* root) {
        int dep = 0, left = root->val;
        solve(root, 0, dep, left);
        return left;
    }
};
```