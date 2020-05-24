class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        list<pair<int,int>> zeros;
        for (int i = 0; i < matrix.size(); i++)
            for (int j=0; j<matrix[i].size(); j++)
                if (matrix[i][j] == 0) {
                    /*for (int k=0;k<matrix[i].size();k++)
                        matrix[i][k]=0;
                    for (int k=0;k<matrix.size();k++)
                        matrix[k][j]=0;*/
                    zeros.push_back(make_pair(i,j));
                }
        for (auto p : zeros) {
            int y=p.first;
            int x=p.second;
            
            for (int i=0;i<matrix.size();i++)
                matrix[i][x]=0;
            for (int i=0;i<matrix[0].size();i++)
            matrix[y][i]=0;
        }
    }
};
