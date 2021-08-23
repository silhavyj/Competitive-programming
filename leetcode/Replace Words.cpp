class Solution {
    struct Node {
        Node *children[26];
        bool end;
        Node() {
            end = false;
            for (int i = 0; i < 26; i++)
                children[i]=NULL;
        }
    };
    Node *root = new Node;
    
    vector<string> __split(const string& s, char c) {
        vector<string> v;
        stringstream ss(s);
        string x;
        while (getline(ss, x, c))
            if (x!="")
                v.emplace_back(x);
        return move(v);
    }
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Node *curr;
        for (auto &word : dictionary) {
            curr = root;
            for (auto &c : word) {
                if (curr->children[c-'a'] == NULL)
                    curr->children[c-'a'] = new Node;
                curr = curr->children[c-'a'];
            }
            curr->end = true;
        }
        vector<string> words = __split(sentence, ' ');
        stringstream ss;
        for (auto &word : words) {
            curr = root;
            string prefix = "";
            for (char c : word) {
                if (curr->children[c-'a'] == NULL || curr->end)
                    break;
                curr = curr->children[c-'a'];
                prefix += c;
            }
            if (curr->end)
                ss << prefix << " ";
            else
                ss << word << " ";
        }
        string ans = ss.str();
        ans.pop_back();
        return ans;
    }
};
