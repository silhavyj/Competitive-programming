class Solution {
public:
    int addDigits(int num) {
        if (num < 10)
            return num;
        int sum = 0;
        string s = to_string(num);
        for (char c : s)
            sum += c-'0';
        return addDigits(sum);
    }
};
