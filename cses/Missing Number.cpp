#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin >> n;
	vector<bool> v(n,false);
	for (int i = 0; i < n-1; ++i) {
		int a;
		cin >> a;
		v[a-1] = true;
	}
	int ans;
	for (int i = 0; i < n; i++) {
		if (v[i]==false) {
			ans = i+1;
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
