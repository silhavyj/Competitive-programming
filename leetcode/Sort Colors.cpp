class Solution {
public:
    
    void solve(vector<int>& nums, int l, int r) {
        if (l < r) {
            int p = l;
            for (int i = l+1; i < r; i++)
                if (nums[i] < nums[l])
                    swap(nums[i], nums[++p]);
            swap(nums[l],nums[p]);
            solve(nums,l,p);
            solve(nums,p+1,r);
        }
    }
    
    void sortColors(vector<int>& nums) {
        solve(nums,0,nums.size());
    }
};
