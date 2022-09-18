/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void PreOrder(Node* n, vector<int>&v){
        if(n!=NULL)v.push_back(n->val);
        if(n->children.size()!=0){
            for(auto i:n->children){
                PreOrder(i,v);
            }
        }
    }
    vector<int> preorder(Node* root) {
        vector<int>v;
        if(root!=NULL)PreOrder(root,v);
        return v;
    }
};