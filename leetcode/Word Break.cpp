class Solution {
public:
    
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        bool dp[n][n];
        unordered_set<string> dic;
        
        for (string word : wordDict)
            dic.insert(word);
    
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dp[i][j] = false;
        
        for (int k = 0; k < n; k++) {
            for (int l=0, r=k; r < n; l++, r++) {
                if (dic.find(s.substr(l,r-l+1)) != dic.end())
                    dp[l][r] = true;
                else {
                    bool exists = false;
                    for (int i = l; i < r && !exists; i++)
                        exists |= dp[l][i] && dp[i+1][r];
                    dp[l][r] = exists;
                }
            }
        }   
        return dp[0][n-1];
    }
};
