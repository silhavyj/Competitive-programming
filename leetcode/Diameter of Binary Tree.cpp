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
    
    /*int ans = -1;
        
    int getDepth(TreeNode* node, int depth) {
        if (node == NULL)
            return depth;
        
        return max(getDepth(node->left, depth+1),
                   getDepth(node->right, depth+1));
    }
    
    void solve(TreeNode* node) {
        if (node == NULL)
            return;
        
        solve(node->left);
        ans = max(ans, getDepth(node->left, 0) + getDepth(node->right, 0));
        solve(node->right);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        
        solve(root);
        return ans;
    }*/
    
    int ans = 0;
    
    int depth(TreeNode *node) {
        if (node == NULL)
            return 0;
        
        int left = depth(node->left);
        int right = depth(node->right);
        
        ans = max(ans, left + right);
        return max(left, right) + 1;
    } 
    
    int diameterOfBinaryTree(TreeNode* root) {
        depth(root);
        return ans;
    }
};
