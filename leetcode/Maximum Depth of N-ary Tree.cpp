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
    
    int dfs(Node *node) {
        if (node == NULL)
            return 0;
        
        int res = 1;
        for (int i = 0; i < node->children.size(); i++)
            res = max(res, dfs(node->children[i]) + 1);
        return res;
    }
    
    int maxDepth(Node* root) {
        return dfs(root);
    }
};
