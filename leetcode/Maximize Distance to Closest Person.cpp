class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n = seats.size();
        vector<int> r(n+2);
        vector<int> l(n+2);
        r[0] = l[0] = r[n+1] = l[n+1] = -1;
        for (int i = 1; i <= n; i++) {
            if (seats[i-1] == 1)
                l[i] = i-1;
            else
                l[i] = l[i-1];
        }
        for (int i = n; i >= 1; i--) {
            if (seats[i-1] == 1)
                r[i] = i-1;
            else
                r[i] = r[i+1];
        }
        int ans = INT_MIN;
        for (int i = 1; i < n+1; i++) {
            if (l[i]==-1)
                ans = max(ans, r[i]);
            else if (r[i]==-1)
                ans = max(ans, (int)seats.size()-l[i]-1);
            else if (l[i] != r[i])
                ans = max(ans, abs(min(i-1-l[i], r[i]-(i-1))));
        }
        return ans;
    }
};
