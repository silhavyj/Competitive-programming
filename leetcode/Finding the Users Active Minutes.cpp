class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int,unordered_set<int>> mp;
        for (auto &log : logs)
            mp[log[0]].insert(log[1]);
        vector<int> ans(k,0);
        unordered_map<int,int> lookup;
        for (auto &p : mp)
            lookup[p.second.size()]++;
        for (int i = 1; i <= k; i++) {
            ans[i-1] = lookup[i];
        }
        return ans;
    }
};
