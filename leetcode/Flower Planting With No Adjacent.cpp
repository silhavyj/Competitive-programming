class Solution {
    bool done = false;
    
    void solve(vector<vector<int>> &adj, int curr, vector<int> &colors, int visited) {
        vector<int> available(colors.size(),1);
        for (int n : adj[curr])
            if (colors[n]!=0)
                available[colors[n]-1]=0;
        
        for (int i = 0; i < available.size(); i++) {
            if (available[i]) {
                colors[curr] = i+1;
                bool anyleft = false;
                for (int n : adj[curr]) {
                    if (colors[n]==0) {
                        anyleft = true;
                        solve(adj, n, colors, visited + 1);
                        if (done)
                            return;
                    }
                }
                if (anyleft==false) {
                    done = true;
                    return;
                }
                colors[curr] = 0;
            }
        }
    }
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>> adj(n);
        for (auto path : paths) {
            adj[path[0]-1].push_back(path[1]-1);
            adj[path[1]-1].push_back(path[0]-1);
        }
        vector<int> colors(n,0);
        for (int i = 0; i < n; i++)
            if (colors[i]==0) {
                done=false;
                solve(adj, i, colors, 0);
            }
        return colors;
    }
};
