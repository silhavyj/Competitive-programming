class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
    bool dp[n];
        
    memset(dp, false, sizeof(dp));
    dp[0] = true;
        
    for (int i = 0; i < n; i++) {
        if (!dp[i])
            continue;
         
		for (int j = i; j <= i+nums[i]; j++) {
			if (j >= n)
				break;
			dp[j] = true;
		}  
    }
    return dp[n-1];
    }
};
