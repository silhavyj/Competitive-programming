class Solution {
    int solve(vector<int> &nums, int p) {
       int len=0, tmp;
       while (1) {
           if (nums[p] == -1)
               break;
           tmp = p;
           p = nums[p];
           nums[tmp] = -1;
           len++;
       }
       return len;
    }
public:
    int arrayNesting(vector<int>& nums) {
        int ans = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
            ans = max(ans, solve(nums, i));
        return ans;
    }
};
