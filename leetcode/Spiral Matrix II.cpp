class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            vector<int> row(n);
            ans.push_back(row);
        }
        int y=0, x=0, i=1, dir=0, loops=0;
        while (i != n*n+1) {
            ans[y][x]=i++;
            switch (dir) {
                case 0:
                    if (x==n-1-loops) {
                        y++;
                        dir=1;
                    } else {
                        x++;
                    }
                    break;
                case 1:
                    if (y==n-1-loops) {
                        x--;
                        dir=2;
                    } else {
                        y++;
                    }
                    break;
                case 2:
                    if (x==loops) {
                        y--;
                        loops++;
                        dir=3;
                    } else {
                        x--;
                    }
                    break;
                case 3:
                    if (y==loops) {
                        x++;
                        dir=0;
                    } else {
                        y--;
                    }
                    break;
            }
        }
        return ans;
    }
};
