class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if (nums.empty())
            return {};
        if (nums.size() == 1)
            return {to_string(nums[0])};
        vector<string> ans;
        int s=0;
        int i = 1;
        for (; i < nums.size(); i++) {
            if (nums[i] != nums[i-1]+1) {
                if (s==i-1)
                    ans.push_back(to_string(nums[s]));
                else
                    ans.push_back(to_string(nums[s]) + "->" + to_string(nums[i-1]));
                s=i;
            }
        }
        if (s==i-1)
            ans.push_back(to_string(nums[s]));
        else
            ans.push_back(to_string(nums[s]) + "->" + to_string(nums[i-1]));
        return ans;
    }
};
