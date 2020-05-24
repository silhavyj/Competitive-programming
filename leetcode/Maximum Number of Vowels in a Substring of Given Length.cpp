class Solution {
public:
    int maxVowels(string s, int k) {
        int a=0, e=0, i=0, o=0, u=0;
        for (int j = 0; j < k; j++) {
            if (s[j]=='a') a++;
            if (s[j]=='e') e++;
            if (s[j]=='i') i++;
            if (s[j]=='o') o++;
            if (s[j]=='u') u++;
        }        
        int ans=0;
        for (int p=0; ;p++) {
            ans = max(ans,a+e+i+o+u);
            if (k+p == s.length())
                break;
            
            if (s[p]=='a') a--;
            if (s[p]=='e') e--;
            if (s[p]=='i') i--;
            if (s[p]=='o') o--;
            if (s[p]=='u') u--;
            
            if (s[k+p]=='a') a++;
            if (s[k+p]=='e') e++;
            if (s[k+p]=='i') i++;
            if (s[k+p]=='o') o++;
            if (s[k+p]=='u') u++;
        }
        return ans;
    }
};
