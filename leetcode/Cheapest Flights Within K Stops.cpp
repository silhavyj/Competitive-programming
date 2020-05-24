class Solution {
public:
    
    struct Node {
        int rank,id,stops;
        bool operator<(const struct Node& other) const {
            return rank > other.rank;
        }
    };
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        vector<list<pair<int,int>>> g(n);
        int used[n];
        int ans = -1;
        
        for (int i = 0; i < n; i++)
            used[i] = false;
        used[src] = 0;
        
        for (auto f : flights)
            g[f[0]].push_back({f[1],f[2]});
        
        priority_queue<Node> que;
        que.push({0,src,-1});
        
        while (!que.empty()) {
            auto top = que.top();
            que.pop();      
			used[top.id] = true;     
            if (top.id == dst)
                return top.rank;
            
            for (auto p : g[top.id]) {
                int dis = top.rank + p.second;
                if (used[p.first] == false && top.stops < K)
                    que.push({dis,p.first,top.stops+1});
            }
        }
        return ans;
    }
};
