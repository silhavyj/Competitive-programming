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
    
    bool solve(TreeNode *root, int sum, int s=0) {
        if (root == NULL)
            return false;
        if (root->left == NULL && root->right == NULL)
            return s+root->val == sum;
        return solve(root->left, sum, s+root->val) ||
               solve(root->right, sum, s+root->val);            
    } 
    
    bool hasPathSum(TreeNode* root, int sum) {
        return solve(root, sum);
    }
};
