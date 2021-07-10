class Solution {
    int moves[4][2] {
        {-1,0},
        {1,0},
        {0,1},
        {0,-1}
    };
    
    bool found = false;
    
    void find(vector<vector<int>> &adj, int c, int p, vector<int> &states) {
        if (found)
            return;
        states[c]=1;
        for (int x : adj[c]) {
            if (x == p)
                continue;
            if (states[x]==1) {
                found = true;
                return;
            } else if (states[x] == 0) {
                find(adj, x, c, states);
            }
        }
        states[c]=2;
    }
    
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> adj(n*m);
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                for (int k = 0; k < 4; k++) {
                    int y = i + moves[k][0];
                    int x = j + moves[k][1];
                    if (y >= 0 && x >= 0 && y < n && x < m && grid[y][x] == grid[i][j])
                        adj[i*m+j].push_back(y*m+x);
                }
            }
        }
        vector<int> states(n*m,0);
        for (int i = 0; i < n*m; i++) {
            if (states[i]==0)
                find(adj,i,-1,states);
            if (found)
                return true;
        }
        return false;
    }
};
