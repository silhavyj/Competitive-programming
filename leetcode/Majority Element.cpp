class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> d;
        int max_count = 0;
        int ans = 0;
        
        for (int n : nums) {
            d[n]++;
            if (d[n] > max_count) {
                max_count = d[n];
                ans = n;
            }
        }
        return ans;
    }
};
