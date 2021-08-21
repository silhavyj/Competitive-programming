class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            int p = (i+1) % n;
            while (p != i) {
                if (nums[p] > nums[i])
                    break;
                p = (p + 1) % n;
            }
            ans[i] = i == p ? -1 : nums[p];
        }
        return ans;
    }
};
