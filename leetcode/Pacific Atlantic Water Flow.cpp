class Solution {
public:
    static const int MAX = 200;
    bool visited[MAX][MAX] = {0};
    vector<vector<int>> ans;
    int n=0,m=0;
    
    int moves[4][2] = {
        {-1,0},
        {1,0},
        {0,-1},
        {0,1}
    };
    
    bool pacific=false;
    bool atlantic=false;
    
    void test(int y, int x, vector<vector<int>>& heights) {
        if (visited[y][x])
            return;
        visited[y][x] =true;
        if (pacific && atlantic)
            return;
        if ((y==0 && x<m-1) || (x==0 && y<n-1)) {
            pacific=true;
        }
        if ((x==m-1 && y>0) || (x>0 && y==n-1)) {
            atlantic=true;
        }
        if ((y==0 && x==m-1) || (y==n-1 && x==0)) {
            pacific=true;
            atlantic=true;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + moves[i][0];
            int xx = x + moves[i][1];
            if (yy >= 0 && xx >=0 && yy < n && xx < m && heights[y][x] >= heights[yy][xx])
                test(yy,xx,heights);
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                memset(visited,0,sizeof(visited));
                pacific=false;
                atlantic=false;
                test(i,j,heights);
                if (pacific && atlantic)
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
};
