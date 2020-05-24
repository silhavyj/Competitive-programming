class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int count = 0;
        
        for (int n : nums) {
            if (n == 1) count++;
            else {
                ans = max(ans, count);
                count = 0;
            }
        }
        return max(ans, count);
    }
};
