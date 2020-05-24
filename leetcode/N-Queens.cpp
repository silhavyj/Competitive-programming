class Solution {
public:
    
    vector<vector<string>> ans;
    bool **m;

    void solve(int i, bool *col, bool *a1, bool *a2, int n) {
        for (int j = 0; j < n; j++) {
            if (col[j] || a1[i+j] || a2[i-j+n])
                continue;
        
            m[i][j] = true;
            if (i == n-1) {
                vector<string> sol;
                for (int k = 0; k < n; k++) {
                    string line = "";
                    for (int l = 0; l < n; l++)
                        line += m[k][l] ? 'Q' : '.';
                    sol.push_back(line);
                }
                ans.push_back(sol);
                m[i][j] = false;
                return; 
            }
        
            col[j] = a1[i+j] = a2[i-j+n] = true;
            solve(i+1, col, a1, a2, n);
            col[j] = a1[i+j] = a2[i-j+n] = false;
            m[i][j] = false;
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        bool col[n];
        bool a1[2*n];
        bool a2[2*n];
        
        m = new bool*[n];
        for (int i = 0; i < n; i++) {
            m[i] = new bool[n];
            for (int j = 0; j < n; j++)
                m[i][j] = false;
        }
        
        memset(col, false, sizeof(col));
        memset(a1, false, sizeof(a1));
        memset(a2, false, sizeof(a2));
        
        solve(0, col, a1, a2, n);
        return ans;
    }
};
