class Solution {
public:
    string reformat(string s) {
        vector<char> l,d;
        
        for (char c : s) {
            if (c >= 'a' && c <= 'z')
                l.push_back(c);
            else d.push_back(c);
        }
        
        int ls = l.size();
        int ds = d.size();
        int i=0, j=0;
        string ans = "";
        
        if (ls==0 && ds==1) {
            ans += d[0];
            return ans;
        }
        
        if (ds==0 && ls==1) {
            ans += l[0];
            return ans;   
        }
        
        if (ds==0 && ls==0)
            return "";
        
        if (abs(ls-ds) > 1)
            return ans;
        
        if (ls == ds) {
            for (int i = 0; i < ls; i++) {
                ans += l[i];
                ans += d[i];
            }
        }
        else if (ls > ds) {
            ans += l[0];
            for (int i = 0; i < ds; i++) {
                ans += d[i];
                ans += l[i+1];
            }
        }
        else {
            ans += d[0];
            for (int i = 0; i < ls; i++) {
                ans += l[i];
                ans += d[i+1];
            }
        }
        return ans;
    }
};
