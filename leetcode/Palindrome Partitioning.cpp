class Solution {
public:
vector<string> sol;
vector<vector<string>> res;

bool isPalindrome(string &s, int low, int high) {
	while (low < high) {
		if (s[low] != s[high])
			return false;
		low++; high--;
	}
	return true;
}

void solve(string &s, int p) {
	if (p >= s.length()) {
		res.push_back(sol);
		return;
	}
	for (int i = 1; p+i <= s.length(); i++) {
		if (isPalindrome(s, p, p+i-1)) {
			string str = s.substr(p,i);
			sol.push_back(str);
			solve(s, p+i);
			sol.pop_back();
		}
	}
}

vector<vector<string>> partition(string s) {
	solve(s, 0);
	return res;
}

};
