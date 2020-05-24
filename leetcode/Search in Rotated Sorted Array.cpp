class Solution {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0)
            return -1;
        
        int p = 0;
        
        for (int i = 0; i < nums.size()-1; i++)
            if (nums[i] > nums[i+1]) {
                p = i;
                break;
            }
        
        if (nums[p] == target)
            return p;
        
        int L = p+1;
        int R = nums.size()-1;
        
        while (L >=0 && R < nums.size() && L <= R) {
            int m = (L+R)/2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                R = m-1;
            else L = m+1;
        }
        
        L = 0;
        R = p;
        
        while (L >=0 && R < nums.size() && L <= R) {
            int m = (L+R)/2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                R = m-1;
            else L = m+1;
        }
        
        return -1;
    }
};
