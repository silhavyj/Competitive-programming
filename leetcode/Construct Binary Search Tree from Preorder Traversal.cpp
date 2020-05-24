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
    
    TreeNode* add(TreeNode *root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        
        if (val < root->val)
            root->left = add(root->left, val);
        else root->right = add(root->right, val);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root = NULL;
        
        for (int x : preorder)
            root = add(root, x);
        
        return root;
    }
};
