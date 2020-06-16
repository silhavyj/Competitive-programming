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
    
    vector<vector<int>> ans;
    
    void solve(TreeNode *root, int sum, int s, vector<int>& p) {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL && s+root->val == sum) {
            p.push_back(root->val);
            ans.push_back(p);
            p.pop_back();
            return;
        }
        p.push_back(root->val);
        solve(root->left, sum, s+root->val, p);
        solve(root->right, sum, s+root->val, p);
        p.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<int> p;
        solve(root, sum, 0, p);
        return ans;
    }
};
