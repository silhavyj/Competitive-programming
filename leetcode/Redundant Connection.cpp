class Solution {
private:
    
    bool found=false;
    int startCycle=-1;
    
    struct Edge {
        int f,t;
        Edge(int f, int t) : f(f), t(t){}
        Edge(const Edge& other) {
	    	memcpy(this, &other, sizeof(Edge));
    	}
        bool operator==(const Edge& other) const {
            return (f==other.f && t==other.t) || (f==other.t && t==other.f);
        }
    };
    
    struct EdgeHash {
        size_t operator()(const Edge& edge) const {    
            int h = 31;
			h = 17 * h + min(edge.f,edge.t);
            h = 17 * h + max(edge.f,edge.t);
		    return h;
	    }
    };
    
    void solve(vector<vector<int>> &adj, vector<int> &state, int curr, int prev, vector<int> &cycle) {
        state[curr] = 1;
        cycle.push_back(curr);
        
        for (int n : adj[curr]) {
            if (n==prev)
                continue;
            if (state[n] == 1) {
                found = true;
                for (int i = 0 ; i < cycle.size(); i++)
                    if (cycle[i]==n) {
                        startCycle = i;
                        return;
                    }
            } else if (state[n] == 0) {
                solve(adj, state, n, curr, cycle);
                if (found)
                    return;
            }
        }
        state[curr] = 2;
        cycle.pop_back();
    }
    
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_set<int> nodes;
        unordered_map<Edge,int,EdgeHash> pos;
        int id = 0;
        
        for (int i = 0; i < edges.size(); i++) {
            nodes.insert(edges[i][0]-1);
            nodes.insert(edges[i][1]-1);
            Edge edge(edges[i][0]-1,edges[i][1]-1);
            pos[edge] = id++;
        }
        vector<vector<int>> adj(nodes.size());
        vector<int> state(nodes.size(),0);
        for (auto &e : edges) {
            adj[e[0]-1].push_back(e[1]-1);
            adj[e[1]-1].push_back(e[0]-1);
        }
        vector<int> cycle;
        solve(adj, state, 0, -1, cycle);
    
        Edge ans(cycle[startCycle],cycle[startCycle+1]);
        int lastPos = -1;
        for (int i = startCycle; i < cycle.size()-1; i++) {
            Edge e(cycle[i],cycle[i+1]);
            if (pos[e] > lastPos) {
                lastPos = pos[e];
                ans = e;
            }
        }
        Edge e(cycle[cycle.size()-1],cycle[startCycle]);
        if (pos[e] > lastPos) {
            lastPos = pos[e];
            ans = e;
        }
        for (auto &e : edges)
            if (min(e[0],e[1]) == min(ans.f+1,ans.t+1) && max(e[0],e[1]) == max(ans.f+1,ans.t+1))
                return {e[0],e[1]};
        return {};
    }
};
