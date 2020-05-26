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
    
    bool is = true;
    typedef long long ll;
    
    bool solve(TreeNode *root, ll left, ll right) {
        if (root == NULL)
            return true;
        if (root->val < left || root->val > right)
            return false;
        return solve(root->left, left, (ll)root->val-1) &&
               solve(root->right, (ll)root->val+1, right);
    }
    
    bool isValidBST(TreeNode* root) {
        return solve(root, INT_MIN, INT_MAX);
    }
};
