/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    
    vector<int> ans;
    unordered_map<int,int> mp;
    
    int solve(TreeNode *root) {
        if (root == NULL)
            return 0;
        int sum = root->val;
        sum += solve(root->left);
        sum += solve(root->right);
        mp[sum]++;
        return sum;
    }
    
    vector<int> findFrequentTreeSum(TreeNode* root) {
        solve(root);
        int m = 0;
        for (auto p : mp)
            m = max(m, p.second);
        for (auto p : mp)
            if (p.second == m)
                ans.push_back(p.first);
        return ans;
    }
};
