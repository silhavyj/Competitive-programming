class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        vector<int> sums(s.length());
        sums[sums.size()-1] = shifts[shifts.size()-1];
        for (int i = shifts.size() - 2; i >= 0; i--)
            sums[i] = (shifts[i] + sums[i+1]) % 26;
        
        for (int i = 0; i < s.length(); i++) {
            int val = s[i]-'a';
            val += sums[i];
            val %= 26;
            s[i] = (char)('a'+val);
        }
        return s;
    }
};
