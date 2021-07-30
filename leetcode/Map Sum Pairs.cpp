class MapSum {
private:
    struct Node {
        char val;
        Node *children[26];
        bool end;
        Node(char val) {
            this->val = val;
            this->end = false;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };
    
    unordered_map<string,int> mp;
    Node *root = NULL;
    
private:
    void insert(string &key) {
        Node *node = root;
        for (int i = 0; i < key.length(); i++) {
            if (node->children[key[i]-'a'] == NULL)
                node->children[key[i]-'a'] = new Node(key[i]);    
            node = node->children[key[i]-'a'];
        }
        node->end = true;
    }
    
    int getSum(Node *node, string &prefix, int p, string word) {
        if (node == NULL)
            return 0;
        
        if (p < prefix.length())
            return getSum(node->children[prefix[p]-'a'], prefix, p+1, word + prefix[p]);
        int sum = 0;
        if (node->end)
            sum += mp[word];
        for (int i = 0; i < 26; i++) {
            sum += getSum(node->children[i], prefix, p+1, word + string(1,'a'+i));
        }
        return sum;
    }
    
public:
    /** Initialize your data structure here. */
    MapSum() {
        root = new Node('/');
    }
    
    void insert(string key, int val) {
        if (!mp.count(key))
            insert(key);
        mp[key] = val;
    }
    
    int sum(string prefix) {
        return getSum(root, prefix, 0, "");
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
