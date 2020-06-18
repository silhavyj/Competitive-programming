class Solution {
public:
    
    int hIndex(vector<int>& citations) {
        if (citations.empty())
            return 0;
        int ans = 0;
        int n = citations.size();
        for (int i = 1; i <= n; i++) {
            auto it = lower_bound(citations.begin(),citations.end(),i);
            int p = (it-citations.begin());
            if (n-p >= i)
                 ans = max(ans, i);
        } 
        return ans;
    }
};
