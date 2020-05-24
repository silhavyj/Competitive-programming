class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_set<int> d;
        for (int i = 1; i <= nums.size(); i++)
            d.insert(i);
        
        for (int n : nums)
            if (d.find(n) != d.end())
                d.erase(n);
        
        vector<int> ans;
        for (int n : d)
            ans.push_back(n);
        return ans;
    }
};
