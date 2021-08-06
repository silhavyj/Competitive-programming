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
    map<int,vector<int>> lv;
    void solve(Node *node, int d) {
        if (node == NULL)
            return;
        lv[d].push_back(node->val);
        for (Node *child : node->children)
            solve(child, d+1);
    }
public:
    vector<vector<int>> levelOrder(Node* root) {
        solve(root,0);
        vector<vector<int>> ans;
        for (auto l : lv)
            ans.push_back(l.second);
        return ans;
    }
};
