class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_set<char> dic = {'b','a','l','o','n'};
        unordered_map<char,int> mp;
        for (char t : text)
            if (dic.count(t))
                mp[t]++;
        if (mp.size()!=dic.size() || mp['l']<2 || mp['o']<2)
            return 0;
        int ans = INT_MAX;
        for (auto p : mp) {
            if (p.first=='l' || p.first=='o') {
                ans = min(ans, p.second/2);
            }
            else
                ans = min(ans, p.second);
        }
        return ans;
    }
};
