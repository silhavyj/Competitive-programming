class Solution {
public:
    
    string getPermutation(int n, int k) {
    	vector<int> nums;
    	for (int i = 1; i <= n; i++)
    		nums.push_back(i);
    	int step = 0;
    	while (++step != k)
    		next_permutation(nums.begin(), nums.end());
		string ans = "";
		for (int x : nums)
			ans += to_string(x);
        return ans;
    }
};
