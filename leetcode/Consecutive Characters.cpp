class Solution {
public:
    int maxPower(string s) {
        if (s.empty())
            return 0;
        int j=0, i=0;
        int ans=1;
        for (; i < s.length(); i++) {
            if (i && s[i] != s[j]) {
                ans = max(ans, i-j);
                j=i;
            }
        }
        return max(ans, i-j);
    }
};
