class Solution {
private:
vector<string> __split(const string& s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while (getline(ss, x, c))
        if (x != "")
            v.emplace_back(x);
    return move(v);
}
public:
    bool wordPattern(string pattern, string s) {
        vector<string> tokens = __split(s, ' ');
        if (tokens.size() != pattern.length())
            return false;
        unordered_map<char,string> m;
        unordered_set<string> seen;
        for (int i = 0; i < pattern.length(); i++) {
            if (!m.count(pattern[i])) {
                m[pattern[i]]=tokens[i];
                if (seen.count(tokens[i]))
                    return false;
                seen.insert(tokens[i]);
            }
            else if (m[pattern[i]]!=tokens[i])
                return false;
        }
        return true;
    }
};
