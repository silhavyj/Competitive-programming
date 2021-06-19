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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<int,TreeNode*>> s;
        s.push({0,root});
        
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            if (t.second==NULL)
                continue;
            if (t.first==0) {
                s.push({0,t.second->right});
                s.push({1,t.second});
                s.push({0,t.second->left});
            } else if (t.first==1) {
                ans.push_back(t.second->val);
            }
        }
        return ans;
    }
};
