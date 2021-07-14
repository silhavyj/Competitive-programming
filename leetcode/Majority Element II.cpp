class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for (int n : nums)
            mp[n]++;
        vector<int> ans;
        for (auto p : mp)
            if (p.second > floor(nums.size()/3.0))
                ans.push_back(p.first);
        return ans;
    }
};
