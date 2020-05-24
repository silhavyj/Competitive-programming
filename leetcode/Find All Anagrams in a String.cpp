class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if (s.length() < p.length())
            return ans;

        int mp[26], used[26];
        int j = p.length();
        bool found;

        memset(mp, 0, sizeof(mp));
        memset(used, 0, sizeof(used));

        for (char c : p)
            mp[c-'a']++;

        for (int i = 0; i < p.length(); i++)
            used[s[i]-'a']++;

        for (int k = 0;; k++) {
            found = true;
            for (int i = 0; i < 26 && found; i++)
                found &= (used[i] == mp[i]);
            if (found)
                ans.push_back(k);

            if (j+k == s.length())
                break;
            used[s[k]-'a']--;
            used[s[j+k]-'a']++;
        }
        return ans;
    }
};
