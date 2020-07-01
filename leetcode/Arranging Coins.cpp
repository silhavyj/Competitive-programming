class Solution {
public:
    typedef long long ll;
    
    int arrangeCoins(int n) {
        int l=0, r=n;
        while (l<=r) {
            int m=l+(r-l)/2;
            ll s=((ll)m*m+m)/2;
            if (s==n)
                return m;
            if (n<s)
                r=m-1;
            else l=m+1;
        }
        return r;
    }
};
