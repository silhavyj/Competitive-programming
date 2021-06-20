class Solution {
public:
    int move[4][2] = {
        {-1,0},  
        {0,-1},
        {1,0},
        {0,1}
    };
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        set<pair<int,int>> pos1;
        for (int i = 0; i < grid.size(); i++)
            for (int j = 0; j < grid[i].size(); j++)
                if (grid[i][j])
                    pos1.insert({i,j});
        int ans = 0;
        while (!pos1.empty()) {
            auto s = *pos1.begin();
            pos1.erase(pos1.begin());
            queue<pair<int,int>> que;
            que.push(s);
            int area=0;
            
            while (!que.empty()) {
                auto curr = que.front();
                que.pop();
                area++;
                for (int i = 0; i < 4; i++) {
                    int y = curr.first + move[i][0];
                    int x = curr.second + move[i][1];
                    if (y >= 0 && x >= 0 && y < grid.size() && x < grid[0].size() && pos1.count({y,x})) {
                        que.push({y,x});
                        pos1.erase({y,x});
                    }
                }
            }
            ans = max(ans, area);
        }
        return ans;
    }
};
