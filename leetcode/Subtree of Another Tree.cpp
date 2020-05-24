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
    
    bool found = false;
    
    bool in(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL && t != NULL) return false;
        if (s != NULL && t == NULL) return false;  
        if (s != NULL && t != NULL && s->val != t->val)
            return false;
        
        return in(s->left, t->left) && 
               in(s->right, t->right) &&
               t->val == s->val;
    }
    
    void solve(TreeNode* s, TreeNode* t) {
        if (found || s == NULL)
            return;

        solve(s->left, t);
        solve(s->right, t);
         
        if (s->val == t->val) {
            if (in(s,t))
                found = true;
        }
    }
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
        solve(s,t);
        return found;
    }
};
