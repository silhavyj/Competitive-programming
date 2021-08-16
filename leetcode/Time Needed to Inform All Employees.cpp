class Solution {
    int solve(vector<vector<int>> &adj, int currManager, vector<int>& informTime, vector<bool> &hasBeenInformed) {
        if (hasBeenInformed[currManager])
            return 0;
        int time = informTime[currManager];
        int slowestManagerTime = 0;
        for (int &employee : adj[currManager])
            slowestManagerTime = max(slowestManagerTime, solve(adj, employee, informTime, hasBeenInformed));
        time += slowestManagerTime;
        hasBeenInformed[currManager] = true;
        return time;
    }
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        vector<bool> hasBeenInformed(n, false);
        for (int i = 0; i < manager.size(); i++) 
            if (i != headID)
                adj[manager[i]].push_back(i);
        return solve(adj, headID, informTime, hasBeenInformed);
    }
};
