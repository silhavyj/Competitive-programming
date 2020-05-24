class Solution {
public:
    
    vector<vector<int>> ans;
    
    void solve(vector<int> &nums, int p, vector<int> &next) {
        ans.push_back(next);
        for (int i = p; i < nums.size(); i++) {
            next.push_back(nums[i]);
            solve(nums, i+1, next);
            next.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> next;
        solve(nums, 0, next);
        return ans;
    }
};
