class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int bestSum = INT_MIN;
        int currentSum = 0;
        bool pos = false;
        int maxNeg = INT_MIN;
        
        for (int n : nums) {
            if (pos == false)
                maxNeg = max(maxNeg, n);
            if (n >= 0)
                pos = true;
            
            currentSum = max(0, currentSum + n);
            bestSum = max(bestSum, currentSum);
        }
        return !pos ? maxNeg : bestSum;
    }
};
