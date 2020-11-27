#define ll long long int 
class Solution {
public:
    int mySqrt(int x) {
        if (x<=1)
            return x;
        int l=1, r=x-1, ans;
        while (l<=r) {
            int m = l+(r-l)/2;
            ll y = (ll)m*m;
            if (y==x)
                return m;
            if (y>x)
                r=m-1;
            else {
                ans=m;
                l=m+1;
            }
        }
        return ans;
    }
};
