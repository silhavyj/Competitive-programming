class Solution {
public:
    
    void dfs(vector<vector<int>>& rooms, bool *visited, int curr) {
        visited[curr] = true;
        for (auto next : rooms[curr])
            if (visited[next] == false)
                dfs(rooms, visited, next);
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        bool visited[rooms.size()];
        memset(visited, false, sizeof(visited));
        dfs(rooms, visited, 0);
        for (int i = 0; i < rooms.size(); i++)
            if(visited[i] == false)
                return false;
        return true;
    }
};
