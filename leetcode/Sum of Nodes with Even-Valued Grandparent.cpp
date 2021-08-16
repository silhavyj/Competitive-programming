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
    unordered_map<TreeNode *, TreeNode *> parent;
    
    void findParents(TreeNode *curr, TreeNode *par) {
        if (curr == NULL)
            return;
        parent[curr] = par;
        findParents(curr->left, curr);
        findParents(curr->right, curr);
    }
    
    int solve(TreeNode *curr) {
        if (curr == NULL)
            return 0;
        int ans = 0;
        if (parent[curr] != NULL && parent[parent[curr]] != NULL && parent[parent[curr]]->val % 2 == 0)
            ans += curr->val;
        ans += solve(curr->left);
        ans += solve(curr->right);
        return ans;
    }
public:
    int sumEvenGrandparent(TreeNode* root) {
        findParents(root, NULL);
        return solve(root);
    }
};
