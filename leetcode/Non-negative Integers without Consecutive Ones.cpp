class Solution {
public:
    int findIntegers(int n) {
        int f[32];
        f[0]=1, f[1]=2;
        for (int i = 2; i < 32; i++)
            f[i] = f[i-1] + f[i-2];
        int ans = 1;
        int prev = 0;
        for (int i = 30; i >= 0; i--) {
            if ((n >> i) & 1) {
                ans += f[i];
                if (prev == 1) {
                    ans--;
                    break;
                }
                prev = 1;
            } else {
                prev = 0;
            }
        }
        return ans;
    }
};
