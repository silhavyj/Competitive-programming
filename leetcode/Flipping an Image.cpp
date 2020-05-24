class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        vector<vector<int>> ans;
        for (auto a : A) {
            int n = a.size();
            for (int i = 0; i < n/2; i++) {
                a[i] = a[i] ^ a[n-i-1];
                a[n-i-1] = a[i] ^ a[n-i-1];
                a[i] = a[i] ^ a[n-i-1];
            }
            for (int i = 0; i < n; i++)
                a[i] = !a[i];
            ans.push_back(a);
        }
        return ans;
    }
};
