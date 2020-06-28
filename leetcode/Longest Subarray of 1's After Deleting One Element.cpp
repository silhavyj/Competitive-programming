class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        vector<int> count;
        int c=0;
        bool allZeros=1;
        for (int i=0; i<nums.size(); ++i) {
            if (nums[i]==0) {
                if (c) {
                    count.push_back(c);    
                    allZeros=0;
                }
                count.push_back(0);
                c=0;
            }
            else c++;
        }
        if (c) {
            count.push_back(c);
            allZeros=0;
        }
        if (allZeros)
            return 0;
        if (count.size()==1)
            return count[0]-1;
        if (count.size()==2)
            return max(count[0],count[1]);
        
        int sum=0, ans=0;
        for (int i=0; i<3; ++i)
            sum+=count[i];
        
        for (int j=0; ;++j) {
            ans=max(ans,sum);
            if (j+3==count.size())
                break;
            sum+=count[3+j];
            sum-=count[j];
        }
        return ans; 
    }
};
