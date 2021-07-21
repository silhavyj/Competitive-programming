class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> force(dominoes.size(), 0);
        int f = 0;
        for (int i = 0; i < dominoes.length(); i++) {
            if (dominoes[i]=='R')
                f=dominoes.length();
            else if (dominoes[i]=='L')
                f=0;
            else
                f=max(0,f-1);
            force[i] += f;
        }
        for (int i = dominoes.length()-1; i >= 0; i--) {
            if (dominoes[i]=='L')
                f=dominoes.length();
            else if (dominoes[i]=='R')
                f=0;
            else
                f=max(0,f-1);
            force[i] -= f;
        }
        string ans="";
        for (int i = 0; i < dominoes.length(); i++) {
            if (force[i]<0)
                ans += 'L';
            else if (force[i]>0)
                ans += 'R';
            else
                ans += '.';
        }
        return ans;
    }
};
