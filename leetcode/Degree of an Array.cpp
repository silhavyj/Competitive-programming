class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,vector<int>> mp;
        int maxlen = INT_MIN;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
            if (mp[nums[i]].size() > mp[maxlen].size())
                maxlen = nums[i];
        }
        int len = mp[maxlen].size();
        int ans = INT_MAX;
        for (auto &p : mp) {
            if (p.second.size() == len)
                ans = min(ans, p.second[len-1] - p.second[0] + 1);
        }
        return ans;
    }
};
