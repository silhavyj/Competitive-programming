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
    
    map<int,vector<int>> mp;
    
    void dfs(TreeNode *node, int d) {
        if (node == NULL)
            return;
        mp[d].push_back(node->val);
        dfs(node->right, d+1);
        dfs(node->left, d+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        vector<int> ans;
        for (auto p : mp)
            ans.push_back(p.second[0]);
        return ans;
    }
};
