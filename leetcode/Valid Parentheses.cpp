class Solution {
public:
    
    int type(char b) {
        if (b == '(') return 0;
        if (b == ')') return 1;
        if (b == '[') return 2;
        if (b == ']') return 3;
        if (b == '{') return 4;
        return 5;
    }
    
    bool isValid(string s) {
        if (s.length() & 1)
            return false;
        
        stack<char> st;
        
        for (char b : s) {
            int t = type(b);
            if (t & 1) {
                if (st.empty())
                    return false;
                if (type(st.top()) != t-1)
                    return false;
                st.pop();
            }
            else st.push(b);
        }
        return st.empty();
    }
};
