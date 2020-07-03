class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<int> tmp(8,0);
        N = N%14==0 ? 14 : N%14;
        while (N--) {
            for (int i=1; i<cells.size()-1; ++i)
                tmp[i]=(cells[i-1]==1 && cells[i+1]==1) || (cells[i-1]==0 && cells[i+1]==0);
            for (int i=0; i<cells.size(); ++i)
                cells[i]=tmp[i];
        }
        return cells;
    }
};
