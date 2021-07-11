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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        vector<int> vals;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t==NULL)
                continue;
            if (t->val >= low && t->val <= high)
                vals.push_back(t->val);
            s.push(t->left);
            s.push(t->right);
        }
        TreeNode *ans = NULL;
        for (int x : vals) {
            ans = add(ans, x);
        }
        return ans;
    }
};
