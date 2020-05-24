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
    
    vector<TreeNode*> res;
    
    void dfs(TreeNode** root, unordered_set<int>& s) {
        TreeNode *node = *root;
        if (node == NULL)
            return;

        dfs(&node->left, s);
        dfs(&node->right, s);
        
        if (s.find(node->val) != s.end()) {
            if (node->left != NULL)
                res.push_back(node->left);
            if (node->right != NULL)
                res.push_back(node->right);
            (*root) = NULL;
        }
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> s;
        for (int x : to_delete)
            s.insert(x);
        if (s.find(root->val) == s.end())
            res.push_back(root);
        dfs(&root, s);
        return res;
    }
};
