class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,list<int>> adj;
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for (auto &p : adj)
            if (p.second.size() == adj.size()-1)
                return p.first;
        return -1;
    }
};
