class Solution {
    void dfs(vector<vector<int>> &adj, int x, vector<bool> &seen) {
        seen[x]=true;
        for (int n : adj[x])
            if (!seen[n])
                dfs(adj, n, seen);
    }
public:
    int regionsBySlashes(vector<string>& grid) {
        int m = grid.size();
        int n = m*m*4;
        int index, index2;
        vector<vector<int>> adj(n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) {
                index = (i*m+j)*4;
                if (grid[i][j]==' ') {
                    adj[index].push_back(index+1);
                    adj[index].push_back(index+3);
                    adj[index+1].push_back(index);
                    adj[index+1].push_back(index+2);
                    adj[index+2].push_back(index+3);
                    adj[index+2].push_back(index+1);
                    adj[index+3].push_back(index);
                    adj[index+3].push_back(index+2);
                } else if (grid[i][j]=='/') {
                    adj[index].push_back(index+3);
                    adj[index+1].push_back(index+2);
                    adj[index+2].push_back(index+1);
                    adj[index+3].push_back(index);
                } else if (grid[i][j]=='\\') {
                    adj[index].push_back(index+1);
                    adj[index+1].push_back(index);
                    adj[index+2].push_back(index+3);
                    adj[index+3].push_back(index+2);
                }
                if (i-1 >= 0) {
                    index2 = ((i-1)*m+j)*4;
                    adj[index2+2].push_back(index);
                    adj[index].push_back(index2+2);
                }
                if (i+1 < m) {
                    index2 = ((i+1)*m+j)*4;
                    adj[index2].push_back(index+2);
                    adj[index+2].push_back(index2);
                }
                if (j-1 >= 0) {
                    index2 = (i*m+(j-1))*4;
                    adj[index2+1].push_back(index+3);
                    adj[index+3].push_back(index2+1);
                }
                if (j+1 < m) {
                    index2 = (i*m+(j+1))*4;
                    adj[index2+3].push_back(index+1);
                    adj[index+1].push_back(index2+3);
                }
            }
        }
        int ans = 0;
        vector<bool> seen(m*m*4,0);
        for (int i = 0; i < m*m*4; i++) {
            if (!seen[i]) {
                ans++;
                dfs(adj, i, seen);
            }
        }
        return ans;
    }
};
