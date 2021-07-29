class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        static int moves[4][2] {
            {-1,0},
            {1,0},
            {0,-1},
            {0,1}
        };
        int n = mat.size();
        int m = mat[0].size();
        queue<int> que;
        vector<vector<int>> ans(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = INT_MAX;
                if (mat[i][j]==0) {
                    que.push(i*m+j);
                    ans[i][j]=0;
                }
            }
        }
        while (!que.empty()) {
            auto t = que.front();
            que.pop();
            int y = t/m, x=t%m;
            for (int k = 0; k < 4; k++) {
                int yy = y + moves[k][0]; 
                int xx = x + moves[k][1];
                if (yy >= 0 && xx >= 0 && yy < n && xx < m && ans[yy][xx] > ans[y][x] + 1) {
                    ans[yy][xx] = 1 + ans[y][x];
                    que.push(yy*m+xx);
                }
            }
        }
        return ans;
    }
};
