class Solution {
public:
    bool hasAlternatingBits(int n) {
        int p = 30;
        while ((n & (1<<p)) == 0)
            p--;
        for (int i = p; i >= 1; i--)
            if (((n & (1<<i))>>i) == ((n & (1<<(i-1))))>>(i-1))
                return false;
        return true;
    }
};
