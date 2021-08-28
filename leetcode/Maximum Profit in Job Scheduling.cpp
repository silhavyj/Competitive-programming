class Solution {
    vector<int> dp;
    vector<vector<int>> data;
    
    int solve(int i) {
        if (i >= data.size())
            return 0;
        if (dp[i] != -1)
            return dp[i];
        vector<int> t = {data[i][1], -1, -1};
        int j = lower_bound(data.begin(), data.end(), t) - data.begin();
        int ans = data[i][2] + solve(j);
        ans = max(ans, solve(i+1));
        return dp[i] = ans;
    }
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        for (int i = 0; i < startTime.size(); i++)
            data.push_back({startTime[i], endTime[i], profit[i]});
        dp.resize(data.size(), -1);
        sort(data.begin(), data.end(), [&](auto &d1, auto &d2) {
            return d1[0] <= d2[0];
        });
        return solve(0);
    }
};
