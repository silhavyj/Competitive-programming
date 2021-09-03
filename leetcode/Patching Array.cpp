class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
    		int ans = 0;
        long sumsf = 1;
        int i = 0;

        while (sumsf <= n) {
            if (i < nums.size() && nums[i] <= sumsf)
                sumsf += nums[i++];
            else {
                ans++;
                sumsf += sumsf;
            }
        }
        return ans;
    }
};
