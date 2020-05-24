class Solution {
public:
    
    vector<vector<int>> res;
    vector<bool> used;
    
    void perm(vector<int> p, vector<int>& nums, int index) {
        if (index == nums.size()) {
            res.push_back(p);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (used[i] == false) {
                used[i] = true;
                p[index] = nums[i];
                perm(p, nums, index + 1);
                used[i] = false;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> p;
        for (int i = 0; i < nums.size(); i++) {
        	used.push_back(false);
        	p.push_back(0);
		}
        perm(p, nums, 0);
        return res;
    }
};
