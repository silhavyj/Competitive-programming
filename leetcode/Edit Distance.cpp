class Solution {
public:
    
    int minDistance(string word1, string word2) {
    int n = word1.length();
        int m = word2.length();
        
        int dp[n+1][m+1];
        
        for (int j = 0; j < m+1; j++)
        	dp[0][j] = j;
        
        for (int i = 1; i < n+1; i++) {
            for (int j = 0; j < m+1; j++) {
            	if (j == 0) {
            		dp[i][0] = i;
            		continue;
				}
                if (word1[i-1] == word2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
            }
        }
        return dp[n][m];
    }
};
