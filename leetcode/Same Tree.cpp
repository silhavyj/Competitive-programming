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
    
    void solve(TreeNode* p, TreeNode* q) {
        if (is == false)
            return;
        if ((p == NULL && q != NULL) || (p != NULL && q == NULL)) {
            is = false;
            return;
        }
        if (p == NULL && q == NULL)
            return;
        if (p->val != q->val) {
            is = false;
            return;
        }
        solve(p->left, q->left);
        solve(p->right, q->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        solve(p,q);
        return is;
    }
};
