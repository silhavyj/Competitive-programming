class Solution {
public:
    int countPairs(vector<int>& deliciousness) {
        const int MOD = 1e9+7;
        int p2[22];
        for (int i = 0; i < 22; i++)
            p2[i] = 1 << i;
        long ans = 0;
        unordered_map<long, long> mp;
        for (int d : deliciousness) {
            for (int i = 0; i < 22; i++)
                ans = (ans + mp[p2[i]-d]) % MOD;
            mp[d]++;
        }
        return ans;
    }
};
