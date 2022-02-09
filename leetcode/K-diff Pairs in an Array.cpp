class Solution {
    inline size_t hash(int a, int b) {
        size_t h = 31;
        int x = min(a,b);
        int y = max(a,b);
        h = 17 * h + x;
        h = 17 * h + y;
        return h;
    }
public:
    int findPairs(vector<int>& nums, int k) {        
        unordered_set<int> seen;
        map<int,list<int>> mp;
        int n = nums.size();
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (mp.count(nums[i])) {
                for (int x : mp[nums[i]]) {
                    size_t h = hash(nums[i],x);
                    if (!seen.count(h)) {
                        ans++;
                        seen.insert(h);
                    }
                }
            }
            mp[nums[i]+k].push_back(nums[i]);
            mp[nums[i]-k].push_back(nums[i]);
        }
        return ans;
    }
};
