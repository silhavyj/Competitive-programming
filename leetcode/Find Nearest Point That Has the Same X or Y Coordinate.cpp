class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int minX = INT_MAX;
        int minY = INT_MAX;
        int indexX=-1;
        int indexY=-1;
        int i=0;
        for (auto point : points) {
            if (point[0]==x && abs(point[1]-y) < minY) {
                minY = abs(point[1]-y);
                indexY = i;            
            }
            if (point[1]==y && abs(point[0]-x) < minX) {
                minX = abs(point[0]-x);
                indexX = i;
            }
            i++;
        }
        if (minX == INT_MAX && minY == INT_MAX)
            return -1;
        return minX < minY ? indexX : indexY;
    } 
};
