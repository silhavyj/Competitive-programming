class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        
        int n = nums.size();
        int sum[n];
        
        for (int i = 0; i < n; i++)
            sum[i] = (i ? (sum[i-1] + nums[i]) : nums[i]); 
        
        for (int i = 0; i < n; i++) {
            if (!i) {
                if (sum[n-1]-sum[0] == 0)
                    return 0;
            }
            else if (sum[i-1] == sum[n-1]-sum[i])
                return i;
        }
        return -1;
    }
};
