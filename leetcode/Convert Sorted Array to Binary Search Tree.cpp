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
    
    TreeNode *root = NULL;
    
    TreeNode *add(TreeNode *node, int val) {
        if (node == NULL)
            return new TreeNode(val);
        if (val < node->val)
            node->left = add(node->left, val);
        else node->right = add(node->right, val);
        return node;
    }
     
    void solve(vector<int>& nums, int left, int right) {
        if (left > right)
            return;
        
        int mid = (left + right) / 2;
        root = add(root, nums[mid]);
        solve(nums, left, mid-1);
        solve(nums, mid+1, right);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        solve(nums, 0, nums.size()-1);
        return root;
    }
};
