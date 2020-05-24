/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        int n = binaryMatrix.dimensions()[0];
        int m = binaryMatrix.dimensions()[1];
        int ans = INT_MAX;
        
        //return binaryMatrix.get(2,0);
        //return n;
        
        for (int i = 0; i < n; i++) {
            int l = 0;
            int r = m-1;
            
            if (binaryMatrix.get(i,m-1) == 0)
                continue;
            
             if (binaryMatrix.get(i,0) == 1)
                return 0;
            
            while ((r-l) > 1) {
                int mid = (l+r)/2;
                if (binaryMatrix.get(i,mid) == 0)
                    l = mid;
                else r = mid;
            }
            ans = min(ans, r); 
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
