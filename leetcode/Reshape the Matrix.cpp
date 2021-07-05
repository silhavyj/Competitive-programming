class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if (n*m != r*c)
            return mat;
        vector<vector<int>> ans;
        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                int s = i*c+j;
                row.push_back(mat[s/m][s%m]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
