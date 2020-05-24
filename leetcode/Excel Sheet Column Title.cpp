class Solution {
public:
    string convertToTitle(int n) {
        string res = "";
        while (n >= 1) {
            int d = n % 26;
            if (d == 0) {
                res += 'Z';
                n /= 26;
                n--;
            }
            else {
                res += 'A'+d-1;
                n /= 26;
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
