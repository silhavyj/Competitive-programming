class Solution {
public:
    
    bool ans=false;
    
    void solve(vector<int>& arr, int s, vector<bool> &dp) {
        if (ans)
            return;
        dp[s]=true;
        if (arr[s]==0) {
            ans=true;
            return;
        } 
        if (s+arr[s]<arr.size()&&!dp[s+arr[s]])
            solve(arr,s+arr[s],dp);
        if (s-arr[s]>=0&&!dp[s-arr[s]])
            solve(arr,s-arr[s],dp);
    }
    
    bool canReach(vector<int>& arr, int start) {
        vector<bool> dp(arr.size(),false);
        solve(arr,start,dp);
        return ans;
    }
};
