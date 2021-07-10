class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int closest_ghost = INT_MAX;
        for (auto g : ghosts)
            closest_ghost = min(closest_ghost, abs(target[0]-g[0]) + abs(target[1]-g[1]));
        return (abs(target[0])+abs(target[1])) < closest_ghost;
    }
};
