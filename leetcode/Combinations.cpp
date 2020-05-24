class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums, int p, vector<int> &next, int k) {
        if (next.size() == k) {
            ans.push_back(next);
            return;
        }
        for (int i = p; i < nums.size(); i++) {
            next.push_back(nums[i]);
            solve(nums, i+1, next, k);
            next.pop_back();
        }
    }
    
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums, next;
        for (int i = 1; i <= n; i++)
            nums.push_back(i);
        solve(nums, 0, next, k);
        return ans;
    }
};
