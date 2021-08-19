class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int ans = 0;
        bool flip = false;
        for (int p = 30; p >= 0; p--) {
            if ((n >> p) & 1)
                flip = true;
            if (flip && ((n >> p) & 1) == 0)
                ans |= (1 << p);
        }
        return ans;
    }
};
