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
    
    int solve(TreeNode *root, string nums="") {
        if (root==NULL)
            return 0;
        if (root->left==NULL && root->right==NULL) {
            nums+=to_string(root->val);
            return stoi(nums);
        }
        return solve(root->left, nums+to_string(root->val))+
               solve(root->right, nums+to_string(root->val));
    }
    
    int sumNumbers(TreeNode* root) {
        return solve(root);
    }
};
