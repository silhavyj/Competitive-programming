class Solution {
    
    struct Point {
        int x, h;
        bool start;
    };
    
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> ans;
        vector<Point> points;
        map<int,int> mp;
        int totalMax=0;
        
        for (auto building : buildings) {
            points.push_back({building[0],building[2],true});
            points.push_back({building[1],building[2],false});
        }
        sort(points.begin(),points.end(), [](const Point p1, const Point p2) {
            if (p1.x != p2.x)
                return p1.x < p2.x;
            if (p1.start && p2.start)
                return p1.h > p2.h;
            else if (!p1.start && !p2.start)
                return p1.h < p2.h;
            return p1.start;
        });
        mp[0]=1;
        for (auto p : points) {
            if (p.start)
                mp[p.h]++;
            else {
                mp[p.h]--;
                if (mp[p.h] == 0)
                    mp.erase(p.h);
            }
            int maxx = mp.rbegin()->first;
            if (maxx != totalMax) {
                ans.push_back({p.x, maxx});
                totalMax = maxx;
            }
        }
        return ans;
    }
};
