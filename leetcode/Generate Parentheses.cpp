class Solution {
public:
    
    vector<string> res;
    
    void gen(int o, int c, int n, string s) {
        if (s.length() == 2*n) {
            res.push_back(s);
            return;
        }
        if (o < n) gen(o+1, c, n, s + "(");
        if (o > c) gen(o, c+1, n, s + ")");
    }
    
    vector<string> generateParenthesis(int n) {
        gen(0,0,n,"");
        return res;
    }
};
