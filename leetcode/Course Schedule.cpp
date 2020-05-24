class Solution {
public:
    
    bool possible = true;
    
    void solve(vector<list<int>>& adj, int* clr, int x) {
        clr[x] = 1;
        for (int n : adj[x]) {
            if (clr[n] == 1) {
                possible = false;
                return;
            }
            else if (clr[n] == 0) {
                solve(adj, clr, n);
                if (!possible)
                    return;
            }
        }
        clr[x] = 2;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<list<int>> adj(numCourses);
        int clr[numCourses];
        memset(clr, 0, sizeof(clr));
        for (int i = 0; i < prerequisites.size(); i++)
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        
        for (int i = 0; i < numCourses; i++) {
            if (clr[i] == 0)
                solve(adj,clr,i);
            if (possible == false)
                return false;
        }
        return true;
    }
};
