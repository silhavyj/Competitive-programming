class Solution {
public:
    
    
    void dfs(vector<list<pair<int,int>>> &g, int curr, int time, bool *visited, int *res) {
        visited[curr] = true;
        if (res[curr] == -1)
            res[curr] = time;
        
        else res[curr] = min(res[curr], time);

        for (auto next : g[curr])
            if (visited[next.first] == false)
                if (res[next.first] > time + next.second || res[next.first] == -1)
                    dfs(g, next.first, time + next.second, visited, res);
        
        visited[curr] = false;
    }
    
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        vector<list<pair<int,int>>> g(N);
        bool visited[N];
        int res[N];
        
        memset(visited, false, sizeof(visited));
        memset(res, -1, sizeof(res));

        for (auto time : times)
            g[time[0]-1].push_back(make_pair(time[1]-1,time[2]));
        
        dfs(g, K-1, 0, visited, res);
        
        int ans = -1;
        for (int i = 0; i < N; i++) {
            if (res[i] == -1)
                return -1;
            ans = max(ans, res[i]);
        }
    
        /*for (int i = 0; i < N; i++)
            if (poss[i] == false)
                return -1;*/
        
        return ans;
    }
};
