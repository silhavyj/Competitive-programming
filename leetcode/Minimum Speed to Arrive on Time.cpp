class Solution {
    bool inTime(vector<int>& dist, double hour, int speed) {
        double time = 0;
        for (int i = 0; i < dist.size(); i++) {
            if (i < dist.size() - 1)
                time += ceil((double)dist[i] / speed);
            else
                time += (double)dist[i] / speed;
            if (time > hour)
                return false;
        }
        return true;
    }
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int l=1, r=INT_MAX;
        while (l < r) {
            int m = l + (r-l) / 2;
            if (inTime(dist, hour, m))
                r = m-1;
            else
                l = m+1;
        }
        if (l == INT_MAX)
            return -1;
        
        if (inTime(dist, hour, l) == false)
            return l+1;
        return l;
    }
};
