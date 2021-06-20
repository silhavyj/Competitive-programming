class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;
        map<char,int> m;
        for (char c : s) {
            if (!m.count(c))
                m[c]=1;
            else
                m[c]++;
        }
        for (char c : t) {
            if (m.find(c)==m.end() || m[c]==0)
                return false;
            else
                m[c]--;
        }
        return true;
    }
};
