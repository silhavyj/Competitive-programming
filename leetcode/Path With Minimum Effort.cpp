class Solution {
public:
    int moves[4][2] = {
        {-1,0},    
        {0,-1},
        {1,0},
        {0,1},
    };
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > que;  
        que.push({0,0});
        int r = heights.size();
        int c = heights[0].size();
        vector<int> ranks(r*c, INT_MAX);
        ranks[0]=0;
        vector<int> done(r*c, 0);
        //cout << r << " " << c << '\n';
        while (!que.empty()) {
            auto t = que.top();
            que.pop();
            if (t.second==r*c-1)
                return t.first;
            int y = t.second / c;
            int x = t.second % c;
            //cout << y << " " << x << '\n';
            if (done[y*c+x])
                continue;
            done[y*c+x]=1;
            for (int i = 0; i < 4; i++) {
                int yy = y + moves[i][0]; 
                int xx = x + moves[i][1];
                if (yy >= 0 && xx >= 0 && yy < r && xx < c) {
                    int n = yy*c+xx;
                    if (done[n]==1)
                        continue;
                    int diff = min(ranks[n],max(t.first,abs(heights[y][x]-heights[yy][xx])));
                    if (diff <= ranks[n]) {
                        ranks[n] = diff;
                        que.push({diff,n});
                        //cout << n << " " << ranks[n] << " " << yy << " " << xx << "\n";
                    }
                }
            }
            
        }
        return INT_MAX;
    }
};
