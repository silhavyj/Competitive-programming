class Solution {
    vector<int> digits(int n) {
        vector<int> d;
        while (n != 0) {
            d.insert(d.begin(),n%10);
            n /= 10;
        }
        return d;
    }
    int getNum(vector<int> &digits) {
        int n = 0;
        int p=1;
        for (int i = digits.size()-1; i>=0; i--) {
            n += digits[i]*p;
            p *= 10;
        }
        return n;
    }
public:
    int rotatedDigits(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            bool invalid = false;
            auto d = digits(i);   
            for (int &x : d) {
                if (x == 0 || x == 1 || x == 8)
                    continue;
                else if (x == 2)
                    x = 5;
                else if (x == 5)
                    x = 2;
                else if (x == 6)
                    x = 9;
                else if (x == 9)
                    x = 6;
                else {
                    invalid = true;
                    break;
                }
            }
            if (!invalid && getNum(d) != i)
                ans++;
        }
        return ans;
    }
};
