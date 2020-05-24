class Solution {
public:
    string reverseOnlyLetters(string S) {
        string r = "";
        for (auto s : S)
            if ((s >= 'a' && s <= 'z') || (s >= 'A' && s <= 'Z'))
                r += s;
        reverse(r.begin(),r.end());
        int i = 0, j = 0;
        string ans = "";
        while (i != S.length()) {
            if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z') && j < r.length())
                ans += r[j++];
            else ans += S[i];
            i++;
        }
        return ans;
    }
};
