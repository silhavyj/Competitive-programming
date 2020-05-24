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
    
    int ans = INT_MAX;
    
    void solve(TreeNode* root, int depth) {
        if (root->left == NULL && root->right == NULL) {
            ans = min(ans, depth);
            return;
        }
        if (root->left)
            solve(root->left, depth + 1);
        if (root->right)
            solve(root->right, depth + 1);
    }
    
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        solve(root, 1);
        return ans;
    }
};
