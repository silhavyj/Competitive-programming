class Solution {
public:
    
    bool possible = true;
    
    void solve(vector<list<int>>& adj, int *clr, int c, int x) {
        clr[x] = c;
        for (int y : adj[x]) {
            if (clr[y]==c) {
                possible = false;
                return;
            }
            else if (clr[y]==-1)
                solve(adj, clr, !c, y);
        }
    }
    
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        vector<list<int>> adj(N);
        for (auto d : dislikes) {
            adj[d[0]-1].push_back(d[1]-1);
            adj[d[1]-1].push_back(d[0]-1);
        }
        int clr[N];
        memset(clr, -1, sizeof(clr));
        solve(adj, clr, 0, 0);
        return possible;
    }
};
