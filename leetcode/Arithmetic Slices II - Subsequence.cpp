class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        #define ll long long
        int ans = 0;
        vector<unordered_map<ll,ll>> dp(nums.size());
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                ll diff = (ll)nums[i]-nums[j];
                if (dp[j].count(diff)) {
                    dp[i][diff] += (dp[j][diff]+1);
                    ans += dp[j][diff];
                } else {
                    dp[i][diff]+=1;
                }
            }
        }
        return ans;
    }
};
