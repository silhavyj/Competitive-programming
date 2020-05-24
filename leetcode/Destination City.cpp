class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> cities;
        
        for (auto p : paths) cities.insert(p[1]);
        for (auto p : paths) cities.erase(p[0]);

        return *(cities.begin());
    }
};
