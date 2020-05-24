class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int sum = 0;
        for (int n : nums)
            sum += n;
        
        sort(nums.begin(), nums.end());
        vector<int> res;
        int sum2 = 0;
        
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum2 += nums[i];
            sum -= nums[i];
            res.push_back(nums[i]);
            
            if (sum2 > sum)
                break;
        }
        return res;
    }
};
