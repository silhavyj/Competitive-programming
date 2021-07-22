class Solution {
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans = 0;
        auto area = [](int x) { return x==0 ? 0 : (2+x*4);};
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int a = area(grid[i][j]);
                for (int k = 0; k < 4; k++) {
                    int y = i + moves[k][0];
                    int x = j + moves[k][1];
                    if (y >= 0 && x >= 0 && y < n && x < n) {
                        if (grid[y][x]<grid[i][j])
                            a -= 2*grid[y][x];
                        else if (grid[y][x]==grid[i][j])
                            a -= grid[y][x];
                    }
                }
                ans += a;
            }
        return ans;
    }
};
