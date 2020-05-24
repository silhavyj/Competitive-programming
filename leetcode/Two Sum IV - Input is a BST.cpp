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
    
    bool found = false;
    unordered_set<int> s;
    
    void dfs(TreeNode *root, int k) {
        if (root == NULL || found)
            return;
        if (s.find(root->val) != s.end()) {
            found = true;
            return;
        }
        s.insert(k-root->val);
        dfs(root->left, k);
        dfs(root->right, k);
    }
    
    bool findTarget(TreeNode* root, int k) {
        dfs(root,k);
        return found;
    }
};
