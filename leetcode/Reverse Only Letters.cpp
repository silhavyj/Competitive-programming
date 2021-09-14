class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<int> pos;
        for (int i = 0; i < s.length(); i++)
            if (isalpha(s[i]))
                pos.push_back(i);
        int n = pos.size();
        for (int i = 0; i < n/2; i++)
            swap(s[pos[i]], s[pos[n-i-1]]);
        return s;
    }
};
