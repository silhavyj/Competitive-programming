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
    #define max(x, y) ((x) > (y) ? (x) : (y))
    
    const int MOD = 1e9+7;
    long long ans = INT_MIN;
    int totalSum;
    unordered_map<TreeNode *, int> sums;
    
    int calculateSums(TreeNode *node, int sum) {
        if (node == NULL)
            return 0;
        return sums[node] = node->val + calculateSums(node->left, sum + node->val) + calculateSums(node->right, sum + node->val);
    }
    
    void solve(TreeNode *node) {
        if (node == NULL)
            return;
        long long p;
        if (node->left != NULL) {
            p = (long long)(totalSum - sums[node->left]) * sums[node->left];
            ans = max(ans, p);
        }
        if (node->right != NULL) {
            p = (long long)(totalSum - sums[node->right]) * sums[node->right];
            ans = max(ans, p);
        }
        solve(node->left);
        solve(node->right);
    }
public:
    int maxProduct(TreeNode* root) {
        totalSum = calculateSums(root, 0);
        solve(root);
        return ans % MOD;
    }
};
