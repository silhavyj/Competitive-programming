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
    
    vector<int> nums;
    
    void solve(TreeNode *node) {
        if (node == NULL)
            return;
        
        solve(node->left);
        nums.push_back(node->val);
        solve(node->right);
    }
    
    int minDiffInBST(TreeNode* root) {
        solve(root);
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
            ans = min(ans, nums[i]-nums[i-1]);
        return ans;
    }
};
