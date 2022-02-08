class Solution {

    vector<int> node_index, low_index;
    vector<vector<int>> ans;

    void dfs(vector<vector<int>> &adj, int &index, vector<int> &color, int x, int p) {
        color[x] = 1;
        node_index[x] = low_index[x] = index++;
        for (int y : adj[x]) {
            if (y == p)
                continue;
            if (color[y] == 0) {
                dfs(adj, index, color, y, x);
                low_index[x] = min(low_index[x], low_index[y]);
                if (low_index[y] > node_index[x])
                    ans.push_back({x,y});
            } else {
                low_index[x] = min(low_index[x], node_index[y]);
            }
        }
    }

public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for (auto &c : connections) {
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(c[0]);
        }
        node_index = vector<int>(n,-1);
        low_index = vector<int>(n,-1);
        vector<int> color(n,0);
        int index = 0;
        dfs(adj, index, color, 0, 0);
        return ans;
    }
};
