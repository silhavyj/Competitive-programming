/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    
    void solve(vector<ListNode *> &nums, int left, int right) {
        if (left > right)
            return;
        
        int mid = (left + right) / 2;
        root = add(root, nums[mid]->val);
        solve(nums, left, mid-1);
        solve(nums, mid+1, right);
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        vector<ListNode *> nums;
        
        ListNode *curr = head;
        while (curr != NULL) {
            nums.push_back(curr);
            curr = curr->next;
        }
        solve(nums, 0, nums.size()-1);
        return root;
    }
};
