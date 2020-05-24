class Solution {
public:
    
    int test(int p1, int p2, vector<vector<int>>& points) {
        int dx = abs(points[p1][0]-points[p2][0]);
        int dy = abs(points[p1][1]-points[p2][1]);
        double d = INT_MAX;
        if (dx != 0)
            d = dy / (double)dx;
        int ans = 0;
        for (int i = 0; i < points.size(); i++) {
           // if (i == p1 || i == p2)
           //     continue;
            
            int ddx = abs(points[p1][0]-points[i][0]);
            int ddy = abs(points[p1][1]-points[i][1]);
            if (ddx == 0 && ddy == 0) {
                ans++;
                continue;
            }
            double dd1 = INT_MAX;
            if (ddx != 0)
                dd1 = ddy / (double)ddx;
            
            ddx = abs(points[p2][0]-points[i][0]);
            ddy = abs(points[p2][1]-points[i][1]);
             if (ddx == 0 && ddy == 0) {
                ans++;
                continue;
            }
            double dd2 = INT_MAX;
            if (ddx != 0)
                dd2 = ddy / (double)ddx;
            
            if (dd1 == d && dd2 == d)
                ans++;
        }
        return ans;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        if (points.size()==0)
            return 0;
        int ans = 1;
        for (int i = 0; i < points.size(); i++)
            for (int j = i+1; j < points.size(); j++)
                ans = max(ans, test(i,j,points));
        
        return ans;
    }
};
