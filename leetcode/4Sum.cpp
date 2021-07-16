class Solution {
    vector<vector<int>> kSum(vector<int>& nums, int target, int start, int k) {
        vector<vector<int>> ans;
        if (start == nums.size() || nums[start] * k > target || target > nums[nums.size()-1] * k)
            return ans;
        if (k==2)
            return twoSum(nums, target, start);
        
        for (int i = start; i < nums.size(); i++)
            if (i == start || nums[i-1] != nums[i])
                for (auto &set : kSum(nums, target - nums[i], i+1, k-1)) {
                    ans.push_back({nums[i]});
                    ans.back().insert(ans.back().end(), set.begin(), set.end());
                }
        return ans;
    }
    
    vector<vector<int>> twoSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> ans;
        int lo = start, hi = nums.size() - 1;
        while (lo < hi) {
            int sum = nums[lo] + nums[hi];
            if (sum < target || (lo > start && nums[lo] == nums[lo-1]))
                lo++;
            else if (sum > target || (hi < nums.size() - 1 && nums[hi] == nums[hi+1]))
                hi--;
            else
                ans.push_back({nums[lo++], nums[hi--]});
        }
        return ans;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        return kSum(nums, target, 0, 4);
    }
};
