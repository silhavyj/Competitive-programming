class Solution {
public:
    
    vector<string> ans;
    unordered_map<string, vector<string>> adj;
    int used_tickets = 0;
    int tickets_count;
    
    bool dfs(string airport) {
        if (used_tickets == tickets_count)
            return true;
        
        for (auto it = adj[airport].begin(); it != adj[airport].end(); it++) {
            string next = *it;
            adj[airport].erase(it);
            ans.push_back(next);
            used_tickets++;
            if (dfs(next))
                return true;
            adj[airport].insert(it,next);
            ans.pop_back();
            used_tickets--;
        }
        return false;
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        tickets_count = tickets.size();
        for (auto ticket : tickets)
            adj[ticket[0]].push_back(ticket[1]);  
        for (auto &a : adj)
            sort(a.second.begin(), a.second.end());
        ans.push_back("JFK");
        dfs("JFK");
        return ans;
    }
};
