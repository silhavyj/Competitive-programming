class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> s;
        for (int i=0; i<k; i++)
            s.insert(nums[i]);
        vector<int> ans;
        for (int i=k; i<nums.size(); i++) {
            int x = *(s.rbegin());
            s.erase(s.lower_bound(nums[i-k]));
            s.insert(nums[i]);
            ans.push_back(x);
        }
        ans.push_back(*(s.rbegin()));
        return ans;
    }
};
