class Solution {
public:
    
    vector<int> par, rank;
    
    void init(int n) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(1);
        }
    }
    
    int find(int x) {
        return x == par[x] ? x : (par[x] = find(par[x]));
    }
    
    void uni(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (rank[px] < rank[py])
            par[px] = par[py];
        else {
            par[py] = px;
            if (rank[py] == rank[px])
                rank[py]++;
        }
    }
    
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        
        int i = 0;
        unordered_map<int,int> mp;
        
        for (int d : nums)
            if (mp.find(d) == mp.end())
                mp[d] = i++;
        
        init(mp.size());
        for (auto m : mp)
            if (mp.find(m.first+1) != mp.end())
                uni(m.second, mp[m.first+1]);
        
        unordered_map<int,int> groups;
        int ans = INT_MIN;

        for (int p : par) {
            int x = find(p);
            groups[x]++;
            ans = max(ans, groups[x]);
        }
        return ans;
    }
};
