class Solution {
public:
    int numPoints(vector<vector<int>>& points, int r) {
        int n  = points.size();
        if (n == 0)
            return 0;
        int ans = 1;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j)
                    continue;
                double x1 = points[i][0];
                double y1 = points[i][1];
                double x2 = points[j][0];
                double y2 = points[j][1];
                double d = sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
                if (d > 2*r)
                    continue;
                double cx = (x1+x2)/2.0;
                double cy = (y1+y2)/2.0;
                double v = d/2.0;
                double a = atan2(y2-y1,x2-x1);
                double t = sqrt(r*r-v*v);
                double p1x = cx + t * sin(a);
                double p1y = cy - t * cos(a);
                double p2x = cx - t * sin(a);
                double p2y = cy + t * cos(a);
                                
                int count = 0;
                for (auto p : points)
                    if (sqrt((p[0]-p1x)*(p[0]-p1x)+(p[1]-p1y)*(p[1]-p1y)) <= r+0.00001)
                        count++;
                count = 0;
                for (auto p : points)
                    if (sqrt((p[0]-p2x)*(p[0]-p2x)+(p[1]-p2y)*(p[1]-p2y)) <= r+0.00001)
                        count++;
                ans = max(ans,count);
            }
        }
        return ans;
    }
};
