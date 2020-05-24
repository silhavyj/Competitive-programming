#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin >> t;
	while (t--) {
		int n, m = 1e4, d;
		vector<int> ans;
		cin >> n;
		while (n) {
			d = n/m;
			if (d != 0) {
				n -= d*m;
				ans.push_back(d*m);
			}
			m/=10;
		}
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i];
			if (i != ans.size()-1)
				cout << " ";
		}
		cout << "\n";
	}

	return 0;
}
