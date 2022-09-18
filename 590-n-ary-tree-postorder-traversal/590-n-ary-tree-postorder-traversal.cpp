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
    void PostOrder(Node* n, vector<int>&v){
        if(n!=NULL)
        {
        if(n->children.size()!=0){
            for(auto i:n->children){
                PostOrder(i,v);
            }
        }
        v.push_back(n->val);
        }
    }
    vector<int> postorder(Node* root) {
        vector<int>v;
        if(root!=NULL)PostOrder(root,v);
        return v;
    }
};
