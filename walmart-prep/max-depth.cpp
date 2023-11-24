#include <iostream>
#include <unordered_map>

using namespace std;

int maxDepthOfBinaryTree (Tree* root) {
    if(!root) return 0;
        int maxLeft = maxDepthOfBinaryTree(root->left);
        int maxRight = maxDepthOfBinaryTree(root->right);
        return max(maxLeft, maxRight)+1
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left= new TreeNode(15);
    root->right->right = new TreeNode(7);
    cout << maxDepthOfBinaryTree(root) << endl;
    return 0;
}
