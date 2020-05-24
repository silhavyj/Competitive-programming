class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> d;
        int count = 0;
        int ans = 0;
        d[0] = -1;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                count++;
            else count--;
            if (d.find(count) != d.end())
                ans = max(ans, i - d[count]);
            else d[count] = i;
        }
        return ans;
    }
};
