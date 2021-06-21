class Solution {
private:
    int moves[8][2] = {
        {-1,-1},
        {-1,0},
        {-1,1},
        {0,1},
        {1,1},
        {1,0},
        {1,-1},
        {0,-1}
    };
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        vector<vector<int>> ans;
        for (int i = 0; i < img.size(); i++) {
            vector<int> row;
            for (int j = 0; j < img[i].size(); j++) {
                int count=1;
                int sum=img[i][j];
                for (int k = 0; k < 8; k++) {
                    int y = i+moves[k][0];
                    int x = j+moves[k][1];
                    if (y >= 0 && x >= 0 && y < img.size() && x < img[i].size()) {
                        sum += img[y][x];
                        count++;
                    }
                }
                row.push_back(floor((sum/(double)count)));
                //cout << sum << " " << count << '\n';
            }
            ans.push_back(row);
        }
        return ans;
    }
};
