class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> left(nums.size());
        vector<int> right(nums.size());
        
        left[0] = nums[0];
        right[nums.size()-1] = nums[nums.size()-1];
        
        for (int i = 1; i < nums.size(); i++)
            left[i] = max(left[i-1], nums[i]); 
        
        for (int i = nums.size() - 2; i >= 0; i--)
            right[i] = min(right[i+1], nums[i]);
        
        for (int i = 1; i < nums.size(); i++)
            if (left[i-1] <= right[i])
                return i;
        return -1;
    }
};
