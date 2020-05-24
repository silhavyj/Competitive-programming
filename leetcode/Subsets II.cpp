class Solution {
public:
    
    vector<vector<int>> ans;
    unordered_set<long long> used;
    
    long long getHash(vector<int> v) {
        sort(v.begin(), v.end());
        long long res = 31;
        for (int x : v)
            res = 17 * res + x;
        return res;
    }
    
    void solve(vector<int> &nums, int p, vector<int> &next) {
        long long h = getHash(next);
        if (used.find(h) == used.end()) {
            used.insert(h);
            ans.push_back(next);
        }
        for (int i = p; i < nums.size(); i++) {
            next.push_back(nums[i]);
            solve(nums, i+1, next);
            next.pop_back();
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> next;
        solve(nums, 0, next);
        return ans;
    }
};
