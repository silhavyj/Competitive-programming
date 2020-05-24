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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<TreeNode *> level;
        vector<vector<int>> res;
        
        if (root == NULL)
            return res;
        
        level.push_back(root);
        
        while (level.size() != 0) {
            vector<int> line;
            vector<TreeNode *> next; 
            for (auto n : level) {
                line.push_back(n->val);
                if (n->left != NULL) next.push_back(n->left);
                if (n->right != NULL) next.push_back(n->right);
            }
            res.insert(res.begin(), line);
            level = next;
        }
        return res;
    }
};
