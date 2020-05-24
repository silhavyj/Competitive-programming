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
    
    int ans = INT_MIN;
    
    int dfs(TreeNode* node) {
        if (node == NULL)
            return 0;
        
        int left = dfs(node->left);
        int right = dfs(node->right);
        
        int val = max({node->val, left + node->val, right + node->val});
        ans = max({ans, val, left + right + node->val});
        return max(val, 0);
    }
    
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
