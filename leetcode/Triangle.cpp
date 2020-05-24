class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        int dp[n][n+2];
        int ans = INT_MAX;
        
        if (n == 1)
            return triangle[0][0];
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n+2; j++)
                dp[i][j] = INT_MAX;
        
        dp[0][1] = triangle[0][0];
        
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < i+2; j++) {   
                dp[i][j] = triangle[i][j-1] + min(dp[i-1][j-1], dp[i-1][j]);
                if (i == n-1)
                    ans = min(ans, dp[i][j]);
            }
        }
        
       /* for (int i = 0; i < n; i++) {
        	for (int j = 0; j < n+2; j++) {
        		cout << dp[i][j] << " ";
			}
			cout << endl;
		} */
        
        return ans;
    }
};
