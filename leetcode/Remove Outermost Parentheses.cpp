class Solution {
public:
    string removeOuterParentheses(string s) {
        int opened = 0;
        int closed = 0;
        int lastPos = 0;
        string ans = "";
        
        for (int i = 0; i < s.length(); i++) {
            opened += s[i] == '(';    
            closed += s[i] == ')';
            if (opened == closed) {
                opened = 0;
                closed = 0;
                ans += s.substr(lastPos+1, i-lastPos-1);
                lastPos = i + 1;
            }
        }
        return ans;
    }
};
