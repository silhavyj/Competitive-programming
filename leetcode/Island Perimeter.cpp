class Solution {
public:
    
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    
    int islandPerimeter(vector<vector<int>>& grid) {
        int ans=0;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j]==1) {
                    ans+=4;
                    for (int k = 0; k < 4; k++) {
                        int yy = i+moves[k][0];
                        int xx = j+moves[k][1];
                        if (yy < 0 || yy >= grid.size() || xx >= grid[yy].size())
                            continue;
                        if (grid[yy][xx]==1)
                            ans--;    
                    }
                }
        return ans;
    }
};
