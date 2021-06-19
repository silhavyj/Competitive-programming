class Solution {
public:
    vector<int> ans;
    bool possible = true;
    
    void dfs(vector<vector<int>> &adj, vector<int> &state, int n) {
        if (possible == false)
            return;
        state[n] = 1;
        for (int x : adj[n]) {
            if (state[x]==1) {
                possible = false;
                return;
            }
            if (state[x]==0)
                dfs(adj, state, x);
        }
        state[n] = 2;
        ans.insert(ans.begin(),n);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {    
        vector<vector<int>> adj(numCourses);
        for (auto p : prerequisites)
            adj[p[1]].push_back(p[0]);
        vector<int> state(numCourses,0);
        for (int i = 0; i < numCourses; i++)
            if (state[i]==0) {
                dfs(adj, state, i);
                if (possible == false)
                    return {};
            }
        return ans;
    }
};
