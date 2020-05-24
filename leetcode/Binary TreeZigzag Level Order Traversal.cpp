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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
         vector<TreeNode *> level;
        vector<vector<int>> res;
        
        if (root == NULL)
            return res;
        
        level.push_back(root);
        bool even = false;
        
        while (level.size() != 0) {
            vector<int> line;
            vector<TreeNode *> next;
            int n = level.size();
            
            for (int i = 0; i < n; i++) {
                if (!even)
                    line.push_back(level[i]->val);
                else line.push_back(level[n-i-1]->val);
                
                if (level[i]->left != NULL) next.push_back(level[i]->left);
                if (level[i]->right != NULL) next.push_back(level[i]->right);
            }
            res.push_back(line);
            even = !even;
            level = next;
        }
        return res;
    }
};
