class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        for (int n : nums) {
            if (mp.count(n) && mp[n]) {
                mp[n]--;
                if (mp[n]==0)
                    mp.erase(n);
                ans++;
            } else {
                mp[k-n]++;
            }
        }
        return ans;
    }
};
