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
    
    int ans=0;
    
    void solve(TreeNode *root, string path)  {
        if (root == NULL)
            return;
        path += (char)('0' + root->val);
        if (root->left == NULL && root->right == NULL) {
            //cout << path << endl;
            bool ok = 1;
            unordered_map<char,int> mp;
            for (char c : path)
                mp[c]++;
            if (path.length() & 1) {
                int odd = 0;
                for (auto p : mp)
                    if (p.second & 1) {
                        if (++odd == 2)
                            return;
                    }
            }
            else {
                for (auto p : mp)
                    if (p.second & 1)
                        return;
            }
            ans++;
            return;
        }        
        solve(root->left, path);
        solve(root->right, path);
    }   
    
    int pseudoPalindromicPaths (TreeNode* root) {
        solve(root, "");
        return ans;
    }
};
