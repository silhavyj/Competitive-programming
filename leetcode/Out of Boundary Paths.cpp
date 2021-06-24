class Solution {
public:
    int dp[50][50][51];
    const int MOD = 1e9+7;
    
    int moves[4][2] {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    
    int solve(int y, int x, int n, int m, int maxMove) {
        if (maxMove == 0)
            return 0;
        if (dp[y][x][maxMove] != -1)
            return dp[y][x][maxMove];
        int ans = 0;
        if (maxMove > 0) {
            if (y == 0) ans++;
            if (x == 0) ans++;
            if (y == n-1) ans++;
            if (x == m-1) ans++;
        }
        //cout << y << " " << x << '\n';
        //cout << ans << "\n";
        for (int i = 0; i < 4; i++) {
            int yy = y + moves[i][0];
            int xx = x + moves[i][1];
            if (yy >= 0 && xx >= 0 && yy < n && xx < m)
                ans = (ans + solve(yy,xx,n,m,maxMove-1)) % MOD;
        }
        return (dp[y][x][maxMove] = ans);
    }
    
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp, -1, sizeof(dp));
        /*int ans = 0;
        for (int i = 0; i < maxMove; i++)
            ans = (ans + solve(startRow, startColumn, m, n, i)) % MOD;
        return ans;*/
        return solve(startRow, startColumn, m, n, maxMove);
    }
};
