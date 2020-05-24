class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int ans = 0;
        int s[60];
        memset(s,0,sizeof(s));
        
        for (int t : time) {
            t %= 60;
            if (t != 0)
                ans += s[60-t];
            else ans += s[t];
            s[t]++;
        }
        return ans;
    }
};
