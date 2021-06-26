class Solution {
    
    void sort(vector<pair<int,int>> &nums, vector<int> &count, int l, int r) {
        if (l >= r)
            return;
        int m = l+(r-l)/2;
        sort(nums, count, l,m);
        sort(nums, count, m+1,r);
        vector<pair<int,int>> tmp(r-l+1);
        int p1=l, p2=m+1, p=0, less=0;
        while (p1 <= m && p2 <= r) {
            if (nums[p1].first <= nums[p2].first) {
                count[nums[p1].second]+=less;
                tmp[p++]=nums[p1++];
            } else {
                tmp[p++]=nums[p2++];
                less++;
            }
        }
        while (p1 <= m) {
            count[nums[p1].second]+=less;
            tmp[p++] = nums[p1++];
        }
        while (p2 <= r) {
            tmp[p++] = nums[p2++];
        }
        for (int i = 0; i < r-l+1; i++)
            nums[l+i]=tmp[i];
    }
    
    
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<pair<int,int>> vals;
        for (int i = 0; i < nums.size(); i++)
            vals.push_back({nums[i],i});
        vector<int> count(nums.size());
        sort(vals, count, 0, nums.size()-1);
        return count;
    }
};
