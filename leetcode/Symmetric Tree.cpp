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
    
    unordered_map<string,int> vals;
    
    void isSymetric(TreeNode *curr, string path) {
        if (curr == NULL)
            return;
        
        isSymetric(curr->left, path + "L");
        vals[path] = curr->val;
        isSymetric(curr->right, path + "R");
    }
    
    string getMirror(string path) {
        string m = "";
        for (char c : path) {
            if (c == 'L') 
                m += "R";
            else m += "L";
        }
        return m;
    }
    
    bool isSymmetric(TreeNode* root) {
        isSymetric(root, "");
        string m;
        for (auto p : vals) {
            m = getMirror(p.first);
            if (vals.find(m) == vals.end() || vals[m] != p.second)
                return false;
        }
        return true;
    }
};
