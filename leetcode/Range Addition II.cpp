class Solution {
    #define min(a,b)((a)<(b)?(a):(b))
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x=m;
        int y=n;
        for (auto &op : ops) {
            x = min(x, op[0]);
            y = min(y, op[1]);
        }
        return y*x;
    }
};
