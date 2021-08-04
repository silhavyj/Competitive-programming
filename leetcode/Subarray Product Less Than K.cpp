class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans = 0;
        int l=0, p=1;
        for (int i = 0; i < nums.size(); i++) {
            p *= nums[i];
            if (p >= k) {
                p /= nums[l];
                l++;
            }
            ans += i-l+1;
        }
        return ans;
    }
};
