class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        int sum = 0;
        unordered_map<int,int> m;
        
        m[0] = 1;
        for (int x : nums) {
            sum += x;
            if (m.find(sum-k) != m.end())
                ans += m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};
