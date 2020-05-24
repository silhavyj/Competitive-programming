class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] <= nums.back())
            return nums[0];
        
        int l=0;
        int r=n-1;
        
        while (true) {
            if (l==r-1)
                break;
            int m = l+(r-l)/2;
            if (nums[m] > nums[r])
                l=m;
            else r=m;
        }
        return nums[r];
    }
};
