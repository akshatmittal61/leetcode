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
    
    // res store the final result
    
    vector<vector<int>> res;
    
    // curr store the node values from root to leaf
    
    vector<int> curr;
    
    void dfs(TreeNode* root, int curr_sum, int target_sum)
    {
        // base case
        
        if(root == NULL)
            return;
        
        // push the curr node into curr
        
        curr.push_back(root -> val);
        
        // add the curr node to curr_sum
        
        curr_sum += root -> val;
        
        // if we have reached leaf node, then check the condition, if it satisfy the condition, then update the res
        
        if(root -> left == NULL && root -> right == NULL)
        {
            if(curr_sum == target_sum)
            {
                res.push_back(curr);
            }
        }
        
        // call to the left subtree
        
        dfs(root -> left, curr_sum, target_sum);
        
        // call to the right subtree
       
        dfs(root -> right, curr_sum, target_sum);
        
        // backtracking part
        
        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        // call for dfs
        
        dfs(root, 0, targetSum);
        
        return res;
    }
};