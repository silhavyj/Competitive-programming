class Solution {
public:
    string removeDuplicates(string s) {
        vector<char> st(s.length());
        int p = 0;
        for (int i = 0; i < s.length(); i++) {
            if (p==0 || st[p-1] != s[i]) {
                st[p++] = s[i];
            }
            else {
                p--;
            }
        }
        string ans = "";
        for (int i = 0; i < p; i++)
            ans += st[i];
        return ans;
    }
};
