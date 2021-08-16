class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int one=0, zero=0;
        for (char c : s) {
            if (c == '0') {
                one = min(one, zero) + 1;
            } else {
                one = min(one, zero);
                zero++;
            }
        }
        return min(one, zero);
    }
};
