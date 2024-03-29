class Solution {
public:
    vector<int> beautifulArray(int n) {
        vector<int> ans = {1};
        while (ans.size() < n) {
            vector<int> tmp;
            for (int x : ans)
                if (2*x-1 <= n)
                    tmp.push_back(2*x-1);
            for (int x : ans)
                if (2*x <= n)
                    tmp.push_back(2*x);
            ans = tmp;
        }
        return ans;
    }
};
