class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp1(n, 1);
        vector<int> dp2(n, 1);
        int ans = 1;

        for (int i = 1; i < n; i++) {
            if ((i % 2 == 1 && arr[i-1] < arr[i]) ||
                (i % 2 == 0 && arr[i-1] > arr[i])) {
                dp1[i] = dp1[i-1] + 1;
            }
            if ((i % 2 == 0 && arr[i-1] < arr[i]) ||
                (i % 2 == 1 && arr[i-1] > arr[i])) {
                dp2[i] = dp2[i-1] + 1;
            }
            ans = max(ans, max(dp1[i], dp2[i]));
        }
        return ans;
    }
};
