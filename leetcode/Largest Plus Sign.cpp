class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        unordered_set<int> banned;
        for (auto &m : mines)
            banned.insert(m[0]*n+m[1]);
        vector<vector<int>> dp(n, vector<int>(n,0));
        int ans = 0;
        int count;
        
        for (int i = 0; i < n; i++) {
            count = 0;
            for (int j = 0; j < n; j++) {
                if (banned.count(i*n+j))
                    count = 0;
                else
                    count++;
                dp[i][j] = count;
            }
            count = 0;
            for (int j = n-1; j >= 0; j--) {
                if (banned.count(i*n+j))
                    count = 0;
                else
                    count++;
                dp[i][j] = min(dp[i][j], count);
            }
        }
        for (int j = 0; j < n; j++) {
            count = 0;
            for (int i = 0; i < n; i++) {
                if (banned.count(i*n+j))
                    count = 0;
                else
                    count++;
                dp[i][j] = min(dp[i][j], count);
            }
            count = 0;
            for (int i = n-1; i >= 0; i--) {
                if (banned.count(i*n+j))
                    count = 0;
                else
                    count++;
                dp[i][j] = min(dp[i][j], count);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};
