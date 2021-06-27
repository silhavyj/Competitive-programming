class Solution {
public:
    int balancedStringSplit(string s) {
        int rc = 0;
        int lc = 0;
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'R') rc++;
            if (s[i] == 'L') lc++;
            if (rc != 0 && lc != 0 && rc == lc) {
                ans++;
                rc = 0;
                lc = 0;
            }
        }
        return ans;
    }
};
