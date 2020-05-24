class Solution {
public:
    
    inline int pow(int a, int b) {
        int ans = 1;
        while (b--)
            ans *= a;
        return ans;
    }
    
    int titleToNumber(string s) {
        int p = s.length()-1;
        int ans = 0;
        for (char c : s)
            ans += (c-'A'+1) * pow(26,p--);
        return ans;
    }
};
