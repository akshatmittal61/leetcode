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
private:
	void f(TreeNode* root, int val, int depth, int curr) {
		if (!root) return;
		if (curr + 1 == depth) {
			TreeNode *l = new TreeNode(val);
			l->left = root->left;
			TreeNode *r = new TreeNode(val);
			r->right = root->right;
			root->left = l;
			root->right = r;
			return;
		}
		f(root->left, val, depth, curr + 1);
		f(root->right, val, depth, curr + 1);
	}
public:
	TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
			TreeNode *l = new TreeNode(val);
			l->left = root;
            return l;
        }
		f(root, val, depth, 1);
		return root;
	}
};