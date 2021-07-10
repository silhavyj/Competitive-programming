class Solution {
    const int MOD = 1e9+7;
public:
    int numDecodings(string s) {
        vector<long long> dp(s.length()+1,1);
        if (s[0]=='*')
            dp[1]=9;
        else if (s[0]=='0')
            dp[1]=0;
        else
            dp[1]=1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i]=='*') {
                dp[i+1] = (9 * dp[i]) % MOD;
                if (s[i-1]=='1')
                    dp[i+1] = (dp[i+1] + 9 * dp[i-1]) % MOD;
                else if (s[i-1] == '2')
                    dp[i+1] = (dp[i+1] + 6 * dp[i-1]) % MOD;
                else if (s[i-1] == '*')
                    dp[i+1] = (dp[i+1] + 15 * dp[i-1]) % MOD;
            } else {
                if (s[i]=='0')
                    dp[i+1] = 0;
                else
                    dp[i+1] = dp[i];
                if (s[i-1] == '1')
                    dp[i+1] = (dp[i+1] + dp[i-1]) % MOD;
                if (s[i-1] == '2' && s[i] <= '6')
                    dp[i+1] = (dp[i+1] + dp[i-1]) % MOD;
                else if (s[i-1] == '*') {
                    if (s[i] <= '6')
                        dp[i+1] = (dp[i+1] + 2 * dp[i-1]) % MOD;
                    else
                        dp[i+1] = (dp[i+1] + dp[i-1]) % MOD;
                }
            }
        }
        return dp[s.length()];
    }
};
