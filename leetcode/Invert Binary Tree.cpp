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
    
    TreeNode* solve(TreeNode *root) {
        if (root == NULL)
            return NULL;
            
        if (root->left == NULL && root->right == NULL)
            return new TreeNode(root->val);
        
        TreeNode *r = new TreeNode(root->val);
        r->left = solve(root->right);
        r->right = solve(root->left);
        return r;
    }
    
    TreeNode* invertTree(TreeNode* root) {
        return root == NULL ? NULL : solve(root);
    }
};
