class Solution {
public:
    vector<vector<int>> res;
    vector<bool> used;
    unordered_set<long long> visited;
    
    long long getHash(vector<int> &v) {
    	long long res = 31;
    	for (int x : v)
    		res = 17 * res + x;
    	return res;
	}
    
    void perm(vector<int> p, vector<int>& nums, int index) {
        if (index == nums.size()) {
        	long long h = getHash(p);
        	if (visited.find(h) == visited.end()) {
            	res.push_back(p);
            	visited.insert(h);          	
            	return;
            }
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
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> p;
        for (int i = 0; i < nums.size(); i++) {
        	used.push_back(false);
        	p.push_back(0);
		}
        perm(p, nums, 0);
        return res;
    }
};
