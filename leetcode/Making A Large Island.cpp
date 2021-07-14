class Solution {
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
    unordered_map<int,int> belongsTo;
    unordered_map<int,int> sizes;
    
    int dfs(vector<vector<int>> &grid, int y, int x, int n, int currIsland) {
        int ans = 1;
        belongsTo[y*n+x] = currIsland;
        for (int k = 0; k < 4; k++) {
            int yy = y + moves[k][0];
            int xx = x + moves[k][1];
            if (yy >= 0 && xx >= 0 && yy < n && xx < n && grid[yy][xx]==1 && !belongsTo.count(yy*n+xx))
                ans += dfs(grid, yy, xx, n, currIsland);
        }
        return ans;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int currIsland=0;
        bool full=true;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j]==1 && !belongsTo.count(i*n+j)) {
                    int islandSize = dfs(grid,i,j,n,currIsland);
                    ans = max(ans, islandSize);
                    sizes[currIsland++]=islandSize;
                } else if (grid[i][j]==0) {
                    full=false;
                }
            }
        }
        if (sizes.size()==0)
            return 1;
        if (full)
            return n*n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) { 
                if (grid[i][j]==0) {
                    unordered_set<int> neighbors;
                    for (int k = 0; k < 4; k++) {
                        int y = i + moves[k][0];
                        int x = j + moves[k][1];
                        if (y >= 0 && x >= 0 && y < n && x < n && grid[y][x]==1)
                            neighbors.insert(belongsTo[y*n+x]);
                    }
                    int sum = 1;
                    for (int neigh : neighbors)
                        sum += sizes[neigh];
                    ans = max(ans, sum);
                }
            }
        }
        return ans;
    }
};
