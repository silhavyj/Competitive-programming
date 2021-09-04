class Solution {
    void preorder(int u, int par, int n, vector<vector<int>> &adj, vector<int> &ans, vector<int> &count) {
        for (int v : adj[u]) {
            if (v == par)
                continue;
            ans[v] = n + ans[u] - 2 * count[v];
            preorder(v, u, n, adj, ans, count);
        }
    }
    
    void postorder(int u, int par, vector<vector<int>> &adj, vector<int> &ans, vector<int> &count) {
        for (int v : adj[u]) {
            if (v == par)
                continue;
            postorder(v, u, adj, ans, count);
            ans[u] += ans[v] + count[v];
            count[u] += count[v];
        }
        count[u]++;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n, 0);
        vector<int> count(n, 0);

        vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        postorder(0, -1, adj, ans, count);
        preorder(0, -1, n, adj, ans, count);
        return ans;
    }
};
