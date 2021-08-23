class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        vector<int> sum(arr.size(), 0);
        sum[0] = arr[0];
        for (int i = 1; i < arr.size(); i++)
            sum[i] = sum[i-1] + arr[i];
        
        int ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            for (int j = i; j < arr.size(); j++) {
                if ((j-i+1) & 1) {
                    if (i==0)
                        ans += sum[j];
                    else
                        ans += sum[j] - sum[i-1];
                }
            }
        }
        return ans;
    }
};
