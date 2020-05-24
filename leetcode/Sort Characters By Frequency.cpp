class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        vector<char> uniq;
        for (char c : s) {
            mp[c]++;
            if (mp[c]==1)
                uniq.emplace_back(c);
        }
        sort(uniq.begin(),uniq.end(), [&](char c1, char c2) {
           return mp[c1] > mp[c2]; 
        });
        string ans = "";
        for (char c : uniq)
            for (int i = 0; i < mp[c]; i++)
                ans += c;
        return ans;
    }
};
