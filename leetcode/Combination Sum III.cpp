class Solution {
public:
    
    vector<vector<int>> res;
    
    void solve(int i, int k, int n, vector<int> &nums) {
        if (n == 0 && nums.size() == k) {
            res.push_back(nums);
            return;
        }
        if (i == 0 || nums.size() == k)
            return;
        if (n >= i) {
            nums.push_back(i);
            solve(i-1, k, n-i, nums);
            nums.pop_back();
        }
        solve(i-1, k, n, nums);
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums;
        solve(9,k,n,nums);
        return res;
    }
};
