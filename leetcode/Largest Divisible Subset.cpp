class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        if (nums.empty())
            return ans;
        sort(nums.begin(), nums.end());
        int dp[nums.size()][2];
        int p=nums.size()-1;
        for (int i = nums.size()-1; i >= 0; i--) {
            dp[i][0]=0;
            dp[i][1]=i;
            for (int j = i+1; j < nums.size(); j++)
                if (nums[j] % nums[i] == 0 && dp[j][0] > dp[i][0]) {
                    dp[i][0] = dp[j][0];
                    dp[i][1] = j;
                }
            if (++dp[i][0] > dp[p][0])
                p=i;
        }
        while (dp[p][1]!=p) {
            ans.push_back(nums[p]);
            p=dp[p][1];
        }
        ans.push_back(nums[p]);
        return ans;
    }
};
