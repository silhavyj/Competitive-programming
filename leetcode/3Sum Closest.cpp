class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int ans = nums[0] + nums[1] + nums[nums.size()-1];
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int l = i+1;
            int r = nums.size()-1;    
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (abs(sum-target) < abs(ans-target))
                    ans = sum;
                if (sum > target)
                    r--;
                else
                    l++;
            }
        }
        return ans;
    }
};
