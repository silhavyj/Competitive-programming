class Solution {
public:
    double trimMean(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        vector<int> sum(n);
        sum[0] = arr[0];
        for (int i = 1; i < n; i++)
            sum[i] = sum[i-1] + arr[i];
        
        int e = n * 0.05;
        int sum2 = sum[n-1-e] - sum[e-1];
        return (double)sum2 / (n-2*e);
    }
};
