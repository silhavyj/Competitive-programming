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
private:
    
    vector<TreeNode *> ans;
    
    bool same(TreeNode *n1, TreeNode *n2) {
        if ((n1 == NULL && n2 != NULL) || (n2 == NULL && n1 != NULL))
            return false;
        if (n1 == NULL && n2 == NULL)
            return true;
        return same(n1->left, n2->left) && same(n1->right, n2->right);
    }
    
    TreeNode *add(TreeNode *node, int val) {
        if (node == NULL)
            return new TreeNode(val);
        if (val > node->val)
            node->right = add(node->right, val);
        else
            node->left = add(node->left, val);
        return node;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<int> nodes(n);
        for (int i = 1; i <= n; i++)
            nodes[i-1] = i;
        do {
            TreeNode *root = NULL;
            for (int n : nodes)
                root = add(root, n);
            bool ok=true;
            for (TreeNode *r : ans)
                if (same(r,root)) {
                    ok = false;
                    break;
                }
            if (ok)
                ans.push_back(root);
        } while (next_permutation(nodes.begin(), nodes.end()));
        return ans;
    }
};
