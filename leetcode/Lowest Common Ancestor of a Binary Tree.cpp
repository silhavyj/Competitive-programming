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
    unordered_set<TreeNode *> visited;
    unordered_map<TreeNode *, TreeNode *> par;
    
    void constructParents(TreeNode *curr, TreeNode *parent) {
        if (curr == NULL)
            return;
        par[curr] = parent;
        constructParents(curr->left, curr);
        constructParents(curr->right, curr);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        constructParents(root, NULL);
        TreeNode *tmp = p;
        while (tmp != NULL) {
            visited.insert(tmp);
            tmp = par[tmp];
        }
        tmp = q;
        while (tmp != NULL) {
            if (visited.count(tmp))
                return tmp;
            tmp = par[tmp];
        }
        return NULL;
    }
};
