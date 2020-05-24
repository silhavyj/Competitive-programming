// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int L=1, R=n;
        
        while (L < R) {
            if (L == R-1 && !isBadVersion(L) && isBadVersion(R))
                return R;
                
            int mid = L+(R-L) / 2;
            if (!isBadVersion(mid))
                L = mid;
            else R = mid;
        }
        return isBadVersion(1) ? 1 : -1;
    }
};
