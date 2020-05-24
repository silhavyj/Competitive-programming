class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        int dp[n][m];
        
        for (int i = 0; i < m; i++) {
            dp[0][i] = matrix[0][i];
            ans += dp[0][i];
        }
        for (int i = 1; i < n; i++) {
            dp[i][0] = matrix[i][0];
            ans += dp[i][0];
        }
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                dp[i][j] = !matrix[i][j] ? 0 : (1+min({dp[i-1][j],dp[i-1][j-1],dp[i][j-1]}));
                ans += dp[i][j];
            }
        }
        return ans;
    }
};
