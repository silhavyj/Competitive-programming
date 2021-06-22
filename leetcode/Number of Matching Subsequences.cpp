class Solution {
public:
    bool check(string &s, string &w) {
        int i = 0;
        for (char c : s) {
            if (c == w[i])
                i++;
            if (i == w.length())
                return true;
        }
        return false;
    }
    
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans = 0;
        unordered_map<string,int> seen;
        for (string &w : words) {
            if (seen.count(w))
                ans += seen[w];
            else if (w.size() <= s.size())
                ans += (seen[w]=check(s,w));
        }
        return ans;
    }
};
