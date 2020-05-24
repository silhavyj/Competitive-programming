class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.length();
        for (int i = 1; i < n; i++) {
            if (n % i != 0)
                continue;
            
            string r = s.substr(0,i);
            
            int j = i;
            for (; j < n; j++) {
                if (s[j] != r[j%i])
                    break;
            }
            if (j == n)
                return true;
        }
        return false;
    }
};
