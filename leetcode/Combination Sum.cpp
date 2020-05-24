class Solution {
public:
vector<vector<int>> ans;

void solve(vector<int>& c, vector<int> res, int p, int t) {
	if (t == 0) {
		ans.push_back(res);
		return;
	}
	for (int i = p; i >= 0; i--)
		if (c[i] <= t) {
			res.insert(res.begin(), c[i]);
			solve(c, res, i, t - c[i]);
			res.erase(res.begin());
		}
}
    
vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
	vector<int> res;
	solve(candidates, res, candidates.size()-1, target);
    return ans;
}
};
