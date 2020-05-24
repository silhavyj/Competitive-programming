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
    
    bool valid = false;
    
    void solve(TreeNode* root, vector<int>& arr, int index) {
        if (valid || index >= arr.size() || root == NULL)
            return;
        
        if (root->val == arr[index] && index == arr.size()-1 && root->left == NULL && root->right == NULL) {
            valid = true;
            return;
        }
        if (root->val == arr[index]) {
            solve(root->left, arr, index+1);
            solve(root->right, arr, index+1);
        }
    }
    
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        solve(root, arr, 0);
        return valid;
    }
};
