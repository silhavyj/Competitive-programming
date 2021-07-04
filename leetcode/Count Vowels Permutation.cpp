class Solution {
public:
    int countVowelPermutation(int n) {
        int MOD = 1e9+7;
        int a[n], e[n], i[n], o[n], u[n];
        a[0] = e[0] = i[0] = o[0] = u[0] = 1;
        
        for (int j = 1; j < n; j++) {
            a[j] = e[j-1];
            e[j] = (a[j-1] + i[j-1]) % MOD;
            i[j] = 0;
            i[j] = (i[j] + a[j-1]) % MOD;
            i[j] = (i[j] + e[j-1]) % MOD;
            i[j] = (i[j] + o[j-1]) % MOD;
            i[j] = (i[j] + u[j-1]) % MOD;
            
            o[j] = (i[j-1] + u[j-1]) % MOD;
            u[j] = a[j-1];
            
            //cout << a[j] << " " << e[j] << " " << i[j] << " " << o[j] << " " << u[j] << "\n";
        }
        
        int ans = (a[n-1] + e[n-1]) % MOD;
        ans = (ans + i[n-1]) % MOD;
        ans = (ans + o[n-1]) % MOD;
        ans = (ans + u[n-1]) % MOD;
        return ans;
    }
};
