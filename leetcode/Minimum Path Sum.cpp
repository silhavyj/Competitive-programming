class Solution {
public:
int minPathSum(vector<vector<int>>& grid) {
	int n = grid.size();
	int m = grid[0].size();
	
	int moves[2][2] = {{1,0},{0,1}};
	
	int nodes[n*m];
	nodes[0] = grid[0][0];
	
	for (int i = 0; i < n*m; i++)
		nodes[i] = INT_MAX;
	
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> que;
	que.push({grid[0][0], 0});
	
	while (!que.empty()) {
		auto top = que.top();
		que.pop();
		
		int val = top.first;
		int y = top.second / m;
		int x = top.second % m; 
		
		//cout << y << " " << x << endl;
		
		if (y == n-1 && x == m-1)
			return top.first;
		
		for (int i = 0; i < 2; i++) {
			int yy = y + moves[i][0];
			int xx = x + moves[i][1];
			
			if (xx < 0 || yy < 0 || xx >= m || yy >= n)
				continue;
				
			int node = yy*m+xx;
			
			/*cout << "node " << node << endl;
			cout << nodes[node] << endl;*/
			
			if (nodes[node] > val + grid[yy][xx]) {
				nodes[node] = val + grid[yy][xx];
				que.push({val + grid[yy][xx], node});
			}
		}
	}
	return 0;        
}
};
