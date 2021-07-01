/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
private:
    string ans;
    TreeNode *root;
    
    vector<string> __split(const string& s, char c) {
        vector<string> v;
        stringstream ss(s);
        string x;
        while (getline(ss, x, c))
            if (x != "")
                v.emplace_back(x);
        return move(v);
    }
    
    void preorder(TreeNode *node) {
        if (node == NULL)
            return;
        ans += to_string(node->val) + ",";
        preorder(node->left);
        preorder(node->right);
    }
    
    TreeNode *insert(TreeNode *node, int val) {
        if (node == NULL)
            return new TreeNode(val);
        if (val > node->val)
            node->right = insert(node->right, val);
        else
            node->left = insert(node->left, val);
        return node;
    }
    
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ans = "";
        preorder(root);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> vals = __split(data, ',');
        root = NULL;
        for (string v : vals)
            root = insert(root, atoi(v.c_str()));
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;
