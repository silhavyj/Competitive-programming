class Solution {
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        const int MOD = 1e9+7;
        set<int> xs, ys;
        map<int,int> mpx, mpy;
        for (auto &rec : rectangles) {
            xs.insert(rec[0]); xs.insert(rec[2]);
            ys.insert(rec[1]); ys.insert(rec[3]);
        }
        vector<int> imapx, imapy;
        int i = 0;
        for (int x : xs) {
            mpx[x] = i++;
            imapx.push_back(x);
        }
        i = 0;
        for (int y : ys) {
            mpy[y] = i++;
            imapy.push_back(y);
        }
        
        int n = ys.size();
        int m = xs.size();
        bool grid[n][m];
        memset(grid, false, sizeof(grid));
        
        for (auto &rec : rectangles)
            for (int y = mpy[rec[1]]; y < mpy[rec[3]]; y++)
                for (int x = mpx[rec[0]]; x < mpx[rec[2]]; x++)
                        grid[y][x] = true;  
        
        long long ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j])
                    ans += ((long long)(imapx[j+1] - imapx[j]) * (imapy[i+1] - imapy[i]));
        return ans % MOD;
    }
};
