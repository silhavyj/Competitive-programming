class Solution {
    #define ll long long
    
    bool binary_search(ll l, ll r, int n) {
        while (l <= r) {
            ll m = l + (r-l)/2;
            if (m*m == n)
                return true;
            if (m*m > n)
                r = m-1;
            else
                l = m+1;
        }
        return false;
    }
public:
    bool judgeSquareSum(int c) {
        for (ll a = 0; a*a <= c; a++) {
            ll b = c - a*a;
            if (binary_search(0, b, b))
                return true;
        }
        return false;
    }
};
