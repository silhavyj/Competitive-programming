class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        for (int i = n-1; i >= 0; i--) {
            if (grid[i][m-1] >= 0)
                break;
            for (int j = m-1; j >= 0; j--) {
                if (grid[i][j] >= 0)
                    break;
                ans++;
            }
        }
        return ans;
    }
};
