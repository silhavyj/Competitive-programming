class Solution {
private:
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>, int>> rotten;
        int fresh = 0;
        int step = 0, ans=-1;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++) {
                if (grid[i][j]==2)
                    rotten.push({{i,j},0});
                else if (grid[i][j]==1)
                    fresh++;
            }
            
        if (rotten.empty() && fresh>0) return -1;
        if (fresh==0) return 0;

        while (!rotten.empty()) {
            auto top = rotten.front();
            rotten.pop();
            step = top.second;
            for (int i = 0; i < 4; i++) {
                int y = top.first.first + moves[i][0];
                int x = top.first.second + moves[i][1];
                if (y >= 0 && x >= 0 && y < grid.size() && x < grid[0].size() && grid[y][x]==1) {
                    grid[y][x]=2;
                    rotten.push({{y,x},step+1});
                    fresh--;
                }
            }
        }
        return fresh == 0 ? step : -1;
    }
};
