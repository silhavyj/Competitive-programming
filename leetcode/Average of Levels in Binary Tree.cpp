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
    
    map<int,vector<int>> depths;
    vector<double> ans;
    
    void solve(TreeNode *root, int d) {
        if (root == NULL)
            return;
        depths[d].push_back(root->val);
        solve(root->left, d+1);
        solve(root->right, d+1);
    }
    
    vector<double> averageOfLevels(TreeNode* root) {
        solve(root,0);
        for (auto p : depths) {
            long long sum = 0;
            for (int x : p.second)
                sum += x;
            ans.push_back((double)sum/p.second.size());
        }
        return ans;
    }
};
