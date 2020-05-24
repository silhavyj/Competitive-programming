class Solution {
public:
    
    bool biparite = true;
    
    void solve(vector<vector<int>>& graph, int curr, int *nodes, bool colr) {
        nodes[curr] = colr;
        for (auto n : graph[curr]) {
            if (nodes[n] == colr) {
                biparite = false;
                return;
            }
            if (nodes[n] == -1)
                solve(graph, n, nodes, !colr);
            if(!biparite)
                return;
        }
    } 
    
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes[graph.size()];
        memset(nodes, -1, sizeof(nodes));
        for (int i = 0; i < graph.size(); i++)
            if (nodes[i] == -1)
                solve(graph, i, nodes, 0);
        return biparite;
    }
};
