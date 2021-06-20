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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode *> s;
        vector<int> ans;
        s.push(root);
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t==NULL)
                continue;
            ans.push_back(t->val);
            s.push(t->right);
            s.push(t->left);
        }
        return ans;
    }
};
