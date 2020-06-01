class Solution {
public:
    
    typedef long long ll;
    const int MOD = 1e9+7;
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int max_h = INT_MIN;
        int max_w = INT_MIN;
        
        horizontalCuts.push_back(0);
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(),horizontalCuts.end());
        for (int i = 0; i < horizontalCuts.size()-1; i++)
            max_h = max(max_h, horizontalCuts[i+1]-horizontalCuts[i]);
        
        verticalCuts.push_back(0);
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(),verticalCuts.end());
        for (int i = 0; i < verticalCuts.size()-1; i++)
            max_w = max(max_w, verticalCuts[i+1]-verticalCuts[i]);
        
        ll ans = (ll)max_w * max_h;
        return ans % MOD;
    }
};
