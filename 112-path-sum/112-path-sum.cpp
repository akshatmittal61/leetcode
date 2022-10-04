/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool hasPathSum(TreeNode *root, int targetSum)
        {
            bool temp = false;
            if (!root)
            {
                return false;
            }
            if (root->left) temp |= hasPathSum(root->left, targetSum - root->val);
            if (root->right) temp |= hasPathSum(root->right, targetSum - root->val);
            if (!root->left && !root->right)
            {
                if (root->val == targetSum) return true;
                return false;
            }
            return temp;
        }
};