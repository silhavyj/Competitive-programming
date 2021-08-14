class Solution {
    int dp[100][100][100];
    
    int solve(vector<int> &boxes, int i, int j, int k) {
        if (i > j)
            return 0;
        if (dp[i][j][k] != 0)
            return dp[i][j][k];
        int ans = (k+1)*(k+1) + solve(boxes, i+1, j, 0);
        for (int p=i+1; p <= j; p++) {
            if (boxes[i]==boxes[p])
                ans = max(ans, solve(boxes, i+1, p-1, 0) + solve(boxes, p, j, k+1));
        }
        return dp[i][j][k] = ans;
    }
    
public:
    int removeBoxes(vector<int>& boxes) {
        memset(dp, 0, sizeof(dp));
        return solve(boxes, 0, boxes.size()-1, 0);
    }
};
