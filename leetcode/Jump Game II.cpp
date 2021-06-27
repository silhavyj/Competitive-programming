class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), INT_MAX);
        dp[0]=0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 1; j <= nums[i] && i+j < nums.size(); j++)
                if (dp[i+j] > dp[i]+1)
                    dp[i+j] = dp[i]+1;
        }
        return dp[nums.size()-1];
    }
};
