class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for (int i = 0; i < matrix[0].size(); i++) {
            int l=0, r=matrix.size()-1;
            while (l<=r) {
                int m=l+(r-l)/2;
                if (matrix[m][i]==target)
                    return true;
                if (target>matrix[m][i])
                    l=m+1;
                else
                    r=m-1;
            }
        }
        return false;
    }
};
