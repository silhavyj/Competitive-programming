class Solution {
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, bool &ok) {
        if (grid2[i][j]==1 && grid1[i][j]!=1)
            ok = false;
        grid2[i][j]=0;
        for (int k = 0; k < 4; k++) {
            int y = i + moves[k][0];
            int x = j + moves[k][1];
            if (y >= 0 && x >= 0 && y < grid1.size() && x < grid1[0].size() && grid2[y][x]==1)
                dfs(grid1, grid2, y, x, ok);
        }
    } 
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int ans = 0;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[0].size(); j++) {
                if (grid2[i][j]==1 && grid1[i][j]==1) {
                    bool ok=true;
                    dfs(grid1, grid2, i, j, ok);
                    if (ok)
                        ans++;
                }
            }
        }
        return ans;
    }
};
