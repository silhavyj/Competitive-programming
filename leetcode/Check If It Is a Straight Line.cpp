class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if (coordinates.size() == 1)
            return true;
        
        double d = INT_MAX;
        int dx = coordinates[1][0]-coordinates[0][0];
        int dy = coordinates[1][1]-coordinates[0][1];
        if (dx != 0)
            d = (double)dy / dx;
        
        for (int i = 1; i < coordinates.size()-1; i++) {
            dx = coordinates[i+1][0]-coordinates[i][0];
            dy = coordinates[i+1][1]-coordinates[i][1];
            double dd = INT_MAX;
            if (dx != 0)
                dd = (double)dy / dx;
            if (dd != d)
                return false;
        }
        return true;
    }
};
