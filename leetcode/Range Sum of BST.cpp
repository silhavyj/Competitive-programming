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
    
    void solve(TreeNode *node, int L, int R) {
        if (node == NULL)
            return;
        
        solve(node->left, L, R);
        if (node->val >= L && node->val <= R)
            ans += node->val;
        solve(node->right, L, R);
    }
    
    int rangeSumBST(TreeNode* root, int L, int R) {
        solve(root, L, R);
        return ans;
    }
};
