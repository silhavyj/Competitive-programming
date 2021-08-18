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
    vector<int> nums;
    
    void dfs(TreeNode *node) {
        if (node == NULL)
            return;
        nums.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
public:
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        sort(nums.begin(), nums.end());
        int ans = INT_MAX;
        for (int i = 1; i < nums.size(); i++)
             ans = min(ans, abs(nums[i]-nums[i-1]));
        return ans;
    }
};
