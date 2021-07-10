class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length()+1,0);
        dp[0]=1;
        if (s[0]!='0')
            dp[1]=1;
        for (int i = 2; i <= s.length(); i++) {
            int x = s[i-1]-'0';
            int y = 10*(s[i-2]-'0')+s[i-1]-'0';
            if (x >= 1)
                dp[i] += dp[i-1];
            if (y >= 10 && y <= 26)
                dp[i] += dp[i-2];
        }
        return dp[s.length()];
    }
};
