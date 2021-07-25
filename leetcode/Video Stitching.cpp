class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [=](auto &x, auto &y) {
            if (x[0] != y[0])
                return x[0] < y[0];
            return x[1] > y[1];
        });

        if (clips[0][0]!=0)
            return -1;
        int ans=1;
        int t=clips[0][1];
        int i = 0;
        
        while (i < clips.size()) {
            if (t >= time)
                break;
            int maxsf = i;
            for (int j = i+1; j < clips.size() && clips[j][0] <= t; j++) {
                if (clips[j][1] > clips[maxsf][1])
                    maxsf = j;
            }
            if (maxsf == i && clips[maxsf][1] < time)
                break;
            t = clips[maxsf][1];
            ans++;
            i = maxsf + 1;
        }
        if (t < time)
            return -1;
        return ans;
    }
};
