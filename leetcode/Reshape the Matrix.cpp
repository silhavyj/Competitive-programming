class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        vector<int> vals;
        
        for (auto row : nums)
            for (int x : row)
                vals.push_back(x);
        
        vector<vector<int>> res;
        int p = 0;
        
        for (int i = 0; i < r; i++) {
            vector<int> row;
            for (int j = 0; j < c; j++) {
                if (p == vals.size())
                    return nums;
                row.push_back(vals[p++]);
            }
            res.push_back(row);
        }
        return res;
    }
};
