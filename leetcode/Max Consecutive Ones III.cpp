class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeros=0;
        int j=0;
        int ans=0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i]==0)
                zeros++;
            if (zeros > k) {
                if (nums[j]==0)
                    zeros--;
                j++;
            }
            ans = max(ans, i-j+1);
        }
        return ans;
    }
};
