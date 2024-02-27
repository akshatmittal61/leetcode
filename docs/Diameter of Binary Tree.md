https://leetcode.com/problems/diameter-of-binary-tree/

# Approach 1

1. Create a utility which calculates diameter, for every node and stores in a global variable.
2. Also this calculates the max depth for each node and returns that for the next node to use.
3. In the utility, calculate the max depth of left sub-tree and right sub-tree by recursing on this utility.
4. Assign the `max` if `diameter` and sum of max depth of left and right sub-tree.
5. Return the final diameter.

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
    int solve(TreeNode* root, int &dia) {
        if ( root == NULL )
            return 0;
        int lh = solve(root->left, dia);
        int rh = solve(root->right, dia);
        dia = max(dia, lh + rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        solve(root, dia);
        return dia;
    }
};
```