auto speedup=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    
    bool cycle;
    
    void solve(vector<vector<int>>& graph, int x, int *state) {
        state[x] = 1;
        for (auto n : graph[x]) {
            if (state[n] == 1) {
                cycle = true; 
                return;
            }
            if (state[n] == 0) {
                solve(graph, n, state);
                if (cycle)
                    return;
            }
        }
        state[x] = 2;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        int n = graph.size();
        int state[n];
        
        memset(state, 0, sizeof(state));
        for (int i = 0; i < n; i++) {
            cycle = false;
            solve(graph, i, state);
            if (!cycle)
                res.push_back(i);
        }
        return res;
    }
};
