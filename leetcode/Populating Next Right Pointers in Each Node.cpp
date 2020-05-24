/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    
    map<int,vector<Node*>> mp;
    
    void solve(Node *root, int d) {
        if (root == NULL)
            return;
        mp[d].push_back(root);
        solve(root->left,d+1);
        solve(root->right,d+1);
    }
    
    Node* connect(Node* root) {
        solve(root,0);
        for (auto p : mp)
            for (int i = 0; i < p.second.size()-1; i++)
                p.second[i]->next = p.second[i+1];
        return root;
    }
};
