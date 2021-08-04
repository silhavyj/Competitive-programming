class Solution {
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pair<pair<int,int>,int>> que;
        que.push({{entrance[0],entrance[1]},0});
        unordered_set<int> seen;
        seen.insert(entrance[0]*m+entrance[1]);
        
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            int y = top.first.first;
            int x = top.first.second;
            int step = top.second;
            if ((y==0 || x==0 || y==n-1 || x==m-1) && (y!=entrance[0] || x!=entrance[1]))
                return step;
            for (int i = 0; i < 4; i++) {
                int yy = y + moves[i][0];
                int xx = x + moves[i][1];
                if (yy >= 0 && xx >= 0 && yy < n && xx < m && !seen.count(yy*m+xx) && maze[yy][xx]=='.') {
                    seen.insert(yy*m+xx);
                    que.push({{yy,xx},step+1});
                }
            }
        }
        return -1;
    }
};
