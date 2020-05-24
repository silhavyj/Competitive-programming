class Solution {
public:
    
    int bs(int l, int r, vector<int>& nums) {
        if (l == r)
            return nums[l];
        if (l == r-1)
            return min(nums[l],nums[r]);
        int m = l+(r-l)/2;
        if (nums[l] == nums[r])
            return min(bs(l,m,nums),bs(m+1,r,nums));
        if (nums[m] > nums[r])
            return bs(m,r,nums);
        return bs(l,m,nums);
    }
    
    int findMin(vector<int>& nums) {
        if (nums[0]<nums.back())
            return nums[0];
        return bs(0,nums.size()-1,nums);
    }
};
