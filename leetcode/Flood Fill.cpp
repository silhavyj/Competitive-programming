class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor)
            return image;
        
        int moves[4][2] = {{-1,0}, {1,0}, {0,-1}, {0,1}};
        queue<pair<int,int>> que;
        que.push({sr,sc});
        int oldColor = image[sr][sc];
                
        image[sr][sc] = newColor;
        while (!que.empty()) {
            auto f = que.front();
            que.pop();
            for (int k = 0; k < 4; k++) {
                int yy = f.first + moves[k][0];
                int xx = f.second + moves[k][1];
                if (yy < 0 || xx < 0 || yy >= image.size() || xx >= image[0].size())
                    continue;
                if (image[yy][xx] == oldColor) {
                    image[yy][xx] = newColor;
                    que.push({yy,xx});
                }
            }
        }
        return image;
    }
};
