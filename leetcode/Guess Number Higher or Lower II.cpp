class Solution {
public:
    
    vector<vector<int>> dp;
    
    int solve(int l, int r) {
        if (l>=r)
            return 0;
        if (dp[l][r]!=INT_MAX)
            return dp[l][r];
        for (int i = l; i <= r; i++)
            dp[l][r] = min(dp[l][r], i+max(solve(l,i-1),solve(i+1,r)));
        return dp[l][r];
    }
    
    int getMoneyAmount(int n) {
        dp.resize(n+1, vector<int>(n+1,INT_MAX));
        return solve(1,n);
    }
};
