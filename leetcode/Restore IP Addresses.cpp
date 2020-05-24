class Solution {
public:
vector<string> res;

void solve(vector<long long> &ip, int dot, string &s, int p) {
	if (p > s.length() || dot == 5)
		return;
		
	if (p == s.length()) {
		if (dot != 4)
			return;
		string ans = "";
		for (int i = 0; i < ip.size(); i++) {
			ans += to_string(ip[i]);
			if (i != ip.size() - 1)
				ans += ".";
		}
		if (ans.length() == s.length() + 3)
			res.push_back(ans);
		return;
	}		
	for (int i = 1; i <= 4; i++) {
		string num_s = s.substr(p,i);
		long long num = stoll(num_s);
		if (num < 0 || num > 255)
			continue;
			
		ip.push_back(num);
		solve(ip, dot+1, s, p+i);
		ip.pop_back();
	}
}

vector<string> restoreIpAddresses(string s) {
	vector<long long> ip;
	solve(ip, 0, s, 0);
	return res;
}

};
