class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        #define pii pair<int,int>
        vector<vector<pii>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }
        int ans = 0;
        priority_queue<pii, vector<pii>, greater<pii>> que;
        vector<int> ranks(n, INT_MAX);
        ranks[0] = 0;
        que.push({0,0});
        
        while (!que.empty()) {
            auto t = que.top();
            que.pop();
            int u = t.second;
            for (auto v : adj[u]) {
                int d = ranks[u] + v.second + 1;
                if (d > maxMoves)
                    continue;
                if (ranks[v.first] > d) {
                    ranks[v.first] = d;
                    que.push({d,v.first});
                }
            }
        }
        for (int r : ranks)
            ans += r <= maxMoves;
        
        for (auto &e : edges) {
            int du = max(0, maxMoves - ranks[e[0]]);
            int dv = max(0, maxMoves - ranks[e[1]]);
            ans += min(e[2], du + dv);
        }
        return ans;
    }
};
