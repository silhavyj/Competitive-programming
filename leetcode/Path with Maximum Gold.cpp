class Solution {
public:
int ans = 0;
int moves[4][2] = {{-1,0},{0,-1},{1,0},{0,1}};

void solve(vector<vector<int>>& grid, int i, int j, int n, int m, int sum) {
	int price = grid[i][j];
	sum += price;
	grid[i][j] = 0;
	
	ans = max(ans, sum);
	for (int k = 0; k < 4; k++) {
		int y = i + moves[k][0];
		int x = j + moves[k][1];
		if (y < 0 || x < 0 || y >= n || x >= m)
			continue;
		if (grid[y][x] != 0)
			solve(grid, y, x, n, m, sum);
	}
	grid[i][j] = price;
}

int getMaximumGold(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = !n ? 0 : grid[0].size();
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (grid[i][j] != 0)
				solve(grid,i,j,n,m,0);
			
	return ans;
}
};
