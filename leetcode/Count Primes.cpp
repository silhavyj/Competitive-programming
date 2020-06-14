class Solution {
public:
    int countPrimes(int n) {
        int ans = 0;
        int is[n+1];
        for (int i = 0; i < n; ++i)
            is[i] = true;
        for (int i = 2; i < n; ++i)
            if (is[i]) {
                ans++;
                for (int j = 2*i; j < n; j+=i)
                    is[j]=false;
            }
        return ans;
    }
};
