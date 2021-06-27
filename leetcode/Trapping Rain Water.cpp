class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty())
            return 0;
        
        vector<int> maxL(height.size());
        maxL[0] = height[0];
        for (int i = 1; i < height.size(); i++)
            maxL[i] = max(height[i], maxL[i-1]);
        
        vector<int> maxR(height.size());
        maxR[height.size()-1] = height[height.size()-1];
        for (int i = height.size()-2; i >= 0; i--)
            maxR[i] = max(height[i], maxR[i+1]);
        
        int ans=0;
        for (int i = 0; i < height.size(); i++)
            ans += min(maxL[i],maxR[i]) - height[i]; 
        return ans;
    }
};
