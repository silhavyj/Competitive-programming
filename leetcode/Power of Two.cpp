class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n == 0)
            return false;
        int res = 0;
        while (n) {
            if (n & 1) {
                res++;
                if (res == 2)
                    return false;
            }
            n >>= 1;
        }
        return true;
    }
};
