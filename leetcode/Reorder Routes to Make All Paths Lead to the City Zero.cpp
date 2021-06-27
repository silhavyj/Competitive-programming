class Solution {
    int ans=0;
    void dfs(vector<vector<pair<int,bool>>> &adj, vector<bool> &visited, int x) {
        visited[x] = true;
        for (pair<int,bool> &p : adj[x])
            if (!visited[p.first]) {
                if (!p.second)
                    ans++;
                dfs(adj, visited, p.first);
            }
    }
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<bool> visited(n,false);
        vector<vector<pair<int,bool>>> adj(n);
        for (auto &c : connections) {
            adj[c[0]].push_back({c[1],false});
            adj[c[1]].push_back({c[0],true});
        }
        for (int i = 0; i < n; i++)
            if (!visited[i])
                dfs(adj,visited,i);
        return ans;
    }
};
