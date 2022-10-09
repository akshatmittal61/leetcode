class Solution {
public:
    
    vector<int> arr;
    
    // function for inorder traversal
    
    void dfs(TreeNode* root)
    {
        if(root == NULL)
            return;
        
        dfs(root -> left);
        
        arr.push_back(root -> val);
        
        dfs(root -> right);
    }
    
    bool findTarget(TreeNode* root, int target) {
        
        // store the inorder traversal in arr
        
        dfs(root);
        
        // apply two pointer approach
        
        int i = 0;
        
        int j = arr.size() - 1;
        
        while(i < j)
        {
            if(arr[i] + arr[j] == target)
                return true;
            
            else if(arr[i] + arr[j] < target)
                i++;
            else
                j--;
        }
        
        return false;
    }
};