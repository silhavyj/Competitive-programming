class Solution {
public:
    int minCut(string s) {
        vector<int> dp(s.length()+1);
        for (int i = 0; i < s.length()+1; i++)
            dp[i] = i-1;
        
        for (int k = 0; k < s.length(); k++) {
            int i = k;
            int j = k;
            for (; i >= 0 && j < s.length() && s[i]==s[j]; i--, j++)
                dp[j+1] = min(dp[j+1], 1 + dp[i]);
            i = k-1;
            j = k;
            for (; i >= 0 && j < s.length() && s[i]==s[j]; i--, j++)
                dp[j+1] = min(dp[j+1], 1 + dp[i]);
        }
        return dp[s.length()];
    }
};
