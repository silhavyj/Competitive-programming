class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> arr(matrix.size()*matrix[0].size());
        int p=0;
        for (auto &row : matrix)
            for (auto &x : row)
                arr[p++]=x;
        sort(arr.begin(), arr.end());
        return arr[k-1];
    }
};
