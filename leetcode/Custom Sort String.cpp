class Solution {
public:
    string customSortString(string order, string str) {
        map<char,vector<int>> mp;
        vector<bool> used(str.length(),false);
        for (int i = 0; i < str.length(); i++)
            mp[str[i]].push_back(i);
        string ans = "";
        for (char c : order) {
            for (int i : mp[c]) {
                used[i]=true;
                ans += c;
            }
        }
        for (int i = 0; i < str.length(); i++)
            if (!used[i])
                ans += str[i];
        return ans;
    }
};
