class Solution {
public:
    
    /*int ans = INT_MIN;
    
    void solve(vector<vector<int>>& dungeon, int y, int x, int life=0, int res=0) {
        life += dungeon[y][x];
        res = min(res, life);
        if (y==dungeon.size()-1 && x==dungeon[0].size()-1) {
            ans = max(ans,res);
            return;
        }
        if (y+1 < dungeon.size())
            solve(dungeon, y+1, x, life, res);
        if (x+1 < dungeon[0].size())
            solve(dungeon, y, x+1, life, res);
    }
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        solve(dungeon,0,0);
        if (ans < 0)
            return -ans+1;
        return 1;
    }*/
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        vector<vector<int>> dp(n, vector<int>(m));
        for (int i = n-1; i >= 0; i--) {
            for (int j = m-1; j >= 0; j--) {
                if (i==n-1 && j==m-1) {
                    dp[i][j] = max(1-dungeon[i][j], 1); 
                    continue;
                }
                if (i==n-1)
                    dp[i][j] = max(dp[i][j+1]-dungeon[i][j], 1);
                else if (j==m-1)
                    dp[i][j] = max(dp[i+1][j]-dungeon[i][j], 1);
                else
                    dp[i][j] = min(max(dp[i][j+1]-dungeon[i][j], 1),
                                   max(dp[i+1][j]-dungeon[i][j], 1));
            }
        }
        return dp[0][0];
    }
};
