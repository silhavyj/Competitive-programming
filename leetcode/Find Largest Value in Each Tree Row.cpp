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
    /*

    key val (list)
    --------------
    0 - 1
    1 - 3 2
    2 - 5 3 9
        
    */
    
    map<int,vector<int>> mp;
    
    void solve(TreeNode* root, int depth) {
        if (root == NULL)
            return;
        
        solve(root->left, depth + 1);
        solve(root->right, depth + 1);
        
        if (mp.find(depth) != mp.end())
            mp[depth].push_back(root->val);
        else {
            vector<int> row = {root->val};
            mp[depth] = row;
        }
    }
    
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        solve(root, 0);
        for (auto row : mp) {
            int e = INT_MIN;
            for (int x : row.second)
                e = max(e, x);
            ans.push_back(e);
        }
        return ans;
    }
};
