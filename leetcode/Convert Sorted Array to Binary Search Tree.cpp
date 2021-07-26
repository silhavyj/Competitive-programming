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
    
    TreeNode *create(vector<int> &nums, int l, int r) {
        if (r == l)
            return new TreeNode(nums[l]);
        if (r < l)
            return NULL;
        int m = l + (r-l) / 2;
        if ((r-l+1) & 1 == 0)
            m++;
        TreeNode *node = new TreeNode(nums[m]);
        node->left = create(nums, l, m-1);
        node->right = create(nums, m+1, r);
        return node;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size()-1);
    }
};
