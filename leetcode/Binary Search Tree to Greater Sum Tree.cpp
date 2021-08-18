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
    vector<int> vals;
    
    void dfs(TreeNode *node) {
        if (node == NULL)
            return;
        vals.push_back(node->val);
        dfs(node->left);
        dfs(node->right);
    }
    
    TreeNode *create(TreeNode *originalNode, vector<int> &newVals, int &index) {
        if (originalNode == NULL)
            return NULL;
        TreeNode *node = new TreeNode(0);
        node->left = create(originalNode->left, newVals, index);
        node->val = newVals[index++];
        node->right = create(originalNode->right, newVals, index);
        return node;
    }
public:
    TreeNode* bstToGst(TreeNode* root) {
        dfs(root);
        sort(vals.begin(), vals.end());
        vector<int> sums(vals.begin(), vals.end());
        for (int i = 1; i < sums.size(); i++)
            sums[i] += sums[i-1];
        
        vector<int> newVals(sums.size());
        for (int i = 0; i < sums.size(); i++) {
            if (i == 0) {
                newVals[i] = sums[sums.size()-1];
            } else {
                newVals[i] = sums[sums.size()-1] - sums[i-1];
            }
        }   
        int index = 0;
        TreeNode *ans = create(root, newVals, index);
        return ans;
    }
};
