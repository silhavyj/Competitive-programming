class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<pair<double,int>> dis;
        vector<vector<int>> ans;
        for (int i = 0; i < points.size(); i++)
            dis.push_back({sqrt(points[i][0]*points[i][0]+points[i][1]*points[i][1]),i});
        sort(dis.begin(), dis.end());
        for (int i = 0; i < K; i++)
            ans.push_back({points[dis[i].second][0],points[dis[i].second][1]});
        return ans;
    }
};
