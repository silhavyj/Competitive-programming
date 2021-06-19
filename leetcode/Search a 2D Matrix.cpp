class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0, r=matrix.size()*matrix[0].size()-1;
        while (l<=r) {
            int m = l+(r-l)/2;
            int val = matrix[m/matrix[0].size()][m%matrix[0].size()];
            if (target == val)
                return true;
            if (target > val)
                l=m+1;
            else
                r=m-1;
        }
        return false;
    }
};
