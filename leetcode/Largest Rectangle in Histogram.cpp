class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int s1[n], s2[n], p=0;
        int tmpH, tmpP;
        int ans = 0;
        int i = 0;
        
        for (; i < n; i++) {
            if (p==0 || heights[i] > s1[p-1]) {
                s1[p] = heights[i];
                s2[p] = i;
                p++;
            } else if (heights[i] < s1[p-1]){
                while (p && heights[i] < s1[p-1]) {
                    tmpH = s1[p-1];
                    tmpP = s2[p-1];
                    p--;
                    ans = max(ans, tmpH * (i-tmpP));
                }
                s1[p] = heights[i];
                s2[p] = tmpP;
                p++;
            }
        }
        while (--p >= 0)
            ans = max(ans, s1[p] * (i-s2[p]));
        return ans;
    }
};
