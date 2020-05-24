class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans[n][n];
        
        if (grid[0][0]!=0)
            return -1;
    
        int m[8][2] = {
            {-1,-1},
            {-1,0},
            {1,1},
            {1,0},
            {1,-1},
            {0,-1},
            {-1,1},
            {0,1},
        };
        memset(ans,0,sizeof(ans));
        queue<int> que;
        que.push(0);
        ans[0][0]=1;
    
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            int y = v / n;
            int x = v % n;
            if (y == n-1 && x == n-1)
                return ans[y][x];
            for (int k = 0; k < 8; k++) {
                int yy = y + m[k][0];
                int xx = x + m[k][1];
                if (yy < 0 || xx < 0 || yy >= n || xx >= n)
                    continue;
                if (ans[yy][xx] != 0 || grid[yy][xx] == 1)
                    continue;
                ans[yy][xx] = ans[y][x] + 1;
                que.push(yy*n+xx);
            }
        }
        return -1;
    }
};
