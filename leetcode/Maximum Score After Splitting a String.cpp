class Solution {
public:
    
    int count(string &s, int l, int r, char v) {
        int ans = 0;
        for (int i = l; i < r; i++)
            if (s[i] == v)
                ans++;
        return ans;
    }
    
    int maxScore(string s) {
        int ans = 0;
        for (int i = 1; i < s.length(); i++) 
            ans = max(ans, count(s,0,i,'0') + count(s,i,s.length(),'1'));
        return ans;
    }
};
