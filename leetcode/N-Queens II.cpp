class Solution {
public:
    
    int ans = 0;
    
    void solve(int i, bool *col, bool *a1, bool *a2, int n) {
        for (int j = 0; j < n; j++) {
            if (col[j] || a1[i+j] || a2[i-j+n])
                continue;
            
             if (i == n-1) {
                ans++;
                return;
            }
            
            col[j] = a1[i+j] = a2[i-j+n] = true;
            solve(i+1, col, a1, a2, n);
            col[j] = a1[i+j] = a2[i-j+n] = false;
        }
    }
    
    int totalNQueens(int n) {
        bool col[n];
        bool a1[2*n+1];
        bool a2[2*n+1];
        
        memset(col, false, sizeof(col));
        memset(a1, false, sizeof(a1));
        memset(a2, false, sizeof(a2));
        
        solve(0, col, a1, a2, n);
        return ans;
    }
};
