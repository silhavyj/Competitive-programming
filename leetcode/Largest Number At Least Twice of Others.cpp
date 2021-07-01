class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> pos;
        for (int i = 0; i < n; i++)
            pos[nums[i]]=i;
        sort(nums.begin(), nums.end());
        if (n==1 || nums[n-1] >= 2*nums[n-2])
            return pos[nums[n-1]];
        return -1;
    }
};
