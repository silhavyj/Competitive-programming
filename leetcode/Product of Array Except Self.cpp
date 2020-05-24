class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        int p = 1;
        
        res.push_back(1);
        for (int i = 1; i < n; i++) {
            p *= nums[i-1];
            res.push_back(p);
        }
        
        p = 1;
        for (int i = n-2; i >= 0; i--) {
            p *= nums[i+1];
            res[i] *= p;
        }
        return res;
    }
};
