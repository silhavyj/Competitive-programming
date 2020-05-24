class Solution {
public:
    
vector<vector<int>> ans;
unordered_set<int> visited;

int getHash(vector<int> &v) {
	int res = 31;
	for (int x : v)
		res = 17 * res + x;
	return res;
}
    
void solve(vector<int>& c, vector<int> res, int p, int t) {
	if (t == 0) {
		int h = getHash(res);
		if (visited.find(h) != visited.end())
			return;
		visited.insert(h);
		ans.push_back(res);
		return;
	}
	for (int i = p; i >= 0; i--)
		if (c[i] <= t) {
			res.insert(res.begin(), c[i]);
			solve(c, res, i-1, t - c[i]);
			res.erase(res.begin());
		}
}
    
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    sort(candidates.begin(), candidates.end());
	vector<int> res;
	solve(candidates, res, candidates.size()-1, target);
    return ans;
}
};
