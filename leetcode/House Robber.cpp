class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int dp[nums.size() + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[1] = nums[0];
        for (int i = 1; i < nums.size(); i++)
            dp[i+1] = max(dp[i], nums[i] + dp[i-1]);
        return dp[nums.size()];
    }
};
