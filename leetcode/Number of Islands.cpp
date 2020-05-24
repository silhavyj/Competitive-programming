class Solution {
public:
    
int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0)
        return 0;
    
    unordered_set<int> ones;
    int moves[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
    
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
            
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        	if (grid[i][j] == '1')
            	ones.insert(i*m+j);
            	
    while (ones.size()) {
    	int point = *(ones.begin());
    	ones.erase(point);
    	
    	queue<int> que;
    	que.push(point);
    	ans++;
    	
    	while (!que.empty()) {
    		int top = que.front();
    		que.pop();
    		
    		int y = top / m;
    		int x = top % m;
    		
    		for (int i = 0; i < 4; i++) {
    			int yy = y + moves[i][0];
    			int xx = x + moves[i][1];
    			if (yy < 0 || xx < 0 || xx >= m || yy >= n)
    				continue;
    			int pos = yy*m+xx;
    			if (ones.find(pos) == ones.end())
    				continue;
    				
    			ones.erase(pos);
    			que.push(pos);
			}
		}
	}
        
    return ans;
}
};
