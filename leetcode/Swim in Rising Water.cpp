class Solution {
public:
    int move[4][2] = {
        {-1,0},    
        {0,-1},
        {1,0},
        {0,1}
    };
    
    int swimInWater(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
        que.push({grid[0][0],0});
        vector<int> rank(r*c, INT_MAX);
        rank[0]=grid[0][0];
        
        while (!que.empty()) {
            auto top = que.top();
            que.pop();
            if (top.second == r*c-1)
                return top.first;
            int y = top.second / r;
            int x = top.second % r;
            for (int i = 0; i < 4; i++) {
                int yy = y+move[i][0];
                int xx = x+move[i][1];
                if (xx >= 0 && yy >= 0 && xx < c && yy < c) {
                    int weight = max(top.first, grid[yy][xx]);
                    if (weight < rank[yy*r+xx]) {
                        que.push({weight, yy*r+xx});
                        rank[yy*r+xx] = weight;
                    }
                }
            }
        }
        return INT_MAX;
    }
};
