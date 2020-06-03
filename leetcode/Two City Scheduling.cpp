class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int ans = 0;
        sort(costs.begin(), costs.end(), [](vector<int> &a, vector<int> &b) {
           return a[0]-a[1] < b[0]-b[1];  
        });
        for (int i = 0; i < costs.size(); i++)
            ans += i < costs.size()/2 ? costs[i][0] : costs[i][1];
        return ans;
    }
};
