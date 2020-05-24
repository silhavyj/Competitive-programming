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
    vector<int> nums;
    
    void solve(TreeNode *root) {
        if (root == NULL)
            return;
        nums.push_back(root->val);
        solve(root->left);
        solve(root->right);
    }
    
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        solve(root);
        root->left = root->right = NULL;
        root->val = nums[0];
        TreeNode *curr = root;
        for (int i = 1; i < nums.size(); i++) {
            curr->right = new TreeNode(nums[i]);
            curr = curr->right;
        }
    }
};
