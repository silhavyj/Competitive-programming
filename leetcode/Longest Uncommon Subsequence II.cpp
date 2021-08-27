class Solution {
    bool isLCS(string &a, string &b) {
        int n = a.length();
        int m = b.length();
        int i = 0;
        if (n > m)
            return false;
        for (int j = 0; j < m; j++) {
            if (a[i]==b[j])
                i++;
            if (i==n)
                return true;
        }
        return false;
    }
public:
    int findLUSlength(vector<string>& strs) {
        int n = strs.size();
        int ans = -1;
        
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i==j)
                    continue;
                if (isLCS(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ans = max(ans, (int)strs[i].length());
        }
        return ans;
    }
};
