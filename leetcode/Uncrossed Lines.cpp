class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int dp[A.size()+1][B.size()+1];
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= A.size(); i++)
            for (int j = 1; j <= B.size(); j++)
                dp[i][j] = A[i-1]==B[j-1] ? (1+dp[i-1][j-1]) : max(dp[i-1][j],dp[i][j-1]);
        return dp[A.size()][B.size()];
    }
};
