class Solution {
public:
    bool isIsomorphic(string s, string t) {
        assert(s.length() == t.length());
        unordered_map<char,char> mp;
        unordered_set<char> taken;
        for (int i = 0; i < s.length(); i++) {
            if (mp.count(s[i]) && mp[s[i]] != t[i])
                return false;
            if (!mp.count(s[i])) {
                if (taken.count(t[i]))
                    return false;
                mp[s[i]] = t[i];
                taken.insert(t[i]);
            }
        }
        return true;
    }
};
