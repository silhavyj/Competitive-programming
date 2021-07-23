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
    unordered_map<TreeNode*,TreeNode*> par;
    
    bool solve(TreeNode *&node, int d) {
        if (node==NULL)
            return false;
                
        bool left = solve(node->left, d+1);
        bool right = solve(node->right, d+1);
        
        if (!(left || right || node->val == 1)) {
            TreeNode *parent = par[node];
            if (parent == NULL)
                node = NULL;
            else if (parent->left == node)
                parent->left = NULL;
            else
                parent->right = NULL;
            return false;
        }
        return true;
    }
    
    void findParents(TreeNode *node, TreeNode *parent) {
        if (node==NULL)
            return;
        par[node] = parent;
        findParents(node->left, node);
        findParents(node->right, node);
    }
    
public:
    TreeNode* pruneTree(TreeNode* root) {
        findParents(root, NULL);
        solve(root, 0);
        return root;
    }
};
