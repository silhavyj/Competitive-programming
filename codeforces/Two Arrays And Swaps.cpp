#include <bits/stdc++.h>
#define ll long long
using namespace std;

void solve() {
	int n,k,ans=0;
	cin >> n >> k;
	int a[n], b[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans += a[i];
	}
	for (int i = 0; i < n; i++)
		cin >> b[i];
	sort(a,a+n);
	sort(b,b+n,greater<>());
	for (int i = 0; i < k; i++) {
		if (a[i]>=b[i])
			break;
		ans -= a[i];
		ans += b[i];
	}
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
			
	int t;
	cin >> t;
	while (t--)
		solve();
	return 0;
}
