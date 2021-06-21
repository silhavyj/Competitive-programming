class Solution {
public:
    #define ll long long
    #define max(x,y) ((x)>(y)?(x):(y))
    const int MOD = 1e9+7;
    
    int moves[8][2] = {
        {-2,-1},
        {-2,1},
        {-1,2},
        {1,2},
        {2,1},
        {2,-1},
        {1,-2},
        {-1,-2}
    };

    unordered_map<int,int> dp;
    
    int solve(int y, int x, int p, int n) {
        if (p==n)
            return 1;
        
        int h=y+x*10+p*100;
        if (dp.count(h))
            return dp[h];
        
        ll ans = 0;
        for (int i = 0; i < 8; i++) {
            int yy = y+moves[i][0];
            int xx = x+moves[i][1];
            if ((yy >= 0 && xx >= 0 && yy <= 2 && xx <= 2) || (yy==3 && xx==1))
                ans = (ans + solve(yy,xx,p+1,n)) % MOD;        
        }
        return dp[h]=ans % MOD;
    }
    
    int knightDialer(int n) {
        int ans = 0;
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (i==3 && (j==0 || j==2))
                    continue;
                ans = (ans + solve(i,j,0,n-1)) % MOD;
            }
        }
        return ans;
    }
};
