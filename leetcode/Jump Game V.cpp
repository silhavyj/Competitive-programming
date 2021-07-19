class Solution {
    unordered_map<int,int> dp;
    int getMaxJumps(vector<int> &arr, vector<vector<int>> &possibleJumps, int p) {
        if (possibleJumps[p].size()==0)
            return 0;
        if (dp.count(p))
            return dp[p];
        int ans = 0;
        for (int peek : possibleJumps[p])
            ans = max(ans, 1 + getMaxJumps(arr, possibleJumps, peek));
        return dp[p]=ans;
    }
public:
    int maxJumps(vector<int>& arr, int d) {
        if (arr.size()==0)
            return 0;
        vector<vector<int>> possibleJumps;
        for (int i = 0; i < arr.size(); i++) {
            vector<int> peek;
            for (int j=i-1; j >= 0 && i-j <= d && arr[j]<arr[i]; j--)
                peek.push_back(j);
            for (int j=i+1; j < arr.size() && j-i <= d && arr[j]<arr[i]; j++)
                peek.push_back(j);
            
            possibleJumps.push_back(peek);
        }
        int ans = 0;
        for (int i = 0; i < arr.size(); i++)
            ans = max(ans, getMaxJumps(arr,possibleJumps,i));
        return 1+ans;
    }
};
