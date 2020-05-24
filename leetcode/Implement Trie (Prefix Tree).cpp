class Trie {
    
struct Node {
    unordered_map<char,Node*> s;
    bool end=false;
};
    
Node *root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->s.find(c) == curr->s.end())
                curr->s[c] = new Node;
            curr = curr->s[c];
        }
        curr->end=true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node *curr = root;
        for (char c : word) {
            if (curr->s.find(c) == curr->s.end())
                return false;
            curr = curr->s[c];
        }
        return curr->end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node *curr = root;
        for (char c : prefix) {
            if (curr->s.find(c) == curr->s.end())
                return false;
            curr = curr->s[c];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
