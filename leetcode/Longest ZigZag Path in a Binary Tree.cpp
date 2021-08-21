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
    int ans = 0;
    
    void solve(TreeNode *node, bool toLeft, int len) {
        if (node == NULL)
            return;
        ans = max(ans, len);
        if (toLeft) {
            solve(node->left, false, len + 1);
            solve(node->right, true, 1);
        } else {
            solve(node->right, true, len + 1);
            solve(node->left, false, 1);
        }
    }
    
public:
    int longestZigZag(TreeNode* root) {
        solve(root, true, 0);
        return ans;
    }
};
