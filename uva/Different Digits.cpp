#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool ok(int x) {
	string s = to_string(x);
	unordered_set<char> m;
	for (char c : s) {
		if (m.find(c)!=m.end())
			return false;
		m.insert(c);
	}
	return true;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	while (cin >> n >> m) {
		int ans = 0;
		for (int i = n; i <= m; i++)
			ans += ok(i);
		cout << ans << "\n";
	}
	return 0;
}
