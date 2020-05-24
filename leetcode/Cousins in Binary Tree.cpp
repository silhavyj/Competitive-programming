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
    
    int ans;
    int par_val;
    
    void find(TreeNode* root, int x, int d, int par) {
        if (root == NULL)
            return;
        if (root->val == x) {
            ans = d;
            par_val = par;
            return;
        }
        if (ans != INT_MAX)
            return;
        
        find(root->right, x, d+1, root->val);
        find(root->left, x, d+1, root->val);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        ans = INT_MAX;
        find(root, x, 0, -1);
        
        int d1=ans;
        int p1=par_val;
        
        ans = INT_MAX;
        find(root, y, 0, -1);
        
        int d2=ans;
        int p2=par_val;
        
        return d1==d2 && p1!=p2;
    }
};
