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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return NULL;
        
        TreeNode *node = root;
        TreeNode *parent = NULL;
        
        while (node != NULL && node->val != key) {
            parent = node;
            if (node->val < key)
                node = node->right;
            else node = node->left;
        }
        if (node == NULL)
            return root;
        
        TreeNode *far_left = node->right;
        TreeNode *far_left_parent = node;
        
        if (far_left == NULL) {
            if (node == root)
                return node->left;
            if (parent != NULL) {
                if (parent->right == node)
                    parent->right = node->left;
                else parent->left = node->left;   
            }
            return root;
        }
        
        while (far_left->left != NULL) {
            far_left_parent = far_left;
            far_left = far_left->left;
        }
        if (far_left_parent->right == far_left)
            far_left_parent->right = far_left->right;
        else far_left_parent->left = far_left->right;
    
        far_left->left = node->left;
        far_left->right = node->right;
        
        if (parent == NULL)
            return far_left;
        
        if (parent->left == node)
            parent->left = far_left;
        else parent->right = far_left;
        
        return root;
    }
};
