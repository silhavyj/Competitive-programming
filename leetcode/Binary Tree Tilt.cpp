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
    
    int ans = 0;
    
    int solve(TreeNode *node) {    
        if (node == NULL)
            return 0;
        
        int left = solve(node->left);
        int right = solve(node->right);
        ans += abs(left-right);
        return node->val + left + right;
    }
    
    int findTilt(TreeNode* root) {
        solve(root);
        return ans;
    }
};
